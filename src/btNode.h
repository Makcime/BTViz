#ifndef _OF_NODE // if this class hasn't been defined, the program can define it
#define _OF_NODE // by using this if statement you prevent the class to be called more
                 // than once which would confuse the compiler

#include "drawable.h"
#include <vector> 
#include <algorithm>

class btNode: public drawable {

 
public: // place public functions or variables declarations here
    btNode(); 
    btNode(float _x, float _y, ofColor _color); 
    btNode(point p, int _dim, ofColor _color, bool fill); // constructor - used to initialize an object, if no properties are passed

    void draw();
    void draw(ofColor *file);

    point getPosition();

    bool getReached(int index);
    void setReached(int index, bool val);

    void request();
    int getPartToRequest();

    bool isDownloading();
    void setDownloading(bool state);

    bool isUploading();
    void setUploading(bool state);
	
	bool checkFull();

    int incrementDownloads();
    int decrementDownloads();

    int incrementUploads();
    int decrementUploads();

    void addDowloader(int i);
    void removeDowloader(int item);
    bool findDownloader(int item);

    int incNobody();

    
private: // place private functions or variables declarations here
        // using drawable::drawable;
    bool part_reached[FILE_SIZE];
    int partToRequest = 0;
    bool isFull = false;

    vector<int> nownDownloaders;

    bool downloading = false;
    bool uploading = false;

    int uploads = 0;
    int downloads = 0;
    int nobody = 0;
 
}; // dont't forget the semicolon!!
 
#endif