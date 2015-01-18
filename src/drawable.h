#ifndef _DRAWABLE		// if this class hasn't been defined, the program can define it
#define _DRAWABLE		// by using this if statement you prevent the class to be called more
// than once which would confuse the compiler

#include "ofMain.h"
#include <math.h>

// #define PART_SIZE 255
#define FILE_SIZE 20
#define DEFAULT_SIZE 40
#define EPSILON 5

struct point
{
    /* data */
    float x, y;
};

class drawable
{

public:			// place public functions or variables declarations here

    // methods, equivalent to specific functions of your class objects
    void update();		// update method, used to refresh your objects properties
    void draw();		// draw method, this where you'll do the object's drawing
    void moveTo(float xSpeed);
    void moveTo(float _xDestiny, float _yDestiny,
                float xSpeed, float acceleration);

    void setDestination(point p);

    bool inArea(point p);
    void setPosition(float x, float y);
    point getPosition();

    bool onTheMove();

    static void setDraggable(int index);
    static int isDraggable();
    static bool comparePosition(point dest, point pos);

    drawable(float _x, float _y, int _dim, ofColor _color, bool fill);	// constructor - used to initialize an object, if no properties are passed
    drawable(float _x, float _y, ofColor _color);	// constructor - used to initialize an object, if no properties are passed
    drawable(point p, int _dim, ofColor _color, bool fill);	// constructor - used to initialize an object, if no properties are passed
    drawable();		// default constructor set random position but fixed size ant color

protected:		// place private functions or variables declarations here
    static int draggable;
    ofColor color;		// = ofColor::blue;
    bool fillnofill, isMoving;
    point position, destination;
    float speed;
    int dim;		// size



};				// dont't forget the semicolon!!

#endif
