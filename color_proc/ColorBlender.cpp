//
// Created by Priyanshu Singh on 22/10/15.
//

#include <iostream>
#include <opencv2/highgui.hpp>
#include "ColorBlender.hpp"

void ColorBlender::allocateArray() {
    assertImage();
    int rows = grayImg->rows;
    int cols = grayImg->cols;
    Mat g;
    cvtColor(*grayImg,g,CV_RGB2GRAY);
    pixelArray = new BlendPixel**[rows];
    for(int i=0; i<rows; i++){
        pixelArray[i] = new BlendPixel*[cols];
    }
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            pixelArray[i][j] = new BlendPixel();
            pixelArray[i][j]->x = j;
            pixelArray[i][j]->y = i;
            for(int k=0; k < MAX_BLEND_COLOR; k++){
                pixelArray[i][j]->dist[k] = MAX_DISTANCE;
                pixelArray[i][j]->cb[k] = pixelArray[i][j]->cr[k] = 0;
            }
            pixelArray[i][j]->Y = g.at<uchar>(i,j);
        }
    }
}

void ColorBlender::releaseArray() {
    assertImage();
    int rows = grayImg->rows;
    int cols = grayImg->cols;
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            delete pixelArray[i][j];
        }
    }
    for(int i=0; i<rows; i++){
        delete pixelArray[i];
    }
    delete pixelArray;
}

Mat* ColorBlender::colorize(const Mat *_grayImageInRGB, const Mat *_layerImageInRGB) {

    this->grayImg = _grayImageInRGB;
    this->layerImg = _layerImageInRGB;
    Mat *out = new  Mat(grayImg->size(), CV_8UC3);
    this->output = out;
    assertImage();
    allocateArray();
        generateColoredSet();
        propogateColor();
        blendColor();
        cvtColor(*output, *output, CV_YCrCb2RGB);
    releaseArray();
    this->grayImg = this->layerImg = nullptr;
    this->output = nullptr;
    return out;
}

void ColorBlender::generateColoredSet() {
    assertImage();
    Mat l;
    cvtColor(*layerImg,l,CV_RGB2YCrCb);
    int rows = grayImg->rows;
    int cols = grayImg->cols;
    while(!activeQueue.empty())activeQueue.pop();
    for(int _x=0; _x<cols; _x++){
        for(int _y=0; _y<rows; _y++){
            //as opencv is row major
            if(grayImg->at<Vec3b>(_y,_x) != layerImg->at<Vec3b>(_y,_x)){
                Vec3b pixelValue = l.at<Vec3b>(_y,_x);
                if(pixelValue[1] == 0 || pixelValue[2] == 0)continue;
                pixelArray[_y][_x]->cb[0] = pixelValue[1];
                pixelArray[_y][_x]->cr[0] = pixelValue[2];
                pixelArray[_y][_x]->dist[0] = 0;
                activeQueue.push(pixelArray[_y][_x]);
            }
        }
    }
}

void ColorBlender::assertImage() {
    assert(grayImg != nullptr && layerImg != nullptr && output != nullptr);
    assert(grayImg->size()== layerImg->size());
}


void ColorBlender::propogateColor() {
    int rows = grayImg->rows;
    int cols = grayImg->cols;
    while(!activeQueue.empty()){
            BlendPixel *pixel = activeQueue.front();
        activeQueue.pop();
            for (int y = pixel->y - 1; y <= pixel->y + 1; ++y) {
                for (int x = pixel->x - 1; x <= pixel->x + 1; ++x) {
                    if (x != pixel->x || y != pixel->y) {
                        if (x >= 0 && x < cols && y >= 0 && y < rows) {
                            BlendPixel *testPixel = pixelArray[y][x];
                            if (modifyPixel(*pixel, *testPixel))activeQueue.push(testPixel);
                        }
                    }
                }
            }
    }
}

bool ColorBlender::modifyPixel(BlendPixel &cur, BlendPixel &test) {
    double y1 = cur.Y;
    double y2 = test.Y;
    double d = abs(y1 - y2);
    bool result = false;

    for(int i=0; i < MAX_BLEND_COLOR; i++){
        if(cur.dist[i] < MAX_DISTANCE){
            int j=0;
            while(cur.dist[i] + d >= test.dist[j] && j < MAX_BLEND_COLOR){
                if(cur.cb[i] == test.cb[j] && cur.cr[i] == test.cr[j]){
                    j=MAX_BLEND_COLOR;
                    break;
                }
                j++;
            }
            if(j < MAX_BLEND_COLOR){
                if(cur.cb[i] != test.cb[j] && cur.cr[i] != test.cr[j]){
                    for(int k=MAX_BLEND_COLOR-1; k > j; k--){
                        if(test.cb[k-1]!=cur.cb[i] && test.cr[k-1]!=cur.cr[i]){
                            test.cb[k] = test.cr[k-1];
                            test.cr[k] = test.cr[k-1];
                            test.dist[k] = test.dist[k-1];
                        }
                        test.cb[j] = cur.cb[i];
                        test.cr[j] = cur.cr[i];
                        test.dist[j] = (float) (cur.dist[i] + d);
                        result = true;
                    }
                }else{
                    break;
                }
            }
        }
    }
    return result;
}

void ColorBlender::blendColor(const Mat *original) {
    int rows = grayImg->rows;
    int cols = grayImg->cols;
    Mat colorMat;
    cvtColor(*grayImg, colorMat, CV_RGB2YCrCb);
    //cv::imshow("lasjf",colorMat);
    for(int y=0; y<rows; ++y){
        for(int x=0; x<cols; ++x){
            double wsum=0;
            double Cbsum=0;
            double Crsum=0;

            BlendPixel pixel = *pixelArray[y][x];
            for(int k=0; k < MAX_BLEND_COLOR; k++){
                if(pixel.dist[k] != MAX_DISTANCE){
                    double wk = weight(pixel.dist[k]);
                    wsum += wk;
                    //cerr<<(int)bgColor[1]<<" "<<(int)pixel.cb[k]<<" "<<(int)bgColor[2]<<" "<<(int)pixel.cr[k]<<"\n";
                    if(original != nullptr &&
                            pixel.cb[k] == bgColor[1] &&
                            pixel.cr[k] == bgColor[2]){

                        Vec3b origColor = colorMat.at<Vec3b>(y, x);
                        Cbsum += wk * origColor[1];
                        Crsum += wk * origColor[2];
                    }else {
                        Cbsum += wk * pixel.cb[k];
                        Crsum += wk * pixel.cr[k];
                    }
                }
            }
            Vec3b pixelValue = output->at<Vec3b>(y, x);
            pixelValue[0] = pixel.Y;
            if(wsum == 0){pixelValue[1] = 0; pixelValue[2] = 0;}
            else {
                pixelValue[1] = (uchar) (Cbsum / wsum);
                pixelValue[2] = (uchar) (Crsum / wsum);
            }

            output->at<Vec3b>(y, x) = pixelValue;
        }
    }
}

double ColorBlender::weight(double d) {
    return pow(d+1, -5.0);
}

Mat *ColorBlender::colorize(const Mat* _grayImageInRGB, const Mat* _layerImageInRGB, const Vec3b backgroundColorInRGB) {

    // getting rbg color background to YCbCr
    Mat bgc(1,1,CV_8UC3);
    bgc.at<Vec3b>(0,0) = backgroundColorInRGB;
    // color in rgb so need to make bgr model to be consistence
    cvtColor(bgc, bgc,CV_BGR2YCrCb);
    bgColor = bgc.at<Vec3b>(0,0);

    // colorize it
    this->grayImg = _grayImageInRGB;
    this->layerImg = _layerImageInRGB;
    Mat *out = new  Mat(grayImg->size(), CV_8UC3);
    this->output = out;
    assertImage();
    allocateArray();
    generateColoredSet();
    propogateColor();
    blendColor(grayImg);
    cvtColor(*output, *output, CV_YCrCb2RGB);
    releaseArray();
    this->grayImg = this->layerImg = nullptr;
    this->output = nullptr;
    return out;

}
