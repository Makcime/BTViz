#include "torrentShare.h"

torrentShare::torrentShare(){
	
	// initialize a Torrent file
	for (int i = 0; i < FILE_SIZE; ++i)
	{
		torrent[i] =  ofColor(ofRandom(0,255),ofRandom(0,255),ofRandom(0,255));
	}
	addSeeder();
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
		if(!nw[i]->onTheMove())	
		if(!nw[i]->isDownloading()){
			nw[i]->request(); // choose a part to dowload
			if((nw[i]->getPartToRequest()) >= 0){
				//create a request
				// r.n = nw[i];
				r.n = i;
				r.id = nw[i]->getPartToRequest();

				// add the request to the queue
				requestQueue.push(r);
				if(nw[i]->incrementDownloads() >= MAX_DW)
					nw[i]->setDownloading(true);
			}
		}
		// answer the front request 
		// if(requestQueue.size()>0)
		if(!requestQueue.empty()){
			int k = requestQueue.front().id;
			int index = requestQueue.front().n;
			if(!nw[index]->onTheMove())
			if(!nw[i]->findDownloader(index)){
				if (!nw[i]->isUploading()){
					if(nw[i]->getReached(k)){
						bucket.push_back(new packet(
							nw[i], // la source c'estt moi
						 	nw[index], // la destionation est dans la request
						 	torrent[k], // corlor correspond to part id
						 	7, //speed??
						 	k,
						 	index));
						requestQueue.pop();
						nw[i]->addDowloader(index);
						if(nw[i]->incrementUploads() >= MAX_DW)
							nw[i]->setUploading(true);	
					}
				}
			}
		}

	}

	// for each packet :
	for(int i=0; i<bucket.size() ; i++){
		bucket[i]->update();
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
	updatePositions();
}

void torrentShare::addSeeder(){
	nw.push_back(new btNode());
	for (int i = 0; i < FILE_SIZE; ++i)
	{
		nw[nw.size()-1]->setReached(i, true);
	}
	updatePositions();
}

void torrentShare::removeNode(int index){
	delete nw[index]; // free memory
	nw[index] = 0; // ptr == 0
}

void torrentShare::sendPacket(){

}

void torrentShare::updatePositions(){

	/*
	for each node:
		compute position
		setDestination

	*/

	//initialize origin at the center of the window
	point origin = {ofGetWidth()/2, ofGetHeight()/2}; 
	point p;
	float angle;
	float radius = ofGetHeight()/2 - (3*DEFAULT_SIZE/4);
	float size = (float) nw.size();

	for (int i =0; i < size; ++i)
	{
		angle = ( 360.0 / size ) * i;
		angle *= (M_PI / 180.0);

		p.x = radius * cos(angle);
		p.y = radius * sin(angle);
		p.x += origin.x;
		p.y += origin.y;

		nw[i]->setDestination(p);
	}
}



