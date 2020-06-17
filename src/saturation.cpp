#include "saturation.h"
#include "ui_saturation.h"
#include "mainwindow.h"


extern cv::Mat img;
cv::Mat img_saturation;

extern std::vector<cv::Mat> history;
extern int historyNum;

Saturation::Saturation(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Saturation)
{
    ui->setupUi(this);

    ui->label_img_saturation->clear();
    ui->label_img_saturation->setPixmap(QPixmap::fromImage(cvMat2QImage(img).scaled(ui->label_img_saturation->width(),ui->label_img_saturation->height(),Qt::KeepAspectRatio)));
}

Saturation::~Saturation()
{
    delete ui;
}

void Saturation::on_saturationSlider_valueChanged(int value)
{
    ui->lcd_saturation->display(value);

    img_saturation=img.clone();
    cv::cvtColor(img_saturation, img_saturation, cv::COLOR_BGR2HSV);
    for (int i = 0; i <= img_saturation.cols; i++) {
        for (int j = 0; j <= img_saturation.rows; j++) {
            int hue = img_saturation.at<cv::Vec3b>(i,j)[1];
            if(hue + value >255){
                img_saturation.at<cv::Vec3b>(i,j)[1]=255;
            }
            else if (hue + value <0) {
                img_saturation.at<cv::Vec3b>(i,j)[1]=0;
            }
            else {
                img_saturation.at<cv::Vec3b>(i,j)[1]=hue +value;
            }
        }
    }
    cv::cvtColor(img_saturation, img_saturation, cv::COLOR_HSV2BGR);
    ui->label_img_saturation->setPixmap(QPixmap::fromImage(cvMat2QImage(img_saturation).scaled(ui->label_img_saturation->width(),ui->label_img_saturation->height(),Qt::KeepAspectRatio)));
}

void Saturation::on_pushButton_apply_clicked()
{
    img = img_saturation;
    accept();

    history.push_back(img.clone()); //by flappy
    historyNum++;
}
