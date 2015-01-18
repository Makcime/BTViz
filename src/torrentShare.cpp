#include "torrentShare.h"

torrentShare::torrentShare()
{

	// initialize a Torrent file
	for (int i = 0; i < FILE_SIZE; ++i) {
		torrent[i] =
		    ofColor(ofRandom(0, 255), ofRandom(0, 255),
			    ofRandom(0, 255));
	}
	// addSeeder();
}

void torrentShare::update()
{
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

	if (standalone) {
		if (!(cnt++ % (EVENT * RM_RATIO))) {
			int nb = ofRandom(RM_NB);
			for (int i = 0; i < nb; ++i)
				if (nw.size() > MIN_NW_SIZE)
					removeNode();
		}

		else if (!(cnt % (EVENT * ADD_RATIO))) {
			int nb = ofRandom(ADD_NB);
			for (int i = 0; i < nb; ++i)
				addNode();
		}

		else if (cnt % (EVENT * ADD_SEED_RATIO) == 0)
			addSeeder();
	}
	// for each node :
	for (int i = 0; i < nw.size(); i++) {
		nw[i]->update();

		// si j'ai pas recu de paquet depuis un moment
		// j'efface mes demanes pour en emmetre de
		if (!(nw[i]->incNobody() % (EVENT * NOBODY_RATIO))) {
			for (int j = 0; j < requestQueue.size(); ++j) {
				if (requestQueue[j].n == i) {
					requestQueue.erase(requestQueue.
							   begin() + j);
					nw[i]->setDownloading(nw[i]->
							      decrementDownloads
							      () >=
							      MAX_DW);
				}
			}
		}

		// add a request
		if (!nw[i]->onTheMove())
			if (!nw[i]->isDownloading()) {
				nw[i]->request();	// choose a part to dowload
				if ((nw[i]->getPartToRequest()) >= 0) {
					//create a request
					// r.n = nw[i];
					r.n = i;
					r.id = nw[i]->getPartToRequest();

					// add the request to the queue
					requestQueue.push_back(r);
					if (nw[i]->incrementDownloads() >=
					    MAX_DW)
						nw[i]->
						    setDownloading(true);
				}
			}

		int randomNode = ofRandom(0, nw.size());
		// answer the front request 
		// if(requestQueue.size()>0)
		int next_req = 0;
		if (!requestQueue.empty()) {
			for (int j = 0; j < requestQueue.size(); ++j) {
				if (nw[i]->getReached(requestQueue[j].id)) {
					next_req = j;
				}
			}
			// requestQueue.swap(requestQueue.back(), requestQueue.front());
			// iter_swap(requestQueue.front(), requestQueue.back());
			// request r = requestQueue.begin()+next_req; 
			int k = requestQueue[next_req].id;
			int index = requestQueue[next_req].n;
			if (!nw[index]->onTheMove())
				if (!nw[randomNode]->findDownloader(index)) {
					if (!nw[randomNode]->isUploading()) {
						if (nw[randomNode]->
						    getReached(k)) {
							bucket.push_back(new packet(nw[randomNode],	// la source c'estt moi
										    nw[index],	// la destionation est dans la request
										    torrent[k],	// corlor correspond to part id
										    7,	//speed??
										    k,
										    index));
							// requestQueue.pop();
							requestQueue.
							    erase
							    (requestQueue.
							     begin() +
							     next_req);
							nw[randomNode]->
							    addDowloader
							    (index);
							if (nw
							    [randomNode]->
							    incrementUploads
							    () >= MAX_DW)
								nw[randomNode]->setUploading(true);
						}
					}
				}
		}

	}

	// for each packet :
	for (int i = 0; i < bucket.size(); i++) {
		bucket[i]->update();
		if (!bucket[i]->onTheMove()) {
			bucket[i]->reachedDestination();
			bucket.erase(bucket.begin() + i);
		}
	}
}

void torrentShare::draw()
{
	for (int i = 0; i < nw.size(); i++) {
		nw[i]->draw(torrent);
		// nw[i]->draw(&torrent);
	}
	for (int i = 0; i < bucket.size(); i++)
		bucket[i]->draw();
}

void torrentShare::addNode()
{

	nw.push_back(new btNode());

	for (int i = 0; i < FILE_SIZE; ++i) {
		int r = (int) ofRandom(0, 10);
		if (!(r % 6))
			nw[nw.size() - 1]->setReached(i, r);
	}
	updatePositions();
}

void torrentShare::addSeeder()
{
	nw.push_back(new btNode());
	for (int i = 0; i < FILE_SIZE; ++i) {
		nw[nw.size() - 1]->setReached(i, true);
	}
	updatePositions();
}

void torrentShare::removeNode()
{
	if (!nw.empty()) {
		int index = ofRandom(0, nw.size());
		if (nw[index]->checkFull()) {
			nw.erase(nw.begin() + index);	// free memory
			updatePositions();
		}
	}
}

void torrentShare::flipStandalone()
{
	standalone = !standalone;
}

void torrentShare::sendPacket()
{
}

void torrentShare::updatePositions()
{

	printf("%f %f \n", nw[0]->getPosition().x, nw[0]->getPosition().y);
	/*
	   for each node:
	   compute position
	   setDestination

	 */

	//initialize origin at the center of the window
	point origin = { ofGetWidth() / 2, ofGetHeight() / 2 };
	point p;
	float angle;
	float radius = ofGetHeight() / 2 - DEFAULT_SIZE;
	float size = (float) nw.size();


	p.x = radius + origin.x;
	p.y = origin.y;
	nw[0]->setDestination(p);

	for (int i = 1; i < size; ++i) {
		angle = (360.0 / size) * i;
		angle *= (M_PI / 180.0);

		p.x = radius * cos(angle);
		p.y = radius * sin(angle);
		p.x += origin.x;
		p.y += origin.y;

		nw[i]->setDestination(p);
	}
}
