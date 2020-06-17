/********************************************************************************
** Form generated from reading UI file 'brightness.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BRIGHTNESS_H
#define UI_BRIGHTNESS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>

QT_BEGIN_NAMESPACE

class Ui_Brightness
{
public:
    QSlider *brightnessSlider;
    QLCDNumber *lcd_brightness;
    QPushButton *pushButton_apply;
    QLabel *label_img_brightness;

    void setupUi(QDialog *Brightness)
    {
        if (Brightness->objectName().isEmpty())
            Brightness->setObjectName(QString::fromUtf8("Brightness"));
        Brightness->resize(551, 432);
        brightnessSlider = new QSlider(Brightness);
        brightnessSlider->setObjectName(QString::fromUtf8("brightnessSlider"));
        brightnessSlider->setGeometry(QRect(30, 400, 160, 22));
        brightnessSlider->setMinimum(-150);
        brightnessSlider->setMaximum(150);
        brightnessSlider->setOrientation(Qt::Horizontal);
        lcd_brightness = new QLCDNumber(Brightness);
        lcd_brightness->setObjectName(QString::fromUtf8("lcd_brightness"));
        lcd_brightness->setGeometry(QRect(200, 400, 64, 23));
        pushButton_apply = new QPushButton(Brightness);
        pushButton_apply->setObjectName(QString::fromUtf8("pushButton_apply"));
        pushButton_apply->setGeometry(QRect(480, 390, 61, 31));
        pushButton_apply->setAutoDefault(false);
        label_img_brightness = new QLabel(Brightness);
        label_img_brightness->setObjectName(QString::fromUtf8("label_img_brightness"));
        label_img_brightness->setGeometry(QRect(37, 15, 481, 351));

        retranslateUi(Brightness);

        QMetaObject::connectSlotsByName(Brightness);
    } // setupUi

    void retranslateUi(QDialog *Brightness)
    {
        Brightness->setWindowTitle(QCoreApplication::translate("Brightness", "Dialog", nullptr));
        pushButton_apply->setText(QCoreApplication::translate("Brightness", "Apply", nullptr));
        label_img_brightness->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Brightness: public Ui_Brightness {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BRIGHTNESS_H
