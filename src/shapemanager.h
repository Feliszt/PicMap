#ifndef SHAPEMANAGER_H
#define SHAPEMANAGER_H

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "ofMain.h"
#include "shape.h"
#include "ofxSimpleFloatingGui.h"

class ShapeManager
{
public:
    // constructors
    ShapeManager();

    // shape stuff
    Shape AddSquare(ofTrueTypeFont font);
    Shape AddCircle(ofTrueTypeFont font);

    // methods
    void update();

    // variables
    int  numShapes = 0;
    vector<Shape>   shapes;
    int             currEditShape;

    // draw stuff
    void drawShapes(ofColor contentColor);
    void drawButtons(ofMatrix4x4 trans, ofColor contentColor);
    void toString();
private:
    // variables
    vector<Button>  buttons;
};

#endif // SHAPEMANAGER_H
