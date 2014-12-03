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
	myNode[nbNodes] = new btNode(ofRandom(0,ofGetWidth()),
							ofRandom(0,ofGetHeight()));
	nbNodes = START_NODES_NB;

	seeder = new btNode(ofGetWidth()/4, ofGetHeight()/2);
	leecher = new btNode((ofGetWidth()/4)*3,ofGetHeight()/2);

	packet = new btNode(ofGetWidth()/4, ofGetHeight()/2);
	// packet = new btNode(0, 0);
	packet->dim = 6;

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
	if(packet->x >= leecher->x - 5)
		dest = seeder;
	else if(packet->x <= seeder->x + 5)
		dest = leecher;
	packet->moveTo(dest->x, dest->y);
}

//--------------------------------------------------------------
void ofApp::draw(){
	for(int i = 0; i < nbNodes; i++)
		myNode[i]->draw();

		packet->draw();
		seeder->draw();
		leecher->draw();


}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	switch(key){
		case 'p':
			myNode[nbNodes] = new btNode(ofRandom(0,ofGetWidth()),
									ofRandom(0,ofGetHeight()));
			nbNodes++;
			printf("nbNodes : %d\n", nbNodes);

			break;
		case 'f':
			ofToggleFullscreen();
			break;
		case 'c': //clear
			nbNodes = 0;
			break;
		case '+':
			speedX +=1;
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
void ofApp::mouseDragged(int x, int y, int button){

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
