#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"

// THIRD
#include "Circle.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class FractalsApp : public App {
  public:
    void setup() override;
    void mouseDown( MouseEvent event ) override;
    void update() override;
    void draw() override;
    
    // FIRST
    void prepareSettings( Settings *settings );
    void drawCircle( float x, float y, float radius );
    
    // THIRD
    vector<Circle> mCircles;
    float mStartAngle;
    float mAngleVel;
    
    // FOURTH
    Color mColor;
    float mHue = 0.0;

};

// FIRST
void FractalsApp::prepareSettings(Settings *settings)
{
    settings->setWindowSize(640, 360);
}

void FractalsApp::setup()
{
    // THIRD
    drawCircle(getWindowWidth()/2, getWindowHeight()/2, 300);
    mStartAngle = 0;
    mAngleVel = 0.1;
    
    // FOURTH
    mColor = Color(CM_HSV, mHue, 1, 1);
}

void FractalsApp::mouseDown( MouseEvent event )
{
}

void FractalsApp::update()
{
    // THIRD
    mStartAngle += 0.015;
    
    // FOURTH
    mHue += 0.001;
    if(mHue >= 1.0) {
        mHue = 0.0;
    }
    mColor = Color(CM_HSV, mHue, 1, 1);
}

void FractalsApp::draw()
{
    gl::clear( Color( 0, 0, 0 ) );
    
    // FIRST
    // drawCircle(getWindowWidth()/2, getWindowHeight()/2, 200);
    
    // THIRD
    float angle = mStartAngle;
    
    for(std::vector<Circle>::iterator it = mCircles.begin(); it != mCircles.end(); ++it) {
        float y = lmap( sin( angle ), -1.0f, 1.0f, 0.0f, ( float )getWindowHeight() );
        //it->drawCircle(y);
        
        //FOURTH
        it->drawCircle(y, mColor);
        angle += mAngleVel;
    }
}

// FIRST
void FractalsApp::drawCircle(float x, float y, float radius)
{
    // FIRST
    //    gl::drawStrokedCircle(vec2(x,y), radius);
    
    // THIRD
    mCircles.push_back(Circle(x, y, radius));
    
    // FIRST
//    if(radius > 2) {
//      //  drawCircle() calls itself twice, creating a branching effect. For every circle, a smaller circle is drawn to the left and the right.
//        drawCircle(x + radius/2, y, radius/2);
//        drawCircle(x - radius/2, y, radius/2);
//        
//    }
    
    // SECOND
//    if(radius > 8) {
//        drawCircle(x + radius/2, y, radius/2);
//        drawCircle(x - radius/2, y, radius/2);
//        drawCircle(x, y + radius/2, radius/2);
//        drawCircle(x, y - radius/2, radius/2);
//    }
    
    // THIRD
    if(radius > 2){
        drawCircle(x + radius/2, y, radius/2);
        drawCircle(x - radius/2, y, radius/2);
    }
    
}

CINDER_APP( FractalsApp, RendererGl )
