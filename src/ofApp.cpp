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
	nw.push_back(new btNode(ofGetWidth()/4, 
								ofGetHeight()/2, 
									ofColor::red));
	nw[0]->isSeeder = true;

	for(int i(0) ; i<FILE_SIZE ; ++i){
		nw[0]->part_reached[i] = true;
	 	torrent[i] = new ofColor(ofRandom(0,255),
	 								ofRandom(0,255),
	 									ofRandom(0,255));
	}
	dest = nw[0];
	packet = new btNode(nw[0]->x+1, nw[0]->y, ofColor::white);
	// packet->dim = 10;
	// packet = new btNode((ofGetWidth()/4)*3, 
	// 			ofGetHeight()/2, ofColor::white);


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

	//*/
	if (speedX){
		packet->moveTo(dest->x, dest->y, speedX, 0);
		if (fabs(packet->x - dest->x) < dest->dim/2){
			speedX = 0;	
			// delete packet;
			packet->color = ofColor::black;
			// nw[1]->part_reached[part] = true;
			dest->part_reached[part] = true;
		}
	}
		


}

//--------------------------------------------------------------
void ofApp::draw(){

	for(int i=0; i<nw.size() ; i++)
		nw[i]->draw(torrent);
	packet->draw(torrent);

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	int last, i;
	switch(key){
		case 'p':
			nw.push_back(new btNode((ofGetWidth()/4)*3, 
				ofGetHeight()/2, ofColor::white));
			last = nw.size() - 1;
			// for(i = 0 ; i<FILE_SIZE ; ++i)
			// 	nw[last]->part_reached[i] = true;
			nw[last]->isSeeder = true;
			printf("%d\n", last );
			dest = nw[last];
			packet->dim = 5;
			packet->color = *torrent[part];
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
			// packet = new btNode(nw[0]->x+1, nw[0]->y, ofColor::red);
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
	for(int i(0) ; i<nw.size() ; ++i){
		delete nw[i]; // free memory
		nw[i] = 0; // ptr == 0
	}
}