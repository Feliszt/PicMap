#include "ofMain.h"
#include "ofApp.h"

//========================================================================
int main( ){
    ofGLFWWindowSettings settings;

    // setup first window for kinect and image processing
    settings.width = 800;
    settings.height = 800;
    settings.resizable = false;
    settings.decorated = true;
    settings.title = "PicMap - UI window";
    settings.setPosition(ofVec2f(100, 1180));
    settings.resizable = true;
    shared_ptr<ofAppBaseWindow> mainWindow = ofCreateWindow(settings);
    shared_ptr<ofApp> mainApp(new ofApp);

    // setup second window for projection
    settings.width = 1920;
    settings.height = 1080;
    settings.setPosition(ofVec2f(0, 0));
    settings.resizable = false;
    settings.decorated = false;
    settings.title = "PicMap - Projection window";
    settings.shareContextWith = mainWindow;
    shared_ptr<ofAppBaseWindow> secondWindow = ofCreateWindow(settings);
    secondWindow->setVerticalSync(false);


    ofAddListener(secondWindow->events().draw, mainApp.get(), &ofApp::drawSecondWindow);

    ofRunApp(mainWindow, mainApp);
    ofRunMainLoop();
}
