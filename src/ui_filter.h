/********************************************************************************
** Form generated from reading UI file 'filter.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FILTER_H
#define UI_FILTER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Filter
{
public:
    QLabel *label_img_filter;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QRadioButton *radioButton_box;
    QRadioButton *radioButton_Gauss;
    QRadioButton *radioButton_Median;
    QRadioButton *radioButton_bilateral;
    QRadioButton *radioButton_sharpening;
    QSlider *w_Slider;
    QSlider *h_Slider;
    QSlider *k_Slider;
    QLCDNumber *lcdNumber_w;
    QLCDNumber *lcdNumber_h;
    QLCDNumber *lcdNumber_k;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QPushButton *pushButton_apply;

    void setupUi(QDialog *Filter)
    {
        if (Filter->objectName().isEmpty())
            Filter->setObjectName(QString::fromUtf8("Filter"));
        Filter->resize(727, 604);
        label_img_filter = new QLabel(Filter);
        label_img_filter->setObjectName(QString::fromUtf8("label_img_filter"));
        label_img_filter->setGeometry(QRect(40, 20, 651, 401));
        verticalLayoutWidget = new QWidget(Filter);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(50, 460, 191, 121));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        radioButton_box = new QRadioButton(verticalLayoutWidget);
        radioButton_box->setObjectName(QString::fromUtf8("radioButton_box"));

        verticalLayout->addWidget(radioButton_box);

        radioButton_Gauss = new QRadioButton(verticalLayoutWidget);
        radioButton_Gauss->setObjectName(QString::fromUtf8("radioButton_Gauss"));

        verticalLayout->addWidget(radioButton_Gauss);

        radioButton_Median = new QRadioButton(verticalLayoutWidget);
        radioButton_Median->setObjectName(QString::fromUtf8("radioButton_Median"));

        verticalLayout->addWidget(radioButton_Median);

        radioButton_bilateral = new QRadioButton(verticalLayoutWidget);
        radioButton_bilateral->setObjectName(QString::fromUtf8("radioButton_bilateral"));

        verticalLayout->addWidget(radioButton_bilateral);

        radioButton_sharpening = new QRadioButton(verticalLayoutWidget);
        radioButton_sharpening->setObjectName(QString::fromUtf8("radioButton_sharpening"));

        verticalLayout->addWidget(radioButton_sharpening);

        w_Slider = new QSlider(Filter);
        w_Slider->setObjectName(QString::fromUtf8("w_Slider"));
        w_Slider->setGeometry(QRect(220, 490, 91, 22));
        w_Slider->setMaximum(49);
        w_Slider->setOrientation(Qt::Horizontal);
        h_Slider = new QSlider(Filter);
        h_Slider->setObjectName(QString::fromUtf8("h_Slider"));
        h_Slider->setGeometry(QRect(400, 490, 91, 22));
        h_Slider->setMaximum(49);
        h_Slider->setOrientation(Qt::Horizontal);
        k_Slider = new QSlider(Filter);
        k_Slider->setObjectName(QString::fromUtf8("k_Slider"));
        k_Slider->setGeometry(QRect(280, 550, 160, 22));
        k_Slider->setMaximum(49);
        k_Slider->setOrientation(Qt::Horizontal);
        lcdNumber_w = new QLCDNumber(Filter);
        lcdNumber_w->setObjectName(QString::fromUtf8("lcdNumber_w"));
        lcdNumber_w->setGeometry(QRect(320, 490, 64, 23));
        lcdNumber_h = new QLCDNumber(Filter);
        lcdNumber_h->setObjectName(QString::fromUtf8("lcdNumber_h"));
        lcdNumber_h->setGeometry(QRect(500, 490, 64, 23));
        lcdNumber_k = new QLCDNumber(Filter);
        lcdNumber_k->setObjectName(QString::fromUtf8("lcdNumber_k"));
        lcdNumber_k->setGeometry(QRect(450, 550, 64, 23));
        label_2 = new QLabel(Filter);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(350, 470, 58, 16));
        label_3 = new QLabel(Filter);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(530, 470, 58, 16));
        label_4 = new QLabel(Filter);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(480, 530, 58, 16));
        pushButton_apply = new QPushButton(Filter);
        pushButton_apply->setObjectName(QString::fromUtf8("pushButton_apply"));
        pushButton_apply->setGeometry(QRect(590, 510, 112, 32));

        retranslateUi(Filter);

        QMetaObject::connectSlotsByName(Filter);
    } // setupUi

    void retranslateUi(QDialog *Filter)
    {
        Filter->setWindowTitle(QCoreApplication::translate("Filter", "Dialog", nullptr));
        label_img_filter->setText(QString());
        radioButton_box->setText(QCoreApplication::translate("Filter", "Box filter(w,h)", nullptr));
        radioButton_Gauss->setText(QCoreApplication::translate("Filter", "Gaussian filter(w,h)", nullptr));
        radioButton_Median->setText(QCoreApplication::translate("Filter", "Median filter(k)", nullptr));
        radioButton_bilateral->setText(QCoreApplication::translate("Filter", "Bilateral filter(k)", nullptr));
        radioButton_sharpening->setText(QCoreApplication::translate("Filter", "Image sharpening(3,3)", nullptr));
        label_2->setText(QCoreApplication::translate("Filter", "w", nullptr));
        label_3->setText(QCoreApplication::translate("Filter", "h", nullptr));
        label_4->setText(QCoreApplication::translate("Filter", "k", nullptr));
        pushButton_apply->setText(QCoreApplication::translate("Filter", "Apply", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Filter: public Ui_Filter {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FILTER_H
