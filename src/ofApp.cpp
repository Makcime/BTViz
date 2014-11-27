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
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	for(int i = 0; i < nbNodes; i++)
		myNode[i]->draw();
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
