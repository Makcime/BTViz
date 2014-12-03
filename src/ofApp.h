#pragma once

#include "ofMain.h"
#include "btNode.h"
// #include "Seeder.h"


#define MAX_NODES 1024
#define START_NODES_NB 	0

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

		// btNode** myNode;
		btNode *myNode[MAX_NODES];
		int nbNodes = 0;
		// btNode myNodes[NBNODES];
		
};
