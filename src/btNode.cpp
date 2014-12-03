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

void btNode::moveTo(int _xDestiny, int _yDestiny){
    x += ( _xDestiny - x )*0.1;
    y += ( _yDestiny - y )*0.1;
}