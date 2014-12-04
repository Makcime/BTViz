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

void btNode::moveTo(float _xDestiny, float _yDestiny, float xSpeed){
	float a, b;

	if((_xDestiny - x) < 0)
		xSpeed *= -1;

	if (x == _xDestiny){}
	else{
		a = (_yDestiny - y) / (_xDestiny - x);
		b = y - a * x;
	}	
	x += xSpeed;
    // x +=  _xDestiny - x *0.01;
	y = a * x + b; 
    // y += ( _yDestiny - y )*0.01;
}


