#include "shape.h"

Shape::Shape(int numVertex) {
    for(int i = 0; i < numVertex; i++) {
        float theta = ofMap(i, 0, numVertex, 0, 2 * PI) + PI / 4;
        float x = ofGetScreenWidth() / 2 + rho * cos(theta);
        float y = ofGetScreenHeight() / 2 + rho * sin(theta);
        Corner currCorn = Corner(x, y);
        corners.push_back(currCorn);
    }
}

void Shape::draw() {
    for(int i = 0; i < corners.size(); i++) {
        // draw corner
        corners[i].draw();

        // draw line between corners
        if(i > 0) {
            ofDrawLine(corners[i-1].getPos(), corners[i].getPos());
        }
        ofDrawLine(corners[0].getPos(), corners[corners.size()-1].getPos());

    }
}
