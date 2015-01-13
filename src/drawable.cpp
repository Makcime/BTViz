#include "drawable.h"

int drawable::draggable = 0;

drawable::drawable(int _x, int _y, int _dim, ofColor _color, bool fill){
	position.x = _x;
	position.y = _y;
	color = _color;
	dim = _dim;
	fillnofill = fill;
	destination = position;
	isMoving = false;

}

drawable::drawable(int _x, int _y, ofColor _color){
	position.x = _x;
	position.y = _y;
	color = _color;

	dim = DEFAULT_SIZE;
	fillnofill = false;
	destination = position;
	isMoving = false;

}

drawable::drawable(point p, int _dim, ofColor _color, bool fill){
	position = p;
	color = _color;

	dim = _dim;

	fillnofill = fill;
	destination = position;
	isMoving = false;
}


drawable::drawable(){
	position.x = ofRandom(0, ofGetWidth());
	position.y = ofRandom(0, ofGetHeight());
	color = ofColor::white;
	dim = DEFAULT_SIZE;
	fillnofill = false;
	destination = position;
	isMoving = false;

}

void drawable::update(){
	if(isMoving){
		moveTo(10);
		isMoving = comparePosition(destination, position);	
	}
}

bool drawable::comparePosition(point dest, point pos){
	// return true if current position is in area of the destination
	int epsilon = EPSILON;

	int deltaX = dest.x - pos.x;
	int deltaY = dest.y - pos.y;

	return(fabs(deltaX) < epsilon && fabs(deltaY) < epsilon);
}

void drawable::draw(){

    if(fillnofill)
	    ofFill();
    else
    	ofNoFill();

	ofSetColor(color);
    ofCircle(position.x, position.y, dim);
    
}

void drawable::moveTo(float _xDestiny, float _yDestiny, 
							float speed, float acceleration){
	// float a, b, angle, 
	// 		scale_x, scale_y,
	// 		velocity_x, velocity_y;

	// a = (_yDestiny - y) / (_xDestiny - x);
	// angle = atan(a);

	// if((_xDestiny - x) < 0)
	// 	speed *= -1;

	// scale_x = cos(angle);
	// scale_y = sin(angle);

	// velocity_x = (speed * scale_x);
	//  velocity_y = (speed * scale_y);

	// x += velocity_x;
	// y += velocity_y;

}

void drawable::moveTo(float speed){
	float a, b, angle, 
			scale_x, scale_y,
			velocity_x, velocity_y;

	a = (destination.y - position.y) / (destination.x - position.x);
	angle = atan(a);

	if((destination.x - position.x) < 0)
		speed *= -1;

	scale_x = cos(angle);
	scale_y = sin(angle);

	velocity_x = (speed * scale_x);
	 velocity_y = (speed * scale_y);

	position.x += velocity_x;
	position.y += velocity_y;

}

void drawable::setDraggable(int index){
	draggable = index;
}

int drawable::isDraggable(){
	return draggable;
}

bool drawable::inArea(point p){
	return (fabs((int)this->position.x - p.x)  <= this->dim &&
				fabs((int)this->position.y - p.y) <= this->dim);
}

void drawable::setPosition(int x, int y){
	this->position.x = x;
	this->position.y = y;	
}



