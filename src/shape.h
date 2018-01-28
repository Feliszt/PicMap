#ifndef SHAPE_H
#define SHAPE_H

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "ofMain.h"
#include "corner.h"

class Shape
{
public:
    // constructors
    Shape(int numVertex);

    // variables
    bool         edit;
    int          numVert;
    vector<Corner>  corners;
    int          id;
    bool         move;

    // methods
    void draw();
    void update();
    void setShapeCorners(int _numVert, vector<ofVec2f> _corners);
    vector<ofVec2f> getVertices();

private:
    // variables
    vector<ofVec2f> cornersPosStarMove;
    ofVec2f         pos, mousePosStart;
    float           rho = 75;
    bool            moveModHovered, mousePressedPrev, movePrev;
    float           hovRad = 10;

};

#endif // SHAPE_H
