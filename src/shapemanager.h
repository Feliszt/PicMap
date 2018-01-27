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

    // draw stuff
    void drawShapes();
    void drawButtons(ofMatrix4x4 trans);
private:
    // variables
    vector<Shape>   shapes;
    vector<Button>  buttons;
    int             numShapes = 0;
    int             currEditShape;
};

#endif // SHAPEMANAGER_H
