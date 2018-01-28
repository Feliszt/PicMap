#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    // init shape manager
    shMan = ShapeManager();

    // UI SETUP
        // colors
    backgroundColor = ofColor(224, 224, 224);
    outlineColor    = ofColor(42);
    contentColor    = ofColor(212, 81, 19);
        // fonts
    overPassMono10.load("overpass-mono/overpass-mono-regular.otf", 10);
    overPassMono12.load("overpass-mono/overpass-mono-regular.otf", 12);
    overPassMono14.load("overpass-mono/overpass-mono-regular.otf", 14);

    // load settings
    loadSettings();

    //
    addSquareShape.setup("Square Shape", overPassMono10);
    addFreeShape.setup("Free Shape", overPassMono10);
}

//--------------------------------------------------------------
void ofApp::update(){
    // update manager
    shMan.update();

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
    // background
    ofBackground(ofColor::black);

    //
    if(!play) {
        shMan.drawShapes(contentColor);
    } else {
        for(int i = 0; i < shMan.numShapes; i++) {
            //if(i == currShapeDrawn) {
                vector<ofVec2f> vertices = shMan.shapes[i].getVertices();
                ofSetColor(ofColor::white);
                ofBeginShape();
                for(int j = 0; j < vertices.size(); j++) {
                    ofVertex(vertices[j].x, vertices[j].y);
                }
                ofEndShape();
            //}
        }
        nDrawCall++;
        if(nDrawCall % 50 == 0) {
            currShapeDrawn = (int) ofRandom(0, shMan.numShapes-1);
        }
    }
}

//--------------------------------------------------------------
void ofApp::drawSecondWindow(ofEventArgs &args){    
    // draw background
    ofBackground(backgroundColor);

    // init trans matrix
    ofMatrix4x4 translation;

    // title of app
    ofSetColor(outlineColor);
    overPassMono14.drawString("PIC", 30, 30);
    ofDrawRectangle(65, 13, 41, 22);
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
            shMan.drawButtons(translation, contentColor);
        ofPopMatrix();
    ofPopStyle();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    // Exit application
    if(key == 'q') {
        saveSettings();
        ofExit();
    }

    // add square short cut
    if(key == 'a') {
        shMan.AddSquare(overPassMono10);
    }

    // save settings
    if(key == 's') {
        saveSettings();
    }

    // display info
    if(key == 'd') {
        shMan.toString();
    }

    // edit next shape
    if(key == 'k') {
        shMan.currEditShape += 1;
        if(shMan.currEditShape >= shMan.numShapes) shMan.currEditShape =0;
    }
    // edit previous shape
    if(key == 'j') {
        shMan.currEditShape -= 1;
        if(shMan.currEditShape < 0) shMan.currEditShape = shMan.numShapes - 1;
    }

    // toggle play mode
    if(key == 9) {
        play = !play;
    }
}

//--------------------------------------------------------------
void ofApp::saveSettings() {
    settings.clear();
    settings.addTag("shapes");
    settings.pushTag("shapes");
    for(int i = 0; i < shMan.numShapes; i++) {
        settings.addTag("shape");
        settings.pushTag("shape", i);
        settings.addTag("vertices");
        settings.pushTag("vertices");
        for(int j = 0; j < shMan.shapes[i].numVert; j++) {
            settings.addTag("vertice");
            settings.pushTag("vertice", j);
            settings.addValue("X", shMan.shapes[i].corners[j].getPosX());
            settings.addValue("Y", shMan.shapes[i].corners[j].getPosY());
            settings.popTag();
        }
        settings.popTag();
        settings.popTag();
    }
    settings.popTag();
    settings.saveFile("settings.xml");
    ofLog() << "Settings saved.";
}

//--------------------------------------------------------------
void ofApp::loadSettings() {
    if(settings.loadFile("settings.xml")){
        settings.pushTag("shapes");
        int nShape = settings.getNumTags("shape");
        for(int i = 0; i < nShape; i++){
            settings.pushTag("shape", i);

            settings.pushTag("vertices");
            int nVert = settings.getNumTags("vertice");
            vector<ofVec2f> newCorners;
            for(int j = 0; j < nVert; j++) {
                settings.pushTag("vertice", j);
                ofVec2f corner;
                corner.x = settings.getValue("X", 0);
                corner.y = settings.getValue("Y", 0);
                newCorners.push_back(corner);
                settings.popTag();
            }

            // add new shape
            shMan.AddSquare(overPassMono10);
            shMan.shapes.back().setShapeCorners(nVert, newCorners);

            settings.popTag();
            settings.popTag();
        }
        settings.popTag();
    }
    else{
        ofLogError("Settings file did not load!");
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

