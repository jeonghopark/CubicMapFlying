#include "ofMain.h"
#include "ofApp.h"
#include "GuiApp.h"
#include "ofAppGLFWWindow.h"

//========================================================================
int main( ){
    
    ofGLFWWindowSettings settings;
    
    settings.width = 300;
    settings.height = 300;
    settings.setPosition(ofVec2f(0,0));
    settings.resizable = false;
    shared_ptr<ofAppBaseWindow> guiWindow = ofCreateWindow(settings);
    
    settings.width = 1280;
    settings.height = settings.width * 9 / 16.0;
    settings.setPosition(ofVec2f(100,0));
    settings.resizable = true;
    shared_ptr<ofAppBaseWindow> mainWindow = ofCreateWindow(settings);
    
    shared_ptr<GuiApp> guiApp(new GuiApp);
    shared_ptr<ofApp> mainApp(new ofApp);
    mainApp->gui = guiApp;
    
    ofRunApp(mainWindow, mainApp);
    ofRunApp(guiWindow, guiApp);
    ofRunMainLoop();
    
}
