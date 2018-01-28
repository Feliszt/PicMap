#include "shapemanager.h"
#include "ofApp.h"

ShapeManager::ShapeManager()
{
    // init
    shapes.clear();
}

Shape ShapeManager::AddSquare(ofTrueTypeFont font) {
    // create and add shape to vector
    Shape newShape = Shape(4);
    newShape.id = numShapes;
    shapes.push_back(newShape);

    // create button for shape
    currEditShape = numShapes;
    Button butt = Button();
    string str = "Square #" + std::to_string(numShapes);
    ofColor bgButton(0, 0, 0, 0);
    butt.setup(str, font, ofColor::black, bgButton);
    buttons.push_back(butt);

    numShapes += 1;

    return newShape;
}

Shape ShapeManager::AddCircle(ofTrueTypeFont font) {
    // create and add shape to vector
    Shape newShape = Shape(15);
    shapes.push_back(newShape);

    return newShape;
}

void ShapeManager::update() {
    // find which shape is being updated
    for(int i = 0; i < numShapes; i++) {
        shapes[i].edit = false;
        if(buttons[i].getValue() || i == currEditShape) {
            shapes[i].edit = true;
            currEditShape = i;
        }
    }

    // update each shape
    for(int i = 0; i < numShapes; i++) {
        shapes[i].update();
    }
}

void ShapeManager::drawShapes(ofColor contentColor) {
    //
    for(int i = 0; i < shapes.size(); i++) {
        ofColor coltoDraw = (i == currEditShape ? contentColor : ofColor::white);
        ofSetColor(coltoDraw);
        shapes[i].draw();
    }
}

void ShapeManager::drawButtons(ofMatrix4x4 trans, ofColor contentColor) {
    float hOffset = 100;
    for(int i = 0; i < buttons.size(); i++) {
        ofColor coltoDraw = (i == currEditShape ? contentColor : ofColor::black);
        buttons[i].setTextColor(coltoDraw);
        buttons[i].draw(0, hOffset, trans);
        hOffset += 40;
    }
}

void ShapeManager::toString() {
    ofLog() << "There is " << numShapes << " shapes";
    for(int i = 0; i < numShapes; i++) {
        ofLog() << "Shape #" << i << " contains " << shapes[i].numVert << " vertices.";
    }
    ofLog() << "\n";
}
