#ifndef CORNER_H
#define CORNER_H

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "ofMain.h"

class Corner
{
public:        
    // constructors
    Corner(float _x, float _y);

    // variables
    int   id;
    bool  editShape;
    ofVec2f pos;

    // methods
    void draw();
    ofVec2f getPos();
    float getPosX();
    float getPosY();
private:
    // variables
    ofVec2f mousePosStart, squarePosStart;
    float   hovRad = 30;
    float   reqSz = 10;
    bool    hovered;
    bool    mousePressedPrev;
    bool    dragged, draggedPrev;
};

#endif // CORNER_H
