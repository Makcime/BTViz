#include "torrentShare.h"

torrentShare::torrentShare(){

	// initialize part_reached table
	for (int i = 0; i < FILE_SIZE; ++i)
		part_reached[i] = false;

	
}


void torrentShare::update(){
	for(int i=0; i<nw.size() ; i++)
		nw[i]->update();
	for(int i=0; i<packet.size() ; i++)
		packet[i]->update();
}

void torrentShare::draw(){
	for(int i=0; i<nw.size() ; i++)
		nw[i]->draw();
	for(int i=0; i<packet.size() ; i++)
		packet[i]->draw();
}

void torrentShare::addNode(){
	nw.push_back(new btNode());
}

void torrentShare::removeNode(int index){
	delete nw[index]; // free memory
	nw[index] = 0; // ptr == 0
}

void torrentShare::sendPacket(){

}

