#ifndef _OF_NODE // if this class hasn't been defined, the program can define it
#define _OF_NODE // by using this if statement you prevent the class to be called more
                 // than once which would confuse the compiler
 
#include "ofMain.h"
 
class btNode {
 
    public: // place public functions or variables declarations here
 
        // methods, equivalent to specific functions of your class objects
        void update();  // update method, used to refresh your objects properties
        void draw();    // draw method, this where you'll do the object's drawing
        void moveTo(int _xDestiny, int _yDestiny);
 
        // variables
        float x;      // position
        float y;
        // float speedY; // speed and direction
        // float speedX;
        int dim;      // size
 
        btNode(float _x, float _y); // constructor - used to initialize an object, if no properties are passed
                  //               the program sets them to the default value
 
    private: // place private functions or variables declarations here
 
}; // dont't forget the semicolon!!
 
#endif