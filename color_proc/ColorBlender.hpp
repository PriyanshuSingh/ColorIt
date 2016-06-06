//
// Created by Priyanshu Singh on 22/10/15.
//

#ifndef COLORIT_COLORIT_HPP
#define COLORIT_COLORIT_HPP

#define DEBUG

// debugging

#ifdef DEBUG
#define METHOD_NAME                        fprintf(stderr, "%s:%d - ", __PRETTY_FUNCTION__, __LINE__);
#define trace1(x)                    cerr<<"(" << __LINE__ <<"): "<< #x << "=" << x << endl;
#define trace2(x, y)                 cerr<<"(" << __LINE__ <<"): "<< #x << "=" << x << " | " << #y << "=" << y << endl;
#define trace3(x, y, z)              cerr<<"("<< __LINE__ <<"): "<< #x << "=" << x << " | " << #y << "=" << y << " | " << #z << "=" << z << endl;
#define trace4(a, b, c, d)           cerr<<"(" << __LINE__ <<"): "<< #a << "=" << a << " | " << #b << "=" << b << " | " << #c << "=" << c << " | " << #d << "=" << d << endl;
#define trace5(a, b, c, d, e)        cerr<<"(" << __LINE__ <<"): "<< #a << "=" << a << " | " << #b << "=" << b << " | " << #c << "=" << c << " | " << #d << "=" << d << " | " << #e << "=" << e << endl;
#define trace6(a, b, c, d, e, f)     cerr<<"(" << __LINE__ <<"): "<< #a << "=" << a << " | " << #b << "=" << b << " | " << #c << "=" << c << " | " << #d << "=" << d << " | " << #e << "=" << e << " | " << #f << "=" << f << endl;
#else
#define METHOD_NAME
#define trace1(x)
#define trace2(x, y)
#define trace3(x, y, z)
#define trace4(a, b, c, d)
#define trace5(a, b, c, d, e)
#define trace6(a, b, c, d, e, f)
#endif


#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <queue>
#include "BlendPixel.hpp"

using namespace cv;
using namespace std;

class ColorBlender {

private:
    const Mat* grayImg;
    const Mat* layerImg;
    Vec3b bgColor;
    Mat* output;

protected:
    BlendPixel*** pixelArray;
    queue<BlendPixel *> activeQueue;
    void propogateColor();                                      // expand the frontier
    void blendColor(const Mat *original = nullptr);                                          // color the picture
    void generateColoredSet();                                  // generate the colored set
    bool modifyPixel(BlendPixel &cur, BlendPixel &test);        // pixel modified wrt test pixel
    void allocateArray();                     // allocate pixelArray
    void releaseArray();                      // release pixelArray
    inline double weight(double d);                             // a simple weight function
    void assertImage();

public:
    virtual ~ColorBlender() { }

    ColorBlender() { }

    Mat* colorize(const Mat* _grayImageInRGB, const Mat* _layerImageInRGB);
    Mat* colorize(const Mat* _grayImageInRGB, const Mat* _layerImageInRGB, const Vec3b backgroundColorInRGB);

};


#endif //COLORIT_COLORIT_HPP
