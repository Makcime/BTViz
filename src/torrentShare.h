#ifndef _TORRENT_SHAARE // if this class hasn't been defined, the program can define it
#define _TORRENT_SHAARE // by using this if statement you prevent the class to be called more
                 // than once which would confuse the compiler

#include "btNode.h"
#include "packet.h"
#include <vector>
#include <queue>
#include <algorithm>

#define FILE_SIZE 20
#define MAX_UP 2
#define MAX_DW 3


struct request
{
	// btNode* n;
	int n, id;
};

class torrentShare{

 
public: // place public functions or variables declarations here

    void update();
    void draw();

    void addNode();
    void removeNode();
    void addSeeder();

    void sendPacket();

    void updatePositions();

    torrentShare();


private: // place private functions or variables declarations here

	vector<btNode*> nw;
	vector<packet*> bucket; // a bit torrent network is a vector of nodes

	ofColor torrent[FILE_SIZE];

	// queue<request*> requestQueue;
	vector<request> requestQueue;

}; // dont't forget the semicolon!!
 
#endif