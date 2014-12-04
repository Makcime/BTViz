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

void btNode::moveTo(float _xDestiny, float _yDestiny, 
							float speed, float acceleration){
	float a, b, angle;

	a = (_yDestiny - y) / (_xDestiny - x);
	angle = atan(a);

	if((_xDestiny - x) < 0)
		speed *= -1;

	float scale_x = cos(angle);
	float scale_y = sin(angle);

	float velocity_x = (speed * scale_x);
	float velocity_y = (speed * scale_y);

	x += velocity_x;	
	y += velocity_y;	

	// if (x == _xDestiny){}
	// else{
	// 	b = y - a * x;
	// }	
	// x += xSpeed;
    // x +=  _xDestiny - x *0.01;
	// y = a * x + b; 
    // y += ( _yDestiny - y )*0.01;
}


