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
}

void torrentShare::removeNode(int index){
	delete nw[index]; // free memory
	nw[index] = 0; // ptr == 0
}

void torrentShare::sendPacket(){

}



