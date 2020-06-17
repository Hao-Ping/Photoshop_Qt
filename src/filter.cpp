#include "filter.h"
#include "ui_filter.h"
#include "mainwindow.h"

extern cv::Mat img;
cv::Mat img_filter;
int w = 3;
int h = 3;
int k = 3;

extern std::vector<cv::Mat> history;
extern int historyNum;

Filter::Filter(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Filter)
{
    ui->setupUi(this);
    ui->label_img_filter->clear();
    ui->label_img_filter->setPixmap(QPixmap::fromImage(cvMat2QImage(img).scaled(ui->label_img_filter->width(),ui->label_img_filter->height(),Qt::KeepAspectRatio)));
}

Filter::~Filter()
{
    delete ui;
}

void Filter::on_w_Slider_valueChanged(int value)
{
    w = 2*value + 3;
    ui->lcdNumber_w->display(w);


    if(ui->radioButton_box->isChecked())
    {
        img_filter = img.clone();
        cv::blur(img, img_filter, cv::Size(w,h));

        ui->label_img_filter->setPixmap(QPixmap::fromImage(cvMat2QImage(img_filter).scaled(ui->label_img_filter->width(),ui->label_img_filter->height(),Qt::KeepAspectRatio)));

    }
    if(ui->radioButton_Gauss->isChecked())
    {
        img_filter = img.clone();
        cv::GaussianBlur(img, img_filter, cv::Size(w,h), 0);

        ui->label_img_filter->setPixmap(QPixmap::fromImage(cvMat2QImage(img_filter).scaled(ui->label_img_filter->width(),ui->label_img_filter->height(),Qt::KeepAspectRatio)));

    }
}

void Filter::on_h_Slider_valueChanged(int value)
{
    h = 2*value + 3;
    ui->lcdNumber_h->display(h);


    if(ui->radioButton_box->isChecked())
    {
        img_filter = img.clone();
        cv::blur(img, img_filter, cv::Size(w,h));

        ui->label_img_filter->setPixmap(QPixmap::fromImage(cvMat2QImage(img_filter).scaled(ui->label_img_filter->width(),ui->label_img_filter->height(),Qt::KeepAspectRatio)));

    }

    if(ui->radioButton_Gauss->isChecked())

    {
        img_filter = img.clone();
        cv::GaussianBlur(img, img_filter, cv::Size(w,h), 0);

        ui->label_img_filter->setPixmap(QPixmap::fromImage(cvMat2QImage(img_filter).scaled(ui->label_img_filter->width(),ui->label_img_filter->height(),Qt::KeepAspectRatio)));

    }
}

void Filter::on_k_Slider_valueChanged(int value)
{
    k = 2*value+3;
    ui->lcdNumber_k->display(k);

    if(ui->radioButton_Median->isChecked())
    {
        img_filter = img.clone();
        cv::medianBlur(img, img_filter, k);

        ui->label_img_filter->setPixmap(QPixmap::fromImage(cvMat2QImage(img_filter).scaled(ui->label_img_filter->width(),ui->label_img_filter->height(),Qt::KeepAspectRatio)));
    }
    if(ui->radioButton_bilateral->isChecked())
    {
        img_filter = img.clone();
        cv::bilateralFilter(img, img_filter, k, k*2, k/2);

        ui->label_img_filter->setPixmap(QPixmap::fromImage(cvMat2QImage(img_filter).scaled(ui->label_img_filter->width(),ui->label_img_filter->height(),Qt::KeepAspectRatio)));
    }
}

void Filter::on_radioButton_box_clicked()
{
    img_filter = img.clone();
    cv::blur(img, img_filter, cv::Size(w,h));

    ui->label_img_filter->setPixmap(QPixmap::fromImage(cvMat2QImage(img_filter).scaled(ui->label_img_filter->width(),ui->label_img_filter->height(),Qt::KeepAspectRatio)));
}

void Filter::on_radioButton_Gauss_clicked()
{
    img_filter = img.clone();
    cv::GaussianBlur(img, img_filter, cv::Size(w,h), 0);

    ui->label_img_filter->setPixmap(QPixmap::fromImage(cvMat2QImage(img_filter).scaled(ui->label_img_filter->width(),ui->label_img_filter->height(),Qt::KeepAspectRatio)));
}

void Filter::on_radioButton_Median_clicked()
{
    img_filter = img.clone();
    cv::medianBlur(img, img_filter, k);

    ui->label_img_filter->setPixmap(QPixmap::fromImage(cvMat2QImage(img_filter).scaled(ui->label_img_filter->width(),ui->label_img_filter->height(),Qt::KeepAspectRatio)));
}

void Filter::on_radioButton_bilateral_clicked()
{
    img_filter = img.clone();
    cv::bilateralFilter(img, img_filter, k, k*2, k/2);

    ui->label_img_filter->setPixmap(QPixmap::fromImage(cvMat2QImage(img_filter).scaled(ui->label_img_filter->width(),ui->label_img_filter->height(),Qt::KeepAspectRatio)));
}

void Filter::on_radioButton_sharpening_clicked()
{
    img_filter = img.clone();
    cv::Mat sharpeningKernel = (cv::Mat_<double>(3,3) << 0, -1, 0, -1, 5, -1, 0, -1, 0);

    filter2D(img, img_filter, -1, sharpeningKernel);

    ui->label_img_filter->setPixmap(QPixmap::fromImage(cvMat2QImage(img_filter).scaled(ui->label_img_filter->width(),ui->label_img_filter->height(),Qt::KeepAspectRatio)));
}

void Filter::on_pushButton_apply_clicked()
{
    img = img_filter;
    accept();

    history.push_back(img.clone()); //by flappy
    historyNum++;

}
