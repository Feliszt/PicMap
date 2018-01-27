#include "shapemanager.h"

ShapeManager::ShapeManager()
{

}

Shape ShapeManager::AddSquare(ofTrueTypeFont font) {
    // create and add shape to vector
    Shape newShape = Shape(4);
    shapes.push_back(newShape);

    // create button for shape
    currEditShape = numShapes;
    Button butt = Button();
    string str = "Square #";
    butt.setup(str, font);
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

void ShapeManager::drawShapes() {
    //
    for(int i = 0; i < shapes.size(); i++) {
        shapes[i].draw();
    }
}

void ShapeManager::drawButtons(ofMatrix4x4 trans) {
    float hOffset = 100;
    for(int i = 0; i < buttons.size(); i++) {
        buttons[i].draw(0, hOffset, trans);
        hOffset += 50;
    }
}
