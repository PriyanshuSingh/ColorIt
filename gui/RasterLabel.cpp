//
// Created by Priyanshu Singh on 03/12/15.
//

#include <iostream>
#include <opencv2/imgproc.hpp>
#include "RasterLabel.hpp"

void RasterLabel::mousePressEvent(QMouseEvent *ev) {
    QLabel::mousePressEvent(ev);
    if(originalImage.empty())return;
//    cerr<<"Press "<<ev->pos().x()<<" "<<ev->pos().y()<<"\n";
//    cerr<<"color "<<lineColor.red()<<" "<<lineColor.blue()<<"\n";
    circle(layeredImage,Point(ev->x(), ev->y()), 1,
           cv::Scalar(lineColor.blue(),lineColor.green(),lineColor.red()), thickness);
    renderImage();

    previous = ev->pos();
}

void RasterLabel::mouseMoveEvent(QMouseEvent *ev) {
    QLabel::mouseMoveEvent(ev);
    if(originalImage.empty())return;
//     cerr<<"Move "<<ev->pos().x()<<" "<<ev->pos().y()<<"\n";
    circle(layeredImage,Point(ev->x(), ev->y()), 1,
           cv::Scalar(lineColor.blue(),lineColor.green(),lineColor.red()), thickness);
    renderImage();
}

void RasterLabel::mouseReleaseEvent(QMouseEvent *ev) {
    QLabel::mouseReleaseEvent(ev);
    if(originalImage.empty())return;
//    cerr<<"Release "<<ev->pos().x()<<" "<<ev->pos().y()<<"\n";
    circle(layeredImage,Point(ev->x(), ev->y()), 1,
           cv::Scalar(lineColor.blue(),lineColor.green(),lineColor.red()), thickness);
    renderImage();
}

RasterLabel::RasterLabel(QWidget *parent): QLabel(parent) {
}

void RasterLabel::renderImage() {
    if(originalImage.empty())return;
    Mat display;
    cvtColor(layeredImage, display, CV_BGR2RGB);
    QImage qimg((uchar*)display.data, layeredImage.cols, layeredImage.rows,
                layeredImage.step, QImage::Format_RGB888);
    setPixmap(QPixmap::fromImage(qimg));
}
