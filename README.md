## Grabcut



```cpp
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

    ui->label_img->setPixmap(QPixmap::fromImage(cvMat2QImage(img).scaled(ui->label_img->width(),ui->label_img->height(),Qt::KeepAspectRatio)));

    if(historyNum >= 1){
        ui->pushButton_undo->setEnabled(true);
    }
}
```

##Hue
```cpp
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
```
