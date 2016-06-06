//
// Created by Priyanshu Singh on 22/10/15.
//

#ifndef COLORIT_BLENDPIXEL_HPP
#define COLORIT_BLENDPIXEL_HPP

#include <opencv2/hal/defs.h>

#define MAX_BLEND_COLOR 3
#define MAX_DISTANCE    65535

class BlendPixel {
public:
    int x,y;
    uchar cr[MAX_BLEND_COLOR];
    uchar cb[MAX_BLEND_COLOR];
    uchar Y;
    float dist[MAX_BLEND_COLOR];

};


#endif //COLORIT_BLENDPIXEL_HPP
