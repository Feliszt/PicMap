#include "shape.h"

Shape::Shape(int numVertex) {
    // set initial position
    pos = ofVec2f(ofGetScreenWidth(), ofGetScreenHeight()) / 2;

    // create vertices
    for(int i = 0; i < numVertex; i++) {
        float theta = ofMap(i, 0, numVertex, 0, 2 * PI) + PI / 4;
        float x = pos.x + rho * cos(theta);
        float y = pos.y + rho * sin(theta);
        Corner currCorn = Corner(x, y);
        currCorn.id = i;
        corners.push_back(currCorn);
    }
    numVert = numVertex;

    // when a shape is created, we can edit it
    edit = true;
}

void Shape::update() {
    ofVec2f tempPos;
    for(int i = 0; i < numVert; i++) {
        // update edit value of each corner
        corners[i].editShape = edit;

        // update pos
        tempPos += corners[i].getPos();
    }
    tempPos /= numVert;
    pos.set(tempPos);
}

void Shape::draw() {
    // draw each corner
    for(int i = 0; i < corners.size(); i++) {
        // draw corner
        corners[i].draw();

        // draw line between corners
        if(i > 0) {
            ofDrawLine(corners[i-1].getPos(), corners[i].getPos());
        }
        ofDrawLine(corners[0].getPos(), corners[corners.size()-1].getPos());
    }

    // check if move gizmo is hovered
    moveModHovered = edit && (ofGetMouseX() < pos.x + hovRad) && (ofGetMouseX() > pos.x - hovRad) && (ofGetMouseY() < pos.y + hovRad) && (ofGetMouseY() > pos.y - hovRad);

    // moving
    if(moveModHovered && ofGetMousePressed() && !mousePressedPrev) {
      move = true;
    }
    move &= ofGetMousePressed();

    if(move && !movePrev) {
      mousePosStart.set(ofGetMouseX(), ofGetMouseY());
      cornersPosStarMove.clear();
      for(int i = 0; i < numVert; i++) {
        cornersPosStarMove.push_back(corners[i].getPos());
      }
    }

    if(move) {
        for(int i = 0; i < numVert; i++) {
            ofVec2f diff = ofVec2f(cornersPosStarMove[i].x + ofGetMouseX() - mousePosStart.x, cornersPosStarMove[i].y + ofGetMouseY() - mousePosStart.y);
            corners[i].pos = diff;
        }
    }

    // update stuff
    movePrev = move;
    mousePressedPrev = ofGetMousePressed();

    // if edit mode we draw gizmos to reshape globally
    if(edit) {
        ofFill();
        ofDrawCircle(pos, 3);

        if(moveModHovered) {
            ofNoFill();
            ofDrawCircle(pos, hovRad);
        }
    }
}

void Shape::setShapeCorners(int _numVert, vector<ofVec2f> _corners) {
    // set numVert
    numVert = _numVert;

    // set corners
    corners.clear();
    for(int i = 0; i < _numVert; i++) {
        Corner newCorner = Corner(_corners[i].x, _corners[i].y);
        corners.push_back(newCorner);
    }
}

vector<ofVec2f> Shape::getVertices() {
    // set corners
    vector<ofVec2f> res;
    for(int i = 0; i < numVert; i++) {
        res.push_back(corners[i].getPos());
    }
    return res;
}
