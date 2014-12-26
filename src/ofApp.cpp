#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

	ofBackground(0,0,0);
	ofSetFrameRate(60);
	ofSetWindowTitle("Salut la compagnie");
	ofEnableSmoothing();
	ofNoFill();
	// myCircleX = 
	// myNode = new btNodede*[MAX_NODES];
	// myNode[nbNodes++-1] = new btNode(ofRandom(0,ofGetWidth()),
	// 						ofRandom(0,ofGetHeight()));
	// myNode[nbNodes++-1] = new btNode(10,10);
	Network[nbNodes] = new btNode(ofRandom(0,ofGetWidth()),
							ofRandom(0,ofGetHeight()),
							ofColor(0, 0, ofRandom( 0, 255 )));
	nbNodes = START_NODES_NB;

	// seeder = new btNode(ofGetWidth()/4, ofGetHeight()/2);
	// leecher = new btNode((ofGetWidth()/4)*3,ofGetHeight()/2);

	seeder = new btNode(ofRandom(0,ofGetWidth()),
							ofRandom(0,ofGetHeight()),
							 ofColor(ofRandom( 0, 255 ), ofRandom( 0, 255 ), ofRandom( 0, 255 )));
	leecher = new btNode(ofRandom(0,ofGetWidth()),
							ofRandom(0,ofGetHeight()),
							ofColor(ofRandom( 0, 255 ), ofRandom( 0, 255 ), ofRandom( 0, 255 )));

	packet = new btNode(seeder->x,seeder->y, ofColor::yellow);
	// packet = seeder;
	packet->dim = 6;
	// packet->color = ofColor::yellow;
	// leecher->color = ofColor::red;

	dest = leecher;
}

//--------------------------------------------------------------
void ofApp::update(){

	// if(packet->x <= leecher->x && packet->x >= seeder->x)
	// 	packet->x += speedX;
	// else{
	// 	speedX *=-1;packet->x += speedX;
	// }
	// if(packet->y != leecher->y)
	// 	packet->y += speedY;
	// if(packet->x >= leecher->x - 5)
	// 	dest = seeder;
	// else if(packet->x <= seeder->x + 5)
	// 	dest = leecher;
	float epsilon = speedX / 2;
	if(packet->x < leecher->x + epsilon && packet->x > leecher->x - epsilon &&
		packet->y < leecher->y + epsilon && packet->y > leecher->y - epsilon)
		dest = seeder;
	else if(packet->x < seeder->x + epsilon && packet->x > seeder->x - epsilon&&
		packet->y < seeder->y + epsilon && packet->y > seeder->y - epsilon)
		dest = leecher;

	// packet->moveTo(dest->x, dest->y);
	packet->moveTo(dest->x, dest->y, speedX, 0);
}

//--------------------------------------------------------------
void ofApp::draw(){
	for(int i = 0; i < nbNodes; i++)
		Network[i]->draw();

		packet->draw();
		seeder->draw();
		leecher->draw();

 	
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	switch(key){
		case 'p':
			Network[nbNodes] = new btNode(ofRandom(0,ofGetWidth()),
									ofRandom(0,ofGetHeight()),
									ofColor(ofRandom( 0, 255 ), 
										ofRandom( 0, 255 ), 
										ofRandom( 0, 255 )));
			nbNodes++;
			break;
		case 'f':
			ofToggleFullscreen();
			break;
		case 'c': //clear
			nbNodes = 0;
			break;
		case '+':
			speedX +=1;
			break;
		case '-':
			speedX--;
			if (speedX <= 0){speedX = 0;}
			break;
		default:
		break;
	}

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}
 
//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int m_x, int m_y, int button){
	if(button == 0)
		// for(int i = 0; i < nbNodes; i++)
		// 	if(x - myNode[i]->x <= abs(myNode[i]->dim/2) &&
		// 		y - myNode[i]->y <= abs(myNode[i]->dim/2)){
		// 			myNode[i]->x = x;
		// 			myNode[i]->y = y;
		// 		}
		printf("\e[1;1H\e[2J");
		printf("        |     |   y |\n");
		printf("Leecher | %3.0f | %3.0f |\n", leecher->x, leecher->y);
		printf("Mouse   | %3d | %3d |\n", m_x, m_y);
		printf("X   : %d\n", (int)leecher->x - m_x, fabs((int)leecher->x - m_x));
		printf("Y   : %d \t %d\n", (int)leecher->y - m_y, fabs((int)leecher->y - m_y));
		printf("DIM : %d\n", leecher->dim);
							
		if(fabs((int)leecher->x - m_x)  <= leecher->dim &&
				fabs((int)leecher->y - m_y) <= leecher->dim){
					leecher->x = m_x;
					leecher->y = m_y;
		}
		if(fabs((int)seeder->x - m_x)  <= seeder->dim &&
				fabs((int)seeder->y - m_y) <= seeder->dim){
					seeder->x = m_x;
					seeder->y = m_y;
		}
	}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
