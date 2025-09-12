#ifndef OBSERVER_H
#define OBSERVER_H
#include <string>
#include <list>
using namespace std;

class subscriber{
    private:
    public:
        virtual void notify(string msg) = 0;
};

class user : public subscriber{
    private:
        int id;
    public:
       user(int id);
       void notify(string msg);
};

class group{
    private:
        list<subscriber*> subs;
    public:
        void subscribe (subscriber* id);
        void unsubscribe(subscriber* id);
        void notify(string msg);
};
#endif