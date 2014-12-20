#include "btNode.h"

btNode::btNode(float _x, float _y, ofColor _color){
	x = _x;
	y = _y;

	color = _color;

	dim = 20;

}

void btNode::update(){

} 

void btNode::draw(){
    // values for R, G, B
    ofSetColor(color);
    ofFill();
    ofCircle(x, y, dim);
    ofSetColor(ofColor::black);
    ofCircle(x, y, dim - 2);
}

void btNode::moveTo(float _xDestiny, float _yDestiny, 
							float speed, float acceleration){
	float a, b, angle, 
			scale_x, scale_y,
			velocity_x, velocity_y;

	a = (_yDestiny - y) / (_xDestiny - x);
	angle = atan(a);

	if((_xDestiny - x) < 0)
		speed *= -1;

	scale_x = cos(angle);
	scale_y = sin(angle);

	velocity_x = (speed * scale_x);
	 velocity_y = (speed * scale_y);

	x += velocity_x;	
	y += velocity_y;	

}


