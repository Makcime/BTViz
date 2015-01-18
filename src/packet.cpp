#include "packet.h"

packet::packet()
{
    drawable();
}

packet::packet(point p, point dest, ofColor _color, int _speed)
{
    position = p;
    destination = dest;
    color = _color;

    dim = PACKET_SIZE;

    fillnofill = true;
    isMoving = true;

    // second = new drawable(position, dim, color, true); // constructor - used to initialize an object, if no properties are passed
    // second.isMoving = false;

}

void packet::update()
{
    drawable::update();
    destination = leecher->getPosition();
}

// packet(point p, btNode * dest, ofColor _color, int speed);
packet::packet(btNode * src, btNode * dest, ofColor _color, int _speed,
               int id, int index)
{
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

void packet::draw()
{


    if (fillnofill)
        ofFill();
    else
        ofNoFill();

    ofSetColor(color);
    ofCircle(position.x, position.y, dim);

    // if(second->getPosition().x - position.x > 10)
    //  second->setDestination(destination);

    // ofPolyline line;

    // float angle = 0;
    // while (angle < TWO_PI ) {
    //     // line.curveTo(100*cos(angle), 0, 100*sin(angle));
    //     // line.curveTo(300*cos(angle), 300, 300*sin(angle));
    //     line.curveTo(cos(angle), 0,sin(angle));
    //     line.curveTo(cos(angle), 10,sin(angle));
    //     angle += TWO_PI / 30;
    // }
    //    line.draw();
    // line.close(); // close the shape
}


// point packet::getPosition(){
//      return position;
// }

int packet::getPartIndex()
{
    return partIndex;
}

void packet::setPartIndex(int i)
{
    partIndex = i;
}

void packet::reachedDestination()
{
    leecher->setReached(partIndex, true);

    seeder->decrementUploads();
    seeder->setUploading(false);
    seeder->removeDowloader(downloaderIndex);

    leecher->decrementDownloads();
    leecher->setDownloading(false);

    leecher = NULL;
    seeder = NULL;
}
