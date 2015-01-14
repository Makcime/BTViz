#include "packet.h"

packet::packet(){
	drawable();
}

packet::packet(point p, point dest, ofColor _color, int _speed){
	position = p;
	destination = dest;
	color = _color;

	dim = PACKET_SIZE;

	fillnofill = true;
	isMoving = true;

}

// packet(point p, btNode * dest, ofColor _color, int speed); 
packet::packet(btNode *src, btNode *dest, ofColor _color, int _speed, int id, int index){
	seeder = src;
	leecher = dest;

	position = seeder->getPosition();
	destination = leecher->getPosition();
	
	color = _color;

	speed = _speed;

	dim = PACKET_SIZE;
	partIndex = id;

	downloaderIndex = index;

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

void packet::reachedDestination(){
	leecher->setReached(partIndex, true);

	seeder->decrementUploads();
	seeder->setUploading(false);
	seeder->removeDowloader(downloaderIndex);

	leecher->decrementDownloads();
	leecher->setDownloading(false);

	leecher = NULL;
	seeder = NULL;
}



