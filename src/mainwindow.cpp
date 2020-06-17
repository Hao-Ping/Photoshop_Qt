#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>


cv::Mat img;
std::string fileName_str;

std::vector<cv::Mat> history;
int historyNum;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->pushButton_undo->setEnabled(false);
//    brightness = new Brightness;

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionLoad_triggered()
{
    ui->label_img->clear();
    historyNum = 0;
    fileName = QFileDialog::getOpenFileName(this,
        tr("Open Image"), "/home/jana", tr("Image Files (*.png *.jpg *.bmp *.jpeg)"));
    qDebug() << fileName;
    fileName_str = fileName.toStdString();

    img = cv::imread(fileName_str); //read in cvMat image
    history.push_back(img.clone());
//    img2 = img.clone();
    if(!img.data){                                                  //check if it read successful
        qDebug() << "failed to read!!!";
    }
    ui->label_img->setPixmap(QPixmap::fromImage(cvMat2QImage(img).scaled(ui->label_img->width(),ui->label_img->height(),Qt::KeepAspectRatio)));
}

void MainWindow::on_actionSave_triggered()
{
    filePath = QFileDialog::getSaveFileName(this, tr("Save Data"), "",tr("(*.jpg)"));
        filep = filePath.toLocal8Bit().constData();
        QFile file(filePath);
        if(file.open(QFile::WriteOnly)){
            imwrite(filep,img);
            QMessageBox::information(this, "INFO","SAVE SUCCEED");
        }
        else {
            QMessageBox::warning(this, "WANRING","SAVE FAILED");
        }
}

void MainWindow::on_pushButton_brightness_clicked()
{
    Brightness brightness;
    brightness.setModal(true);
    brightness.exec();

    ui->label_img->setPixmap(QPixmap::fromImage(cvMat2QImage(img).scaled(ui->label_img->width(),ui->label_img->height(),Qt::KeepAspectRatio)));

    if(historyNum >= 1){
        ui->pushButton_undo->setEnabled(true);
    }

}

void MainWindow::on_pushButton_saturation_clicked()
{
    Saturation saturation;
    saturation.setModal(true);
    saturation.exec();

    ui->label_img->setPixmap(QPixmap::fromImage(cvMat2QImage(img).scaled(ui->label_img->width(),ui->label_img->height(),Qt::KeepAspectRatio)));

    if(historyNum >= 1){
        ui->pushButton_undo->setEnabled(true);
    }
}

void MainWindow::on_pushButton_hue_clicked()
{
    hue huee;
    huee.setModal(true);
    huee.exec();

    ui->label_img->setPixmap(QPixmap::fromImage(cvMat2QImage(img).scaled(ui->label_img->width(),ui->label_img->height(),Qt::KeepAspectRatio)));

    if(historyNum >= 1){
        ui->pushButton_undo->setEnabled(true);
    }

}

void MainWindow::on_pushButton_RGB_clicked()
{
    RGB rgb;
    rgb.setModal(true);
    rgb.exec();

    ui->label_img->setPixmap(QPixmap::fromImage(cvMat2QImage(img).scaled(ui->label_img->width(),ui->label_img->height(),Qt::KeepAspectRatio)));

    if(historyNum >= 1){
        ui->pushButton_undo->setEnabled(true);
    }

}

void MainWindow::on_pushButton_filter_clicked()
{
    Filter filter;
    filter.setModal(true);
    filter.exec();

    ui->label_img->setPixmap(QPixmap::fromImage(cvMat2QImage(img).scaled(ui->label_img->width(),ui->label_img->height(),Qt::KeepAspectRatio)));

    if(historyNum >= 1){
        ui->pushButton_undo->setEnabled(true);
    }
}

void MainWindow::on_pushButton_grabcut_clicked()
{
    cv::Mat mask = cv::Mat::zeros(img.size(), CV_8UC1);;
    cv::Mat bgdModel;
    cv::Mat fgdModel;
    cv::Rect rect = cv::Rect(50,50, 600, 800);
    cv::grabCut(img, mask, rect, bgdModel, fgdModel, 5, cv::GC_INIT_WITH_RECT);
    cv::compare(mask,cv::GC_PR_FGD,mask,cv::CMP_EQ);
    cv::Mat foreground;
    img.copyTo(foreground, mask);
    img = foreground;
    history.push_back(img.clone()); //by flappy
    historyNum++;
//    img = history[historyNum];

    ui->label_img->setPixmap(QPixmap::fromImage(cvMat2QImage(img).scaled(ui->label_img->width(),ui->label_img->height(),Qt::KeepAspectRatio)));

    if(historyNum >= 1){
        ui->pushButton_undo->setEnabled(true);
    }
}

void MainWindow::on_pushButton_cropping_clicked()
{

}

void MainWindow::on_pushButton_undo_clicked()
{
    if(historyNum <= 1){
        ui->pushButton_undo->setEnabled(false);
    }

    historyNum--;
    img = history[historyNum];
    history.erase(history.end()-1);
    ui->label_img->setPixmap(QPixmap::fromImage(cvMat2QImage(img).scaled(ui->label_img->width(),ui->label_img->height(),Qt::KeepAspectRatio)));

}

void MainWindow::on_pushButton_reset_clicked()
{
    fileName_str = fileName.toStdString();
    img = cv::imread(fileName_str);                                 //read in cvMat image
    if(!img.data){                                                  //check if it read successful
        qDebug() << "failed to read!!!";
    }
    ui->label_img->setPixmap(QPixmap::fromImage(cvMat2QImage(img).scaled(ui->label_img->width(),ui->label_img->height(),Qt::KeepAspectRatio)));

//    ui->pushButton_undo->setEnabled(false);
    history.push_back(img.clone()); //by flappy
    historyNum++;

    if(historyNum >= 1){
        ui->pushButton_undo->setEnabled(true);
    }
}
