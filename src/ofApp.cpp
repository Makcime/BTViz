#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

	ofBackground(0,0,0);
	ofSetFrameRate(60);
	ofSetWindowTitle("BTViz");
	ofEnableSmoothing();
	ofNoFill();

	nbNodes = START_NODES_NB;

	// add a node to network
	share = new torrentShare();
	// share2 = new torrentShare();

	// mySound.loadSound("test.mp3");  
	// mySound.play();  

}

//--------------------------------------------------------------
void ofApp::update(){
	share->update();
	// share2->update();
	// for(int i=0; i<nw.size() ; i++)
	// 	nw[i]->update();
	// packet->update();
}

//--------------------------------------------------------------
void ofApp::draw(){

	share->draw();
	// share2->draw();
	// for(int i=0; i<nw.size() ; i++)
	// 	nw[i]->draw();
	// packet->draw();

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	int last, i;
	switch(key){
		case 'p':
			share->addNode();
			break;
		case 's':
			share->addSeeder();
			break;
		case 'f':
			ofToggleFullscreen();
			break;
		case 'r':
			share->removeNode();
			break;
		case 'c': //clear
			freeVectors();
			nbNodes = 0;
			break;
		case '+':
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

	point p = {m_x, m_x};

	// // if nobody is beeing dragged
	// if(button == 0 && dragged == 0)
	// 	for(int i=0; i<nw.size() ; i++)
	// 		if(nw[i]->inArea(p)){
	// 			nw[i]->setPosition(m_x, m_y);
	// 		}


	// else if(button == 0){
	// 	int i = dragged;
	// 	if(nw[i]->inArea(p)){
	// 		nw[i]->setPosition(m_x, m_y);
	// 		}
	// 		else
	// 			dragged = 0;
	// }
	// else
	// 	dragged = 0;
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

//--------------------------------------------------------------
  void ofApp::freeVectors(){
	// for(int i(0) ; i<nw.size() ; ++i){
	// 	delete nw[i]; // free memory
	// 	nw[i] = 0; // ptr == 0
	// }
}