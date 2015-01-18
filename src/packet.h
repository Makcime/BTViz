/**
 * @file packet.h
 * @brief header file for packet class declaration
 *
 * A class wich manage a packet sent into a torrent share.
 *
 * @author Marlier Maxime <marlier.maxime@gmail.com>
 *
 **/

#ifndef _PACKET			// if this class hasn't been defined, the program can define it
#define _PACKET			// by using this if statement you prevent the class to be called more
// than once which would confuse the compiler

#include "drawable.h"
#include "btNode.h"

#define PACKET_SIZE 5

class packet:public drawable
{


public:	
    packet();
    packet(point p, point dest, ofColor _color, int _speed);
    packet(btNode * src, btNode * dest,
           ofColor _color, int _speed, int id, int index);

    void update();

    int getPartIndex();
    void setPartIndex(int i);
    void reachedDestination();

private:

    int partIndex, downloaderIndex;

    btNode *leecher, *seeder;

};

#endif
