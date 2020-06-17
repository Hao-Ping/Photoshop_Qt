/********************************************************************************
** Form generated from reading UI file 'hue.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HUE_H
#define UI_HUE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>

QT_BEGIN_NAMESPACE

class Ui_hue
{
public:
    QSlider *hueSlider;
    QLabel *label_img_hue;
    QLCDNumber *lcdHue;
    QPushButton *pushButton;

    void setupUi(QDialog *hue)
    {
        if (hue->objectName().isEmpty())
            hue->setObjectName(QString::fromUtf8("hue"));
        hue->resize(400, 300);
        hueSlider = new QSlider(hue);
        hueSlider->setObjectName(QString::fromUtf8("hueSlider"));
        hueSlider->setGeometry(QRect(30, 250, 160, 22));
        hueSlider->setMinimum(-200);
        hueSlider->setMaximum(200);
        hueSlider->setOrientation(Qt::Horizontal);
        label_img_hue = new QLabel(hue);
        label_img_hue->setObjectName(QString::fromUtf8("label_img_hue"));
        label_img_hue->setGeometry(QRect(27, 25, 331, 171));
        lcdHue = new QLCDNumber(hue);
        lcdHue->setObjectName(QString::fromUtf8("lcdHue"));
        lcdHue->setGeometry(QRect(200, 250, 64, 23));
        pushButton = new QPushButton(hue);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(280, 250, 112, 32));

        retranslateUi(hue);

        QMetaObject::connectSlotsByName(hue);
    } // setupUi

    void retranslateUi(QDialog *hue)
    {
        hue->setWindowTitle(QCoreApplication::translate("hue", "Dialog", nullptr));
        label_img_hue->setText(QString());
        pushButton->setText(QCoreApplication::translate("hue", "Apply", nullptr));
    } // retranslateUi

};

namespace Ui {
    class hue: public Ui_hue {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HUE_H
