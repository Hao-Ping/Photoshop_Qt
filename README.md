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
