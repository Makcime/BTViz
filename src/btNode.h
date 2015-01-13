#ifndef _OF_NODE // if this class hasn't been defined, the program can define it
#define _OF_NODE // by using this if statement you prevent the class to be called more
                 // than once which would confuse the compiler
 
class btNode : drawable {

 
    public: // place public functions or variables declarations here
 
    private: // place private functions or variables declarations here
        using drawable::drawable;
 
}; // dont't forget the semicolon!!
 
#endif