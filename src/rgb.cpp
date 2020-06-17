#include "rgb.h"
#include "ui_rgb.h"

extern cv::Mat img;
cv::Mat img_rgb;

extern std::vector<cv::Mat> history;
extern int historyNum;

RGB::RGB(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RGB)
{
    ui->setupUi(this);

    ui->label_img_rgb->clear();
    img_rgb=img.clone();
//    int red = img_rgb.at<cv::Vec3b>(i,j)[2];
    ui->label_img_rgb->setPixmap(QPixmap::fromImage(cvMat2QImage(img_rgb).scaled(ui->label_img_rgb->width(),ui->label_img_rgb->height(),Qt::KeepAspectRatio)));
}

RGB::~RGB()
{
    delete ui;
}

void RGB::on_R_Slider_valueChanged(int value)
{
    ui->lcdNumber_R->display(value);

    for (int i = 0; i <= img.cols; i++) {
        for (int j = 0; j <= img.rows; j++) {
            int red = img.at<cv::Vec3b>(i,j)[2];
            if(red + value > 255){
                img_rgb.at<cv::Vec3b>(i,j)[2] = 255;
            }
            else if (red + value < 0) {
                img_rgb.at<cv::Vec3b>(i,j)[2] = 0;
            }
            else {
                img_rgb.at<cv::Vec3b>(i,j)[2] = red + value;
            }
        }
    }
    ui->label_img_rgb->setPixmap(QPixmap::fromImage(cvMat2QImage(img_rgb).scaled(ui->label_img_rgb->width(),ui->label_img_rgb->height(),Qt::KeepAspectRatio)));

}

void RGB::on_G_Slider_valueChanged(int value)
{
    ui->lcdNumber_G->display(value);

    for (int i = 0; i <= img.cols; i++) {
        for (int j = 0; j <= img.rows; j++) {
            int green = img.at<cv::Vec3b>(i,j)[1];
            if(green + value > 255){
                img_rgb.at<cv::Vec3b>(i,j)[1] = 255;
            }
            else if (green + value < 0) {
                img_rgb.at<cv::Vec3b>(i,j)[1] = 0;
            }
            else {
                img_rgb.at<cv::Vec3b>(i,j)[1] = green + value;
            }
        }
    }
    ui->label_img_rgb->setPixmap(QPixmap::fromImage(cvMat2QImage(img_rgb).scaled(ui->label_img_rgb->width(),ui->label_img_rgb->height(),Qt::KeepAspectRatio)));
}

void RGB::on_B_Slider_valueChanged(int value)
{
    ui->lcdNumber_B->display(value);

    for (int i = 0; i <= img.cols; i++) {
        for (int j = 0; j <= img.rows; j++) {
            int blue = img.at<cv::Vec3b>(i,j)[0];       //B[0]G[1]R[2]
            if(blue + value > 255){
                img_rgb.at<cv::Vec3b>(i,j)[0] = 255;
            }
            else if (blue + value < 0) {
                img_rgb.at<cv::Vec3b>(i,j)[0] = 0;
            }
            else {
                img_rgb.at<cv::Vec3b>(i,j)[0] = blue + value;
            }
        }
    }
    ui->label_img_rgb->setPixmap(QPixmap::fromImage(cvMat2QImage(img_rgb).scaled(ui->label_img_rgb->width(),ui->label_img_rgb->height(),Qt::KeepAspectRatio)));
}

void RGB::on_pushButton_apply_clicked()
{
    img = img_rgb;
    accept();

    history.push_back(img.clone()); //by flappy
    historyNum++;
}
