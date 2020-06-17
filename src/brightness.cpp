#include "brightness.h"
#include "ui_brightness.h"
#include "mainwindow.h"

//extern int globaldata;
extern cv::Mat img;
cv::Mat img_brightness;

extern std::vector<cv::Mat> history;
extern int historyNum;

Brightness::Brightness(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Brightness)
{
    ui->setupUi(this);
    ui->label_img_brightness->clear();
    ui->label_img_brightness->setPixmap(QPixmap::fromImage(cvMat2QImage(img).scaled(ui->label_img_brightness->width(),ui->label_img_brightness->height(),Qt::KeepAspectRatio)));
}

Brightness::~Brightness()
{
    delete ui;
}

void Brightness::on_brightnessSlider_valueChanged(int value)
{
    ui->lcd_brightness->display(value);
//    qDebug() << globaldata;
    img_brightness = img.clone();
    cv::cvtColor(img_brightness, img_brightness, cv::COLOR_BGR2HSV);
    for (int i = 0; i <= img_brightness.cols; i++) {
        for (int j = 0; j <= img_brightness.rows; j++) {
            int hue = img_brightness.at<cv::Vec3b>(i,j)[2];
            if(hue + value >255){
                img_brightness.at<cv::Vec3b>(i,j)[2]=255;
            }
            else if (hue + value <0) {
                img_brightness.at<cv::Vec3b>(i,j)[2]=0;
            }
            else {
                img_brightness.at<cv::Vec3b>(i,j)[2]=hue +value;
            }
        }
    }
    cv::cvtColor(img_brightness, img_brightness, cv::COLOR_HSV2BGR);
    ui->label_img_brightness->setPixmap(QPixmap::fromImage(cvMat2QImage(img_brightness).scaled(ui->label_img_brightness->width(),ui->label_img_brightness->height(),Qt::KeepAspectRatio)));

}

void Brightness::on_pushButton_apply_clicked()
{
    img = img_brightness;
    accept();

    history.push_back(img.clone()); //by flappy
    historyNum++;
}
