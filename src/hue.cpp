#include "hue.h"
#include "ui_hue.h"
#include "mainwindow.h"

extern cv::Mat img;
cv::Mat img_hue;

extern std::vector<cv::Mat> history;
extern int historyNum;

hue::hue(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::hue)
{
    ui->setupUi(this);
    ui->label_img_hue->clear();
    ui->label_img_hue->setPixmap(QPixmap::fromImage(cvMat2QImage(img).scaled(ui->label_img_hue->width(),ui->label_img_hue->height(),Qt::KeepAspectRatio)));
}

hue::~hue()
{
    delete ui;
}
void hue::on_hueSlider_valueChanged(int value)
{
    ui->lcdHue->display(value);

    img_hue=img.clone();
    cv::cvtColor(img_hue, img_hue, cv::COLOR_BGR2HSV); //BGR to HSV
    for (int i = 0; i <= img_hue.cols; i++) {
        for (int j = 0; j <= img_hue.rows; j++) {
            int hue = img_hue.at<cv::Vec3b>(i,j)[0];
            if(hue + value >360){
                img_hue.at<cv::Vec3b>(i,j)[0]=0;
            }
            else if (hue + value <0) {
                img_hue.at<cv::Vec3b>(i,j)[0]=360;
            }
            else {
                img_hue.at<cv::Vec3b>(i,j)[0]=hue +value;
            }
        }
    }
    cv::cvtColor(img_hue, img_hue, cv::COLOR_HSV2BGR); //before display the image change HSV back to BGR
    ui->label_img_hue->setPixmap(QPixmap::fromImage(cvMat2QImage(img_hue).scaled(ui->label_img_hue->width(),ui->label_img_hue->height(),Qt::KeepAspectRatio)));
}

void hue::on_pushButton_clicked()
{
    img = img_hue;
    accept();
    history.push_back(img.clone()); //by flappy
    historyNum++;
}
