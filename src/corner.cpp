#include "corner.h"

Corner::Corner(float _x, float _y)
{
    pos = ofVec2f(_x, _y);

    mousePosStart = ofVec2f();
    squarePosStart = ofVec2f();
}

void Corner::draw() {
        /// Update
     // hovering
     hovered = (ofGetMouseX() < pos.x + hovRad) && (ofGetMouseX() > pos.x - hovRad) && (ofGetMouseY() < pos.y + hovRad) && (ofGetMouseY() > pos.y - hovRad);

     // dragging
     if(hovered && ofGetMousePressed() && !mousePressedPrev) {
       dragged = true;
     }
     dragged &= ofGetMousePressed();

     if(dragged && !draggedPrev) {
       squarePosStart.set(pos.x, pos.y);
       mousePosStart.set(ofGetMouseX(), ofGetMouseY());
     }

     if(dragged) {
      ofVec2f diff = ofVec2f(squarePosStart.x + ofGetMouseX() - mousePosStart.x, squarePosStart.y + ofGetMouseY() - mousePosStart.y);
      pos = diff;
     }

     // update stuff
     draggedPrev = dragged;
     mousePressedPrev = ofGetMousePressed();

        /// Draw
     ofSetColor(ofColor::white);
     ofFill();
     if(hovered) {
      ofNoFill();
      ofDrawRectangle(pos.x - hovRad / 2, pos.y - hovRad / 2, hovRad, hovRad);
     }
     ofSetColor(ofColor::white);
     ofFill();
     ofDrawRectangle(pos.x - reqSz / 2, pos.y - reqSz / 2, reqSz, reqSz);
}

ofVec2f Corner::getPos() {
    return ofVec2f(pos.x, pos.y);
}

float Corner::getPosX() {
    return pos.x - reqSz / 2;
}

float Corner::getPosY() {
    return pos.y - reqSz / 2;
}
