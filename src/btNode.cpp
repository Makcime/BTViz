#include "btNode.h"

btNode::btNode(float _x, float _y){
	x = _x;
	y = _y;

	dim = 20;

}

void btNode::update(){

}

void btNode::draw(){
    // values for R, G, B
    ofSetColor(120,120,120);
    ofCircle(x, y, dim);
}