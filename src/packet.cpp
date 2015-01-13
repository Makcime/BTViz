#include "packet.h"

packet::packet(){
	drawable();
}

packet::packet(point p, point dest, ofColor _color, int speed){
	position = p;
	destination = dest;
	color = _color;

	dim = PACKET_SIZE;

	fillnofill = true;
	isMoving = true;

}

point packet::getPosition(){
	return position;
}

int packet::getPartIndex(){
	return partIndex;
}

void packet::setPartIndex(int i){
	partIndex = i;
}



