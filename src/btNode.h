#ifndef _OF_NODE // if this class hasn't been defined, the program can define it
#define _OF_NODE // by using this if statement you prevent the class to be called more
                 // than once which would confuse the compiler

#include "drawable.h"

class btNode: public drawable {

 
public: // place public functions or variables declarations here
    btNode(); 
    btNode(int _x, int _y, ofColor _color); 
    btNode(point p, int _dim, ofColor _color, bool fill); // constructor - used to initialize an object, if no properties are passed

    void draw();
    void draw(ofColor *file);

    point getPosition();

    bool getReached(int index);
    void setReached(int index, bool val);

    void request();
    int getPartToRequest();

    bool isDowloading();
    void setDowloading(bool state);
	
	bool checkFull();
    
private: // place private functions or variables declarations here
        // using drawable::drawable;
    bool part_reached[FILE_SIZE];
    int partToRequest;
    bool isFull = false;
    bool dowloading = false;
 
}; // dont't forget the semicolon!!
 
#endif