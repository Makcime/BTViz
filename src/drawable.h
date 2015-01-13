#ifndef _OF_NODE // if this class hasn't been defined, the program can define it
#define _OF_NODE // by using this if statement you prevent the class to be called more
                 // than once which would confuse the compiler
 
#include "ofMain.h"
#include <math.h>

// #define PART_SIZE 255
#define FILE_SIZE 20
#define DEFAULT_SIZE 40
#define EPSILON 10

struct point
{
    /* data */
    int x, y;
};

class drawable {

    public: // place public functions or variables declarations here
 
        // methods, equivalent to specific functions of your class objects
        void update();  // update method, used to refresh your objects properties
        void draw(ofColor* file[]);    // draw method, this where you'll do the object's drawing
        void moveTo(float xSpeed);
        void moveTo(float _xDestiny, float _yDestiny, 
            float xSpeed,  float acceleration);

        bool inArea(point p);
        void setPosition(int x, int y);

        static void setDraggable(int index);
        static int isDraggable();
        static bool comparePosition(point dest, point pos);

        drawable(int _x, int _y,  int _dim, ofColor _color, bool fill); // constructor - used to initialize an object, if no properties are passed
        drawable(); // default constructor set random position but fixed size ant color
 
    private: // place private functions or variables declarations here
        static int draggable;
        ofColor color; // = ofColor::blue;
        bool fillnofill, isMoving;
        point position, destination;
        int dim;      // size

}; // dont't forget the semicolon!!
 
#endif