#pragma once

#include "ofMain.h"
#include "ofxSimpleFloatingGui.h"
#include "corner.h"
#include "shape.h"
#include "shapemanager.h"

class ofApp : public ofBaseApp{

public:
    void setup();
    void update();
    void draw();
    void drawSecondWindow(ofEventArgs& args);

    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void mouseEntered(int x, int y);
    void mouseExited(int x, int y);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);

    // SHAPE VARIABLES
    ShapeManager shMan;

    // UI VARIABLES
        // colors
    ofColor backgroundColor;
    ofColor outlineColor;
    ofColor contentColor;
        // font
    ofTrueTypeFont overPassMono10;
    ofTrueTypeFont overPassMono12;
    ofTrueTypeFont overPassMono14;
        // buttons
    Button          addSquareShape;
    Button          addFreeShape;
    int             nShape = 0;
    vector<Button>  shapeEdit;
};
