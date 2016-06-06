//
// Created by Priyanshu Singh on 03/12/15.
//

#include <qstandardpaths.h>
#include <iostream>
#include <qfiledialog.h>
#include "MainWindow.hpp"
#include "ui_mainwindow.hpp"
#include <opencv2/highgui/highgui.hpp>
#include <qcolordialog.h>

MainWindow::MainWindow(QWidget *parent) :
        QMainWindow(parent),pencilColor(QColor(0,0,0)),bgColor(QColor(0,0,0)),
        ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // setting properties of gui
    ui->openAction->setShortcut(QKeySequence::Open);
    ui->saveAsAction->setShortcut(QKeySequence::SaveAs);
    ui->pencilColorLabel->setStyleSheet(getStylesheetBgColor(QColor(0, 0, 0)));
    ui->bgColorLabel->setStyleSheet(getStylesheetBgColor(QColor(0, 0, 0)));

    // connect ui elements to slots
    connect(ui->openAction, SIGNAL(triggered(bool)), this, SLOT(open()));
    connect(ui->bgColorPushButton, SIGNAL(clicked(bool)), this, SLOT(setBgColor()));
    connect(ui->pencilColorPushButton, SIGNAL(clicked(bool)), this, SLOT(setPencilColor()));
    connect(ui->thicknessSpinBox, SIGNAL(valueChanged(int)), this, SLOT(setRasterThickness(int)));
    connect(ui->isPencilCheckBox, SIGNAL(clicked(bool)), this, SLOT(setRasterColor(bool)));
    connect(ui->colorizePushButton, SIGNAL(clicked(bool)), this, SLOT(colorImage()));
    connect(ui->bgCheckBox, SIGNAL(clicked(bool)), this, SLOT(handle(bool)));
    connect(ui->saveAsAction, SIGNAL(triggered(bool)), this, SLOT(saveAs()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::open() {
    QString desktopPath = QStandardPaths::locate(QStandardPaths::DesktopLocation,
                                                 QString(), QStandardPaths::LocateDirectory);

    QString filePath = QFileDialog::getOpenFileName(this, QString("Open Image"), desktopPath);
    if(!filePath.isEmpty()){
        string path = filePath.toUtf8().constData();
        Mat image = cv::imread(path);
        ui->rasterLabel->setOriginalImage(image);
    }
}

QString MainWindow::getStylesheetBgColor(QColor color) {
    QString stylesheeet = "background-color: rgb(";
    stylesheeet += QString::number(color.red()) + QString(",");
    stylesheeet += QString::number(color.green()) + QString(",");
    stylesheeet += QString::number(color.blue()) + QString(",");
    stylesheeet += QString(");");
    return stylesheeet;
}

void MainWindow::setPencilColor() {
    QColor color = QColorDialog::getColor(pencilColor, this, QString("Pencil Color"));
    pencilColor = color;
    ui->pencilColorLabel->setStyleSheet(getStylesheetBgColor(pencilColor));
    setRasterColor(ui->isPencilCheckBox->isChecked());
}

void MainWindow::setBgColor() {
    QColor color = QColorDialog::getColor(bgColor, this, QString("Pencil Color"));
    bgColor = color;
    ui->bgColorLabel->setStyleSheet(getStylesheetBgColor(bgColor));
    setRasterColor(ui->isPencilCheckBox->isChecked());
}

void MainWindow::setRasterColor(bool isPencilColor) {
    ui->rasterLabel->setLineColor((isPencilColor)?pencilColor:bgColor);
}

void MainWindow::setRasterThickness(int i) {
    ui->rasterLabel->setThickness(i);
}

void MainWindow::colorImage() {
    if(ui->rasterLabel->getOriginalImage().empty())return;
    bool isBg = ui->bgCheckBox->isChecked();
    Mat originalImage = ui->rasterLabel->getOriginalImage();
    Mat layeredImage = ui->rasterLabel->getLayeredImage();
    Vec3b color;
    color[0] = (uchar) bgColor.red();
    color[1] = (uchar) bgColor.green();
    color[2] = (uchar) bgColor.blue();

    Mat *output;
    if(!isBg){
//        output = colorBlender.colorize(&originalImage, &layeredImage);
    }else{
        output = colorBlender.colorize(&originalImage, &layeredImage,
                                    color);
    }
    originalImage = output->clone();
    layeredImage = originalImage.clone();

    ui->rasterLabel->setOriginalImage(originalImage);
    delete output;
}

void MainWindow::handle(bool isBG) {
    if(isBG){
        if(ui->isPencilCheckBox->isChecked()){
            ui->pencilColorPushButton->setEnabled(true);
            ui->bgColorPushButton->setEnabled(false);
        }else{
            ui->pencilColorPushButton->setEnabled(false);
            ui->bgColorPushButton->setEnabled(true);
        }
    }
    setPencilColor();
    setBgColor();
}

void MainWindow::saveAs() {
    QString desktopPath = QStandardPaths::locate(QStandardPaths::DesktopLocation,
                                                 QString(), QStandardPaths::LocateDirectory);

    QString filePath = QFileDialog::getSaveFileName(this, QString("Save Image"), desktopPath);
    if(!filePath.isEmpty()){
        string path = filePath.toUtf8().constData();
        if(ui->rasterLabel->getLayeredImage().empty()){
            cerr<<"Image not loaded\n";
            return;
        }
        cv::imwrite(path,ui->rasterLabel->getLayeredImage());
    }
}
