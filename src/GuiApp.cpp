#include "GuiApp.h"

void GuiApp::setup(){
	parameters.setName("parameters");
    parameters.add(windowsAlpha.set("WindowsAlpha", 255, 0, 255));
    main.setup(parameters);
    main.setPosition(10, 10);
    
    basicShapes.setup("basicShapes");
    basicShapes.setPosition(300, 10);
    basicShapes.add(colorBackground.setup("colorBackground", ofColor(0, 0, 0), ofColor(0, 0), ofColor(255, 255)));
    basicShapes.add(colorBuilding.setup("colorBuilding", ofColor(255, 255, 255), ofColor(0, 0), ofColor(255, 255)));
    basicShapes.add(colorStreet.setup("colorStreet", ofColor(255, 255, 255), ofColor(0, 0), ofColor(255, 255)));
    basicShapes.add(streetWidth.setup("streetWidth", 1, 0.1, 10));
    basicShapes.add(movingObjectSize.setup("movingObjectSize", 1, 0.1, 100));

	ofBackground(0);
	ofSetVerticalSync(false);
}

void GuiApp::update(){

}

void GuiApp::draw(){

    main.draw();
    basicShapes.draw();
    
}
