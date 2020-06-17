/********************************************************************************
** Form generated from reading UI file 'saturation.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SATURATION_H
#define UI_SATURATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>

QT_BEGIN_NAMESPACE

class Ui_Saturation
{
public:
    QLabel *label_img_saturation;
    QLCDNumber *lcd_saturation;
    QSlider *saturationSlider;
    QPushButton *pushButton_apply;

    void setupUi(QDialog *Saturation)
    {
        if (Saturation->objectName().isEmpty())
            Saturation->setObjectName(QString::fromUtf8("Saturation"));
        Saturation->resize(758, 568);
        label_img_saturation = new QLabel(Saturation);
        label_img_saturation->setObjectName(QString::fromUtf8("label_img_saturation"));
        label_img_saturation->setGeometry(QRect(37, 35, 641, 411));
        lcd_saturation = new QLCDNumber(Saturation);
        lcd_saturation->setObjectName(QString::fromUtf8("lcd_saturation"));
        lcd_saturation->setGeometry(QRect(340, 510, 64, 23));
        saturationSlider = new QSlider(Saturation);
        saturationSlider->setObjectName(QString::fromUtf8("saturationSlider"));
        saturationSlider->setGeometry(QRect(80, 510, 160, 22));
        saturationSlider->setMinimum(-100);
        saturationSlider->setMaximum(100);
        saturationSlider->setOrientation(Qt::Horizontal);
        pushButton_apply = new QPushButton(Saturation);
        pushButton_apply->setObjectName(QString::fromUtf8("pushButton_apply"));
        pushButton_apply->setGeometry(QRect(600, 510, 112, 32));

        retranslateUi(Saturation);

        QMetaObject::connectSlotsByName(Saturation);
    } // setupUi

    void retranslateUi(QDialog *Saturation)
    {
        Saturation->setWindowTitle(QCoreApplication::translate("Saturation", "Dialog", nullptr));
        label_img_saturation->setText(QString());
        pushButton_apply->setText(QCoreApplication::translate("Saturation", "Apply", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Saturation: public Ui_Saturation {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SATURATION_H
