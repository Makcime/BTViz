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
	request r;

	// for each node :
	for(int i=0; i<nw.size() ; i++){
		nw[i]->update();
		nw[i]->request();

		// add a request
		if(!nw[i]->isDowloading()) 
			if((nw[i]->getPartToRequest()) != 0){
				r.n = nw[i];
				r.id = nw[i]->getPartToRequest();
				requestQueue.push(r);
				nw[i]->setDowloading(true);
			}

		// answer a request
		if(!requestQueue.empty())
			if(nw[i]->getReached(requestQueue.front().id)){
				bucket.push_back(new packet(
					nw[i]->getPosition(),
				 	requestQueue.front().n->getPosition(),
				 	torrent[requestQueue.front().id],
				 	5));
				requestQueue.pop();
			}
			// point p, point dest, ofColor _color, int speed

	}

	for(int i=0; i<bucket.size() ; i++){
		bucket[i]->update();
		if(!bucket[i]->onTheMove()){
			// delete bucket[i]; // free memory
			// bucket[i] = 0; // ptr == 0
		}
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



