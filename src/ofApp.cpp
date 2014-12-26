#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

	ofBackground(0,0,0);
	ofSetFrameRate(60);
	ofSetWindowTitle("BTViz");
	ofEnableSmoothing();
	ofNoFill();

	nbNodes = START_NODES_NB;

	// create the seeder
	printf("%d\n", nw.size() );
	nw.push_back(new btNode(ofGetWidth()/4, ofGetHeight()/2, ofColor::red));
	printf("%d\n", nw.size() );

}

//--------------------------------------------------------------
void ofApp::update(){

	/*
	float epsilon = speedX / 2;
	if(packet->x < leecher->x + epsilon && packet->x > leecher->x - epsilon &&
		packet->y < leecher->y + epsilon && packet->y > leecher->y - epsilon)
		dest = seeder;
	else if(packet->x < seeder->x + epsilon && packet->x > seeder->x - epsilon&&
		packet->y < seeder->y + epsilon && packet->y > seeder->y - epsilon)
		dest = leecher;

	packet->moveTo(dest->x, dest->y, speedX, 0);
	//*/
}

//--------------------------------------------------------------
void ofApp::draw(){

	for(int i=0; i<nw.size() ; i++)
		nw[i]->draw();

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	switch(key){
		case 'p':
			nw.push_back(new btNode((ofGetWidth()/4)*3, ofGetHeight()/2, ofColor::white));
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

	if(button == 0 && btNode::isDraggable() == 0)
		for(int i=0; i<nw.size() ; i++)
			if(nw[i]->inArea(m_x, m_y)){
				nw[i]->setPosition(m_x, m_y);
			}
	else if(button == 0){
		int i = btNode::isDraggable();
		if(nw[i]->inArea(m_x, m_y)){
			nw[i]->setPosition(m_x, m_y);
			btNode::setDraggable(i);
			}
	}
	else
		btNode::setDraggable(0);
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
	for(int i=0 ; i<nw.size() ; i++){
		delete nw[i]; // free memory
		nw[i] = 0; // ptr == 0
	}
}