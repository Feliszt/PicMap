#ifndef CORNER_H
#define CORNER_H

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "ofMain.h"

class Corner
{
public:    
    // methods
    void draw();
    ofVec2f getPos();
    float getPosX();
    float getPosY();

    Corner(float _x, float _y);



private:

    // variables
    ofVec2f pos, mousePosStart, squarePosStart;
    float hovRad = 30;
    float reqSz = 10;
    bool hovered;
    bool mousePressedPrev;
    bool dragged, draggedPrev;
};

#endif // CORNER_H
