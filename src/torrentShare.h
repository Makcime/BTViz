/**
 * @file torrentShare.h
 * @brief header file for torrentShare class declaration
 *
 * A class wich manage  a torrent share (nodes, packets, requests,...).
 *
 * @author Marlier Maxime <marlier.maxime@gmail.com>
 *
 **/

#ifndef _TORRENT_SHAARE		// if this class hasn't been defined, the program can define it
#define _TORRENT_SHAARE		// by using this if statement you prevent the class to be called more
// than once which would confuse the compiler

#include "btNode.h"
#include "packet.h"
#include <vector>
#include <queue>
#include <algorithm>

#define FILE_SIZE 20
#define MAX_UP 3
#define MAX_DW 2

#define RM_RATIO 19
#define ADD_RATIO 17
#define ADD_SEED_RATIO 10000000

#define RM_NB 25
#define ADD_NB 10

#define EVENT 60

#define MIN_NW_SIZE 3

#define NOBODY_RATIO 1

struct request
{
    // btNode* n;
    int n, id;
};

class torrentShare
{


public:			// place public functions or variables declarations here

    void update();
    void draw();

    void addNode();
    void removeNode();
    void addSeeder();

    void sendPacket();

    void updatePositions();

    void flipStandalone();

    torrentShare();


private:			// place private functions or variables declarations here

    vector < btNode * >nw;
    vector < packet * >bucket;	// a bit torrent network is a vector of nodes

    ofColor torrent[FILE_SIZE];

    // queue<request*> requestQueue;
    vector < request > requestQueue;

    int cnt = 1;

    bool standalone = false;

};				// dont't forget the semicolon!!

#endif
