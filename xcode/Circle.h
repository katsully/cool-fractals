//
//  Circle.h
//  Fractals
//
//  Created by Kathleen Sullivan on 3/22/17.
//
//
#include "cinder/app/App.h"

#pragma once

using namespace ci;
using namespace ci::app;
using namespace std;

class Circle
{
public:
    Circle();
    Circle(float x, float y, float radius);

    // THIRD
//    void drawCircle(float y);
    
    // FOURTH
    void drawCircle(float y, Color color);
    
    float mX;
    float mY;
    float mRadius;
};