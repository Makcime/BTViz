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
	/*
	update :
	for each node :
		update drawable
		ask for a part if not already downloading one
		upload the font part in queu if have and not already uploading
	
	for each packet:
		update drawable
		delete from bucket if destination is reached

	*/
	request r;

	// for each node :
	for(int i=0; i<nw.size() ; i++){
		nw[i]->update();
	
		// add a request
		if(!nw[i]->isDownloading()){
			nw[i]->request(); // choose a part to dowload
			if((nw[i]->getPartToRequest()) >= 0){
				//create a request
				r.n = nw[i];
				r.id = nw[i]->getPartToRequest();

				// add the request to the queue
				requestQueue.push(r);
			}
		}

		// answer the front request 
		// if(requestQueue.size()>0)
		if(!requestQueue.empty()){
			if (!nw[i]->isUploading()){
				if(nw[i]->getReached(requestQueue.front().id)){
					bucket.push_back(new packet(
						nw[i], // la source c'estt moi
					 	requestQueue.front().n, // la destionation est dans la request
					 	torrent[requestQueue.front().id], // corlor correspond to part id
					 	7, //speed??
					 	requestQueue.front().id));
					requestQueue.pop();
				}
			// point p, point dest, ofColor _color, int speed
			}
		}

	}

	// for each packet :
	for(int i=0; i<bucket.size() ; i++){
		bucket[i]->update();
		printf("%d --> %d\n", i, bucket[i]->onTheMove());
		if(!bucket[i]->onTheMove()){
			bucket[i]->reachedDestination();
			bucket.erase(bucket.begin()+i);
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



