#include "torrentShare.h"

torrentShare::torrentShare(){
	
	// initialize a Torrent file
	nw.push_back(new btNode());

	for (int i = 0; i < FILE_SIZE; ++i)
	{
		torrent[i] =  ofColor(ofRandom(0,255),ofRandom(0,255),ofRandom(0,255));
		nw[0]->setReached(i, true);
	}

}

void torrentShare::update(){
	for(int i=0; i<nw.size() ; i++){
		nw[i]->update();

	}

	for(int i=0; i<bucket.size() ; i++){
		bucket[i]->update();
		if(bucket[i]->onTheMove());
	}
}

void torrentShare::draw(){
	for(int i=0; i<nw.size() ; i++){
		nw[i]->draw(torrent);
		// nw[i]->draw(&torrent);
	}
	for(int i=0; i<bucket.size() ; i++)
		bucket[i]->draw();
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

