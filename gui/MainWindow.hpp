//
// Created by Priyanshu Singh on 03/12/15.
//

#ifndef COLORIT_MAINWINDOW_HPP
#define COLORIT_MAINWINDOW_HPP

#include <QMainWindow>
#include <color_proc/ColorBlender.hpp>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QColor pencilColor;
    QColor bgColor;
    ColorBlender colorBlender;
    QString getStylesheetBgColor(QColor color);

private slots:
    void open();
    void setPencilColor();
    void setBgColor();
    void setRasterColor(bool isPencilColor);
    void setRasterThickness(int);
    void colorImage();
    void handle(bool isBG);
    void saveAs();
};

#endif //COLORIT_MAINWINDOW_HPP
