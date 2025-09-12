#include <iostream>
#include <thread>
#include "singleton.hpp"

using namespace std;

void func1(){
    singleton* s1 = singleton::getInstance();
    s1->log("hii 1");
}

void func2(){
    singleton* s2 = singleton::getInstance();
    s2->log("hii 2");
}

int main(){    
    thread t1(func1);
    thread t2(func2);

    t1.join();
    t2.join();

    return 0;
}