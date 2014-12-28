#pragma once

#include "ofMain.h"
#include "btNode.h"
#include <vector>
// #include "Seeder.h"


using namespace std;

#define MAX_NODES 1024
#define START_NODES_NB 	0
#define FILE_SIZE 20


struct part
{
    bool reached;
    ofColor *color;
};


class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

		void freeVectors();

		// btNode *Network[MAX_NODES];

		vector<btNode*> nw;

		ofColor* torrent[FILE_SIZE];

		int nbNodes = 0;
        int part = FILE_SIZE/2;


		float speedX = 0;
		float speedY = 0;

		btNode *packet, *seeder, *leecher, *dest;

};
