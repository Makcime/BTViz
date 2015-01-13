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
	printf("test\n");

	// add a node to network
	nw.push_back(new btNode(ofGetWidth()/4, 
								ofGetHeight()/2, 
									ofColor::red));

	packet = new btNode(nw[0]->x+1, nw[0]->y, 5, ofColor::white, true);

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

	for(int i=0; i<nw.size() ; i++)
		nw[i]->draw();
	packet->draw();

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	int last, i;
	switch(key){
		case 'p':
			nw.push_back(new btNode();
			last = nw.size() - 1;
			nbNodes++;
			break;
		case 'f':
			ofToggleFullscreen();
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
	for(int i(0) ; i<nw.size() ; ++i){
		delete nw[i]; // free memory
		nw[i] = 0; // ptr == 0
	}
}