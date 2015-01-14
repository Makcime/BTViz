#ifndef _PACKET // if this class hasn't been defined, the program can define it
#define _PACKET // by using this if statement you prevent the class to be called more
                 // than once which would confuse the compiler

#include "drawable.h"
#include "btNode.h"

#define PACKET_SIZE 5

class packet: public drawable {

 
public: // place public functions or variables declarations here
    packet(); 
    packet(point p, point dest, ofColor _color, int _speed); 
    packet(btNode *src, btNode * dest, 
        ofColor _color, int _speed, int id, int index); 

    point getPosition();

    int getPartIndex();
    void setPartIndex(int i);
    void reachedDestination();

private: // place private functions or variables declarations here
        // using drawable::drawable;

	int partIndex, downloaderIndex;

	btNode *leecher, *seeder;

}; // dont't forget the semicolon!!
 
#endif