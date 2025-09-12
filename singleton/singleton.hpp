#ifndef singleton_h
#define singleton_h

#include <string>
#include<mutex>

using namespace std;

class singleton{
    private:
        static singleton* instance;
        static int counter;
        static mutex lock;
        singleton ();
        singleton (singleton&);
        singleton operator= (singleton&);

    public:
        static singleton* getInstance();
        void log(string message);
};


#endif