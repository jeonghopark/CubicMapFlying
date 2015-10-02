#pragma once

#include "ofMain.h"
#include "ofxGui.h"

class GuiApp: public ofBaseApp {

public:

    void setup();
	void update();
	void draw();

	ofParameterGroup parameters;
	ofParameter<float> windowsAlpha;
	ofxPanel main;
    
    
    ofxPanel basicShapes;
    ofxColorSlider colorBackground;
    ofxColorSlider colorBuilding;
    ofxColorSlider colorStreet;
    ofxFloatSlider streetWidth;
    ofxFloatSlider movingObjectSize;

    
};

