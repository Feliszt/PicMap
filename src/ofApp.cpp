#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    //shMan = ShapeManager();

    // UI SETUP
        // colors
    backgroundColor = ofColor(224, 224, 224);
    outlineColor    = ofColor(42);
    contentColor    = ofColor(212, 81, 19);
        // fonts
    overPassMono10.load("overpass-mono/overpass-mono-regular.otf", 10);
    overPassMono12.load("overpass-mono/overpass-mono-regular.otf", 12);
    overPassMono14.load("overpass-mono/overpass-mono-regular.otf", 14);

    //
    addSquareShape.setup("Square Shape", overPassMono10);
    addFreeShape.setup("Free Shape", overPassMono10);
}

//--------------------------------------------------------------
void ofApp::update(){
    // adding square shape
    if(addSquareShape.getValue()) {
        shMan.AddSquare(overPassMono10);
    }

    // adding free shape
    if(addFreeShape.getValue()) {

    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    // draw background
    ofBackground(backgroundColor);

    // init trans matrix
    ofMatrix4x4 translation;

    // title of app
    ofSetColor(outlineColor);
    overPassMono14.drawString("PIC", 30, 30);
    ofDrawRectangle(65, 13, 40, 20);
    ofSetColor(backgroundColor);
    overPassMono14.drawString("MAP", 68, 30);

    // shape manager
    translation = ofMatrix4x4::newTranslationMatrix(ofVec3f(50, 70));
    ofPushStyle();
        ofPushMatrix();

            // translation
            ofMultMatrix(translation);

            // title
            ofSetColor(outlineColor);
            overPassMono12.drawString("Shape Manager", 0, 10);

            // buttons
            addSquareShape.draw(0, 40, translation);
            shMan.drawButtons(translation);

        ofPopMatrix();
    ofPopStyle();
}

//--------------------------------------------------------------
void ofApp::drawSecondWindow(ofEventArgs &args){
    // background
    ofBackground(ofColor::black);

    //
    shMan.drawShapes();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    // Exit application
    if(key == 'q') {
        ofExit();
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){

}

