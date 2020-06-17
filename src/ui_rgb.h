/********************************************************************************
** Form generated from reading UI file 'rgb.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RGB_H
#define UI_RGB_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RGB
{
public:
    QLabel *label_img_rgb;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QSlider *R_Slider;
    QLCDNumber *lcdNumber_B;
    QLCDNumber *lcdNumber_G;
    QSlider *B_Slider;
    QSlider *G_Slider;
    QLCDNumber *lcdNumber_R;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QPushButton *pushButton_apply;

    void setupUi(QDialog *RGB)
    {
        if (RGB->objectName().isEmpty())
            RGB->setObjectName(QString::fromUtf8("RGB"));
        RGB->resize(673, 554);
        label_img_rgb = new QLabel(RGB);
        label_img_rgb->setObjectName(QString::fromUtf8("label_img_rgb"));
        label_img_rgb->setGeometry(QRect(70, 20, 521, 391));
        gridLayoutWidget = new QWidget(RGB);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(90, 410, 261, 131));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        R_Slider = new QSlider(gridLayoutWidget);
        R_Slider->setObjectName(QString::fromUtf8("R_Slider"));
        R_Slider->setMinimum(-100);
        R_Slider->setMaximum(100);
        R_Slider->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(R_Slider, 0, 0, 1, 1);

        lcdNumber_B = new QLCDNumber(gridLayoutWidget);
        lcdNumber_B->setObjectName(QString::fromUtf8("lcdNumber_B"));

        gridLayout->addWidget(lcdNumber_B, 2, 2, 1, 1);

        lcdNumber_G = new QLCDNumber(gridLayoutWidget);
        lcdNumber_G->setObjectName(QString::fromUtf8("lcdNumber_G"));

        gridLayout->addWidget(lcdNumber_G, 1, 2, 1, 1);

        B_Slider = new QSlider(gridLayoutWidget);
        B_Slider->setObjectName(QString::fromUtf8("B_Slider"));
        B_Slider->setMinimum(-100);
        B_Slider->setMaximum(100);
        B_Slider->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(B_Slider, 2, 0, 1, 1);

        G_Slider = new QSlider(gridLayoutWidget);
        G_Slider->setObjectName(QString::fromUtf8("G_Slider"));
        G_Slider->setMinimum(-100);
        G_Slider->setMaximum(100);
        G_Slider->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(G_Slider, 1, 0, 1, 1);

        lcdNumber_R = new QLCDNumber(gridLayoutWidget);
        lcdNumber_R->setObjectName(QString::fromUtf8("lcdNumber_R"));

        gridLayout->addWidget(lcdNumber_R, 0, 2, 1, 1);

        label_2 = new QLabel(gridLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 0, 1, 1, 1);

        label_3 = new QLabel(gridLayoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 1, 1, 1, 1);

        label_4 = new QLabel(gridLayoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 2, 1, 1, 1);

        pushButton_apply = new QPushButton(RGB);
        pushButton_apply->setObjectName(QString::fromUtf8("pushButton_apply"));
        pushButton_apply->setGeometry(QRect(480, 490, 112, 32));

        retranslateUi(RGB);

        QMetaObject::connectSlotsByName(RGB);
    } // setupUi

    void retranslateUi(QDialog *RGB)
    {
        RGB->setWindowTitle(QCoreApplication::translate("RGB", "Dialog", nullptr));
        label_img_rgb->setText(QString());
        label_2->setText(QCoreApplication::translate("RGB", "R", nullptr));
        label_3->setText(QCoreApplication::translate("RGB", "G", nullptr));
        label_4->setText(QCoreApplication::translate("RGB", "B", nullptr));
        pushButton_apply->setText(QCoreApplication::translate("RGB", "Apply", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RGB: public Ui_RGB {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RGB_H
