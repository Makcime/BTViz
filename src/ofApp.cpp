/**
 * @file ofApp.cpp
 * @brief 
 *
 * A class wich manage creation of a torrentShare
 * will manage events like key pressed, draw and update callback functions, 
 *
 * @author Marlier Maxime <marlier.maxime@gmail.com>
 *
 **/

 #include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{

    ofBackground(0, 0, 0);
    ofSetFrameRate(60);
    ofSetWindowTitle("BTViz");
    ofEnableSmoothing();
    ofNoFill();

    // add a node to network
    share = new torrentShare();
}

//--------------------------------------------------------------
void ofApp::update()
{
    share->update();
}

//--------------------------------------------------------------
void ofApp::draw()
{
    share->draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{
    int last, i;
    switch (key)
    {
    case 'p':
        share->addNode();
        break;
    case 's':
        share->addSeeder();
        break;
    case 'f':
        ofToggleFullscreen();
        break;
    case 'r':
        share->removeNode();
        break;
    case 'a':
        share->flipStandalone();
        break;
    default:
        break;
    }

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key)
{

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y)
{

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int m_x, int m_y, int button)
{

    point p = { m_x, m_x };

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button)
{

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button)
{

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h)
{

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg)
{

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo)
{

}
