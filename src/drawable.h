/**
 * @file drawable.h
 * @brief header file for drawable class declaration
 *
 * A class wich manage basic function of drawable obect into the network.
 *
 * @author Marlier Maxime <marlier.maxime@gmail.com>
 *
 **/

#ifndef _DRAWABLE		// if this class hasn't been defined, the program can define it
#define _DRAWABLE		// by using this if statement you prevent the class to be called more
// than once which would confuse the compiler

#include "ofMain.h"
#include <math.h>

#define FILE_SIZE 20
#define DEFAULT_SIZE 40
#define EPSILON 5

struct point
{
    float x, y;
};

class drawable
{

public:

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

    drawable(float _x, float _y, int _dim, ofColor _color, bool fill);
    drawable(float _x, float _y, ofColor _color);
    drawable(point p, int _dim, ofColor _color, bool fill);	
    drawable();

protected:
    static int draggable;
    ofColor color;
    bool fillnofill, isMoving;
    point position, destination;
    float speed;
    int dim;



};

#endif
