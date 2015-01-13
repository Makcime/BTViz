#include "btNode.h"

// int btNode::draggable = 0;

btNode::btNode(){
	drawable();
}

btNode::btNode(int _x, int _y, ofColor _color){
	// drawable(_x, _y, _color);
	position.x = _x;
	position.y = _y;
	color = _color;

	dim = DEFAULT_SIZE;
	fillnofill = false;
	destination = position;
	isMoving = false;
}

btNode::btNode(point p, int _dim, ofColor _color, bool fill){
	// drawable(p, _dim, _color, fill);
	position = p;
	color = _color;

	dim = _dim;

	fillnofill = fill;
	destination = position;
	isMoving = false;
}

point btNode::getPosition(){
	return position;
}

// void btNode::update(){

// }


// void btNode::draw(ofColor* file[]){
//     // values for R, G, B
//     ofNoFill();
// 	ofSetColor(color);
//     ofCircle(x, y, dim);

//     if(this->isSeeder)
// 		    for (int i = 0; i < FILE_SIZE; ++i)
// 		    {
// 		    	if(part_reached[i]){
// 			    	ofSetColor(*file[i]);
// 			    	ofCircle(x, y, dim-i*2);
// 		    	}
// 		    }
//     // ofSetColor(ofColor::black);
//     // ofCircle(x, y, dim - 2);
// }

// void btNode::moveTo(float _xDestiny, float _yDestiny, 
// 							float speed, float acceleration){
// 	float a, b, angle, 
// 			scale_x, scale_y,
// 			velocity_x, velocity_y;

// 	a = (_yDestiny - y) / (_xDestiny - x);
// 	angle = atan(a);

// 	if((_xDestiny - x) < 0)
// 		speed *= -1;

// 	scale_x = cos(angle);
// 	scale_y = sin(angle);

// 	velocity_x = (speed * scale_x);
// 	 velocity_y = (speed * scale_y);

// 	x += velocity_x;
// 	y += velocity_y;

// }

// void btNode::setDraggable(int index){
// 	draggable = index;
// }

// int btNode::isDraggable(){
// 	return draggable;
// }

// bool btNode::inArea(int x, int y){
// 	return (fabs((int)this->x - x)  <= this->dim &&
// 				fabs((int)this->y - y) <= this->dim);
// }

// void btNode::setPosition(int x, int y){
// 	this->x = x;
// 	this->y = y;	
// }



