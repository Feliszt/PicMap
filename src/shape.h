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
    Shape(int numVertex);

    void draw();

private:
    // variables
    vector<Corner>  corners;
    ofVec2f         pos;
    float           rho = 50;
};

#endif // SHAPE_H
