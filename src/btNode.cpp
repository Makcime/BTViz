/**
 * @file btNode.cpp
 * @brief implementation of btNode class
 *
 * A class wich manage a node into a torrent share.
 *
 * @author Marlier Maxime <marlier.maxime@gmail.com>
 *
 **/

#include "btNode.h"

btNode::btNode()
{
    drawable();
    for (int i = 0; i < FILE_SIZE; ++i)
        part_reached[i] = false;
    speed = 3;
    downloading = false;
    uploading = false;
}

btNode::btNode(float _x, float _y, ofColor _color)
{
    position.x = _x;
    position.y = _y;
    color = _color;

    dim = DEFAULT_SIZE;
    fillnofill = false;
    destination = position;
    isMoving = false;


    // initialize part_reached table
    for (int i = 0; i < FILE_SIZE; ++i)
        part_reached[i] = false;
}

btNode::btNode(point p, int _dim, ofColor _color, bool fill)
{
    // drawable(p, _dim, _color, fill);
    position = p;
    color = _color;

    dim = _dim;

    fillnofill = fill;
    destination = position;
    isMoving = false;
}

void btNode::draw()
{
    drawable::draw();
}

void btNode::draw(ofColor * file)
{

    drawable::draw();
    for (int i = 0; i < FILE_SIZE; ++i)
    {
        if (part_reached[i])
        {
            ofNoFill();
            ofSetColor(file[i]);
            ofCircle(position.x, position.y, dim - 2 * i);
        }
    }
}


point btNode::getPosition()
{
    return position;
}

bool btNode::getReached(int index)
{
    if (index < FILE_SIZE)
        return part_reached[index];
}

void btNode::setReached(int index, bool val)
{
    part_reached[index] = val;
}

void btNode::request()
{
    int i = -1;
    int count = 10;

    checkFull();

    if (!isFull)
    {
        do
        {
            i = (int) ofRandom(0, FILE_SIZE);	/// -1 ?
        }
        while (part_reached[i] && --count > 0);

        if (part_reached[i])
            i = -1;
    }

    partToRequest = i;
}

int btNode::getPartToRequest()
{
    return partToRequest;
}

bool btNode::checkFull()
{

    isFull = true;
    for (int i = 0; i < FILE_SIZE; ++i)
    {
        if (!part_reached[i])
        {
            isFull = false;
        }
    }

    return isFull;
}

bool btNode::isDownloading()
{
    return downloading;
}

void btNode::setDownloading(bool state)
{
    downloading = state;
}

bool btNode::isUploading()
{
    return uploading;
}

void btNode::setUploading(bool state)
{
    uploading = state;
}

int btNode::incrementDownloads()
{
    return ++downloads;
}

int btNode::decrementDownloads()
{
    return --downloads;
}

int btNode::incrementUploads()
{
    return ++uploads;
}

int btNode::decrementUploads()
{
    return --uploads;
}

void btNode::addDowloader(int i)
{
    nownDownloaders.push_back(i);
}

void btNode::removeDowloader(int item)
{
    vector < int >::iterator index = find(nownDownloaders.begin(),
                                          nownDownloaders.end(),
                                          item);
    nownDownloaders.erase(index);
}

bool btNode::findDownloader(int item)
{
    return find(nownDownloaders.begin(),
                nownDownloaders.end(), item) != nownDownloaders.end();
}

int btNode::incNobody()
{
    return nobody++;
}
