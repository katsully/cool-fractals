//
//  Circle.cpp
//  Fractals
//
//  Created by Kathleen Sullivan on 3/22/17.
//
//

#include "Circle.h"
#include "cinder/app/App.h"
#include "cinder/gl/gl.h"

using namespace ci;
using namespace ci::app;
using namespace std;

Circle::Circle()
{
}

Circle::Circle(float x, float y, float radius)
{
    mX = x;
    mY = y;
    mRadius = radius;
}

// THIRD
//void Circle::drawCircle(float y)
//{
//    gl::drawStrokedCircle(vec2(mX, y), mRadius);
//}

// FOURTH
void Circle::drawCircle(float y, Color color)
{
    // FOURTH
    gl::color(color);
    gl::drawStrokedCircle(vec2(mX, y), mRadius);
}
