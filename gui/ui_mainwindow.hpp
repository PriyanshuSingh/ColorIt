//
// Created by Priyanshu Singh on 03/12/15.
//

#ifndef COLORIT_UI_MAINWINDOW_HPP
#define COLORIT_UI_MAINWINDOW_HPP


#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>
#include "RasterLabel.hpp"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *openAction;
    QAction *saveAsAction;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    RasterLabel *rasterLabel;
    QFrame *line;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QLabel *label_5;
    QSpinBox *thicknessSpinBox;
    QPushButton *colorizePushButton;
    QCheckBox *bgCheckBox;
    QLabel *pencilColorLabel;
    QPushButton *bgColorPushButton;
    QLabel *bgColorLabel;
    QSpacerItem *verticalSpacer;
    QPushButton *pencilColorPushButton;
    QFrame *line_2;
    QFrame *line_3;
    QCheckBox *isPencilCheckBox;
    QMenuBar *menuBar;
    QMenu *menu_File;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(397, 393);
        openAction = new QAction(MainWindow);
        openAction->setObjectName(QStringLiteral("openAction"));
        saveAsAction = new QAction(MainWindow);
        saveAsAction->setObjectName(QStringLiteral("saveAsAction"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        rasterLabel = new RasterLabel(centralWidget);
        rasterLabel->setObjectName(QStringLiteral("rasterLabel"));
        rasterLabel->setAutoFillBackground(true);

        horizontalLayout->addWidget(rasterLabel);

        line = new QFrame(centralWidget);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        horizontalLayout->addWidget(line);

        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout->addWidget(label_5, 1, 0, 1, 1);

        thicknessSpinBox = new QSpinBox(groupBox);
        thicknessSpinBox->setObjectName(QStringLiteral("thicknessSpinBox"));
        thicknessSpinBox->setMinimum(1);

        gridLayout->addWidget(thicknessSpinBox, 1, 1, 1, 1);

        colorizePushButton = new QPushButton(groupBox);
        colorizePushButton->setObjectName(QStringLiteral("colorizePushButton"));

        gridLayout->addWidget(colorizePushButton, 12, 0, 1, 2);

        bgCheckBox = new QCheckBox(groupBox);
        bgCheckBox->setObjectName(QStringLiteral("bgCheckBox"));
        bgCheckBox->setChecked(true);

        gridLayout->addWidget(bgCheckBox, 0, 0, 1, 2);

        pencilColorLabel = new QLabel(groupBox);
        pencilColorLabel->setObjectName(QStringLiteral("pencilColorLabel"));
        pencilColorLabel->setAutoFillBackground(true);

        gridLayout->addWidget(pencilColorLabel, 3, 0, 1, 1);

        bgColorPushButton = new QPushButton(groupBox);
        bgColorPushButton->setObjectName(QStringLiteral("bgColorPushButton"));
        bgColorPushButton->setEnabled(false);

        gridLayout->addWidget(bgColorPushButton, 7, 1, 1, 1);

        bgColorLabel = new QLabel(groupBox);
        bgColorLabel->setObjectName(QStringLiteral("bgColorLabel"));
        bgColorLabel->setAutoFillBackground(true);

        gridLayout->addWidget(bgColorLabel, 7, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 11, 0, 1, 1);

        pencilColorPushButton = new QPushButton(groupBox);
        pencilColorPushButton->setObjectName(QStringLiteral("pencilColorPushButton"));

        gridLayout->addWidget(pencilColorPushButton, 3, 1, 1, 1);

        line_2 = new QFrame(groupBox);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_2, 2, 0, 1, 2);

        line_3 = new QFrame(groupBox);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_3, 8, 0, 1, 2);

        isPencilCheckBox = new QCheckBox(groupBox);
        isPencilCheckBox->setObjectName(QStringLiteral("isPencilCheckBox"));
        isPencilCheckBox->setChecked(true);

        gridLayout->addWidget(isPencilCheckBox, 9, 0, 1, 2);


        horizontalLayout->addWidget(groupBox);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 397, 22));
        menu_File = new QMenu(menuBar);
        menu_File->setObjectName(QStringLiteral("menu_File"));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menu_File->menuAction());
        menu_File->addAction(openAction);
        menu_File->addAction(saveAsAction);

        retranslateUi(MainWindow);
        QObject::connect(bgCheckBox, SIGNAL(clicked(bool)), bgColorPushButton, SLOT(setEnabled(bool)));
        QObject::connect(bgCheckBox, SIGNAL(clicked(bool)), bgColorLabel, SLOT(setEnabled(bool)));
        QObject::connect(isPencilCheckBox, SIGNAL(clicked(bool)), bgColorPushButton, SLOT(setDisabled(bool)));
        QObject::connect(isPencilCheckBox, SIGNAL(clicked(bool)), pencilColorPushButton, SLOT(setEnabled(bool)));
        QObject::connect(bgCheckBox, SIGNAL(clicked(bool)), isPencilCheckBox, SLOT(setEnabled(bool)));
        QObject::connect(bgCheckBox, SIGNAL(clicked(bool)), bgColorPushButton, SLOT(setEnabled(bool)));
        QObject::connect(bgCheckBox, SIGNAL(clicked(bool)), pencilColorPushButton, SLOT(setDisabled(bool)));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        openAction->setText(QApplication::translate("MainWindow", "&open", 0));
        openAction->setShortcut(QApplication::translate("MainWindow", "Meta+O, Ctrl+O", 0));
        saveAsAction->setText(QApplication::translate("MainWindow", "&save as", 0));
        saveAsAction->setShortcut(QApplication::translate("MainWindow", "Ctrl+S, Meta+S", 0));
#ifndef QT_NO_STATUSTIP
        rasterLabel->setStatusTip(QApplication::translate("MainWindow", "Current loaded image", 0));
#endif // QT_NO_STATUSTIP
        rasterLabel->setText(QString());
        groupBox->setTitle(QApplication::translate("MainWindow", "Tools", 0));
        label_5->setText(QApplication::translate("MainWindow", "Thickness", 0));
#ifndef QT_NO_STATUSTIP
        thicknessSpinBox->setStatusTip(QApplication::translate("MainWindow", "Thickness of pencil", 0));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        thicknessSpinBox->setWhatsThis(QString());
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_STATUSTIP
        colorizePushButton->setStatusTip(QApplication::translate("MainWindow", "Colorize the image", 0));
#endif // QT_NO_STATUSTIP
        colorizePushButton->setText(QApplication::translate("MainWindow", "Colorize", 0));
#ifndef QT_NO_STATUSTIP
        bgCheckBox->setStatusTip(QApplication::translate("MainWindow", "Check the box to color specific objects", 0));
#endif // QT_NO_STATUSTIP
        bgCheckBox->setText(QApplication::translate("MainWindow", "color with background", 0));
#ifndef QT_NO_STATUSTIP
        pencilColorLabel->setStatusTip(QApplication::translate("MainWindow", "Current pencil color", 0));
#endif // QT_NO_STATUSTIP
        pencilColorLabel->setText(QString());
#ifndef QT_NO_STATUSTIP
        bgColorPushButton->setStatusTip(QApplication::translate("MainWindow", "Select color for the background pencil", 0));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        bgColorPushButton->setWhatsThis(QString());
#endif // QT_NO_WHATSTHIS
        bgColorPushButton->setText(QApplication::translate("MainWindow", "Background", 0));
#ifndef QT_NO_STATUSTIP
        bgColorLabel->setStatusTip(QApplication::translate("MainWindow", "Current background color", 0));
#endif // QT_NO_STATUSTIP
        bgColorLabel->setText(QString());
#ifndef QT_NO_STATUSTIP
        pencilColorPushButton->setStatusTip(QApplication::translate("MainWindow", "Select color for the pencil", 0));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        pencilColorPushButton->setWhatsThis(QString());
#endif // QT_NO_WHATSTHIS
        pencilColorPushButton->setText(QApplication::translate("MainWindow", "Pencil", 0));
#ifndef QT_NO_STATUSTIP
        isPencilCheckBox->setStatusTip(QApplication::translate("MainWindow", "toggle between pencil and background pencil", 0));
#endif // QT_NO_STATUSTIP
        isPencilCheckBox->setText(QApplication::translate("MainWindow", "pencil - 1 | bg - 0", 0));
        menu_File->setTitle(QApplication::translate("MainWindow", "&File", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif //COLORIT_UI_MAINWINDOW_HPP
