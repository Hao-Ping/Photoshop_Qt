# Simple photoshop with image processing on Qt
demo: https://www.youtube.com/watch?v=aNB48DgDeRM
![截圖 2022-12-06 下午2 23 44](https://user-images.githubusercontent.com/49761419/205837050-2fe943fb-8ff8-4324-b242-8c0ef07f35da.png)

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
    }
}
```

## Hue
```cpp
void hue::on_hueSlider_valueChanged(int value)
{
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
}
```
## Saturation
```cpp
void Saturation::on_saturationSlider_valueChanged(int value)
{
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
}
```
## Brightness(Value)
```cpp
void Brightness::on_brightnessSlider_valueChanged(int value)
{
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
}
```
## RGB
R for example
```cpp
void RGB::on_R_Slider_valueChanged(int value)
{
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
}
```

## Box Filter
```cpp
void Filter::on_radioButton_box_clicked()
{
    img_filter = img.clone();
    cv::blur(img, img_filter, cv::Size(w,h));
}
```
## Gauss Blur
```cpp
void Filter::on_radioButton_Gauss_clicked()
{
    img_filter = img.clone();
    cv::GaussianBlur(img, img_filter, cv::Size(w,h), 0);
}
```
## Median Blur
```cpp
void Filter::on_radioButton_Median_clicked()
{
    img_filter = img.clone();
    cv::medianBlur(img, img_filter, k);
}
```
## Bilateral filter
```cpp
void Filter::on_radioButton_bilateral_clicked()
{
    img_filter = img.clone();
    cv::bilateralFilter(img, img_filter, k, k*2, k/2);
}
```
## Sharpening
```cpp
void Filter::on_radioButton_sharpening_clicked()
{
    img_filter = img.clone();
    cv::Mat sharpeningKernel = (cv::Mat_<double>(3,3) << 0, -1, 0, -1, 5, -1, 0, -1, 0);

    filter2D(img, img_filter, -1, sharpeningKernel);
}

```
