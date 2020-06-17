/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionLoad;
    QAction *actionSave;
    QWidget *centralWidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton_grabcut;
    QPushButton *pushButton_cropping;
    QSpacerItem *verticalSpacer_2;
    QPushButton *pushButton_undo;
    QPushButton *pushButton_reset;
    QLabel *label_img;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_3;
    QPushButton *pushButton_brightness;
    QPushButton *pushButton_saturation;
    QPushButton *pushButton_hue;
    QPushButton *pushButton_RGB;
    QSpacerItem *verticalSpacer;
    QPushButton *pushButton_filter;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1248, 829);
        actionLoad = new QAction(MainWindow);
        actionLoad->setObjectName(QString::fromUtf8("actionLoad"));
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QString::fromUtf8("actionSave"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayoutWidget = new QWidget(centralWidget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(9, 9, 112, 421));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_grabcut = new QPushButton(verticalLayoutWidget);
        pushButton_grabcut->setObjectName(QString::fromUtf8("pushButton_grabcut"));

        verticalLayout->addWidget(pushButton_grabcut);

        pushButton_cropping = new QPushButton(verticalLayoutWidget);
        pushButton_cropping->setObjectName(QString::fromUtf8("pushButton_cropping"));

        verticalLayout->addWidget(pushButton_cropping);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        pushButton_undo = new QPushButton(verticalLayoutWidget);
        pushButton_undo->setObjectName(QString::fromUtf8("pushButton_undo"));

        verticalLayout->addWidget(pushButton_undo);

        pushButton_reset = new QPushButton(verticalLayoutWidget);
        pushButton_reset->setObjectName(QString::fromUtf8("pushButton_reset"));

        verticalLayout->addWidget(pushButton_reset);

        label_img = new QLabel(centralWidget);
        label_img->setObjectName(QString::fromUtf8("label_img"));
        label_img->setGeometry(QRect(130, 10, 731, 611));
        verticalLayoutWidget_2 = new QWidget(centralWidget);
        verticalLayoutWidget_2->setObjectName(QString::fromUtf8("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(880, 10, 128, 321));
        verticalLayout_3 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        pushButton_brightness = new QPushButton(verticalLayoutWidget_2);
        pushButton_brightness->setObjectName(QString::fromUtf8("pushButton_brightness"));

        verticalLayout_3->addWidget(pushButton_brightness);

        pushButton_saturation = new QPushButton(verticalLayoutWidget_2);
        pushButton_saturation->setObjectName(QString::fromUtf8("pushButton_saturation"));

        verticalLayout_3->addWidget(pushButton_saturation);

        pushButton_hue = new QPushButton(verticalLayoutWidget_2);
        pushButton_hue->setObjectName(QString::fromUtf8("pushButton_hue"));

        verticalLayout_3->addWidget(pushButton_hue);

        pushButton_RGB = new QPushButton(verticalLayoutWidget_2);
        pushButton_RGB->setObjectName(QString::fromUtf8("pushButton_RGB"));

        verticalLayout_3->addWidget(pushButton_RGB);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Preferred);

        verticalLayout_3->addItem(verticalSpacer);

        pushButton_filter = new QPushButton(verticalLayoutWidget_2);
        pushButton_filter->setObjectName(QString::fromUtf8("pushButton_filter"));

        verticalLayout_3->addWidget(pushButton_filter);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1248, 22));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuFile->addAction(actionLoad);
        menuFile->addAction(actionSave);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionLoad->setText(QCoreApplication::translate("MainWindow", "Load", nullptr));
        actionSave->setText(QCoreApplication::translate("MainWindow", "Save", nullptr));
        pushButton_grabcut->setText(QCoreApplication::translate("MainWindow", "Grabcut", nullptr));
        pushButton_cropping->setText(QCoreApplication::translate("MainWindow", "Cropping", nullptr));
        pushButton_undo->setText(QCoreApplication::translate("MainWindow", "Undo", nullptr));
        pushButton_reset->setText(QCoreApplication::translate("MainWindow", "Reset", nullptr));
        label_img->setText(QString());
        pushButton_brightness->setText(QCoreApplication::translate("MainWindow", "Brightness", nullptr));
        pushButton_saturation->setText(QCoreApplication::translate("MainWindow", "Saturation", nullptr));
        pushButton_hue->setText(QCoreApplication::translate("MainWindow", "Hue", nullptr));
        pushButton_RGB->setText(QCoreApplication::translate("MainWindow", "RGB", nullptr));
        pushButton_filter->setText(QCoreApplication::translate("MainWindow", "Filter", nullptr));
        menuFile->setTitle(QCoreApplication::translate("MainWindow", "File", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
