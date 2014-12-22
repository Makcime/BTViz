#ifndef _OF_NODE // if this class hasn't been defined, the program can define it
#define _OF_NODE // by using this if statement you prevent the class to be called more
                 // than once which would confuse the compiler
 
#include "ofMain.h"
#include <math.h>
 
class btNode {

    // un node représente n'importe qui sur le réseau BttTorrent
    // Chaque node participe au partage d'un fichier
    // les fichier sont définis comme des torrent fils
 
    public: // place public functions or variables declarations here
 
        // methods, equivalent to specific functions of your class objects
        void update();  // update method, used to refresh your objects properties
        void draw();    // draw method, this where you'll do the object's drawing
        void moveTo(float _xDestiny, float _yDestiny, 
            float xSpeed,  float acceleration);

        // status variables
        bool isSeeder = false;
        
 
        // Drawing variables
        float x;      // position
        float y;
        int dim;      // size
        ofColor color; // = ofColor::blue;



        btNode(float _x, float _y,  ofColor _color ); // constructor - used to initialize an object, if no properties are passed
                  //               the program sets them to the default value
 
    private: // place private functions or variables declarations here
 
}; // dont't forget the semicolon!!
 
#endif