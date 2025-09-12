#include <iostream>
#include "singleton.hpp"

using namespace std;

singleton* singleton::instance = nullptr;
mutex singleton::lock;
int singleton::counter = 0;

singleton::singleton(){
    counter++;
    cout<<counter<<endl;
}

singleton* singleton::getInstance(){
    if(instance == nullptr){
        lock.lock();
        if(instance == nullptr){
            instance = new singleton();
        }
        lock.unlock();
    }
    return instance;
}

void singleton::log(string msg){
    cout<<msg<<endl;
    return;
}
