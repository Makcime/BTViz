#ifndef _TORRENT_SHAARE // if this class hasn't been defined, the program can define it
#define _TORRENT_SHAARE // by using this if statement you prevent the class to be called more
                 // than once which would confuse the compiler

#include "btNode.h"

class torrentShare{

 
public: // place public functions or variables declarations here
    torrentShare();

    void update();
    void draw();

    void addNode();
    void removeNode();

    void sendPacket();

    

private: // place private functions or variables declarations here
        // using drawable::drawable;

	vector<btNode*> nw, packet; // na bit torrent network is a vector of nodes
	
 
}; // dont't forget the semicolon!!
 
#endif