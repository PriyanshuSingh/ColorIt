//
// Created by Priyanshu Singh on 03/12/15.
//

#ifndef COLORIT_RASTERLABEL_HPP
#define COLORIT_RASTERLABEL_HPP

#include <QLabel>
#include <QMouseEvent>
#include <opencv2/core/core.hpp>
using namespace cv;
using namespace std;

class RasterLabel: public QLabel {

private:
    Mat originalImage;
    Mat layeredImage;
    QPoint previous;
    QColor lineColor;
    int thickness;

    void renderImage();

protected:
    virtual void mousePressEvent(QMouseEvent *ev) override;

    virtual void mouseMoveEvent(QMouseEvent *ev) override;

    virtual void mouseReleaseEvent(QMouseEvent *ev) override;

public slots:

    void setThickness(int thickness) {
        RasterLabel::thickness = thickness;
    }

    void setLineColor(const QColor &lineColor) {
        RasterLabel::lineColor = lineColor;
    }

    void setOriginalImage(const Mat &originalImage) {
        RasterLabel::originalImage = originalImage;
        layeredImage = originalImage.clone();
        setFixedSize(originalImage.cols, originalImage.rows);
        renderImage();
    }

public:
    explicit RasterLabel(QWidget *parent = 0);

    const Mat &getLayeredImage() const {
        return layeredImage;
    }


    const Mat &getOriginalImage() const {
        return originalImage;
    }

};


#endif //COLORIT_RASTERLABEL_HPP
