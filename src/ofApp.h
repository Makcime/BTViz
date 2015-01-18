/**
 * @file ofApp.h
 * @brief header file for ofApp class declaration
 *
 * A class wich manage creation of a torrentShare
 * will manage events like key pressed, draw and update callback functions, 
 *
 * @author Marlier Maxime <marlier.maxime@gmail.com>
 *
 **/

 #pragma once

#include "ofMain.h"
#include "btNode.h"
#include "torrentShare.h"
#include <vector>


using namespace std;

#define MAX_NODES 1024
#define START_NODES_NB 	0
#define PART 19


struct part
{
    bool reached;
    ofColor *color;
};


class ofApp:public ofBaseApp
{

public:
    void setup();
    void update();
    void draw();

    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y);
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);

    void freeVectors();

    ofSoundPlayer mySound;


private:

    // vector<btNode*> nw; // na bit torrent network is a vector of nodes

    int nbNodes = 0;
    int part = PART;
    int dragged = 0;

    torrentShare *share;	//, *share2;

    float speedX = 0;
    float speedY = 0;

    // btNode *packet, *seeder, *leecher, *dest;


};
