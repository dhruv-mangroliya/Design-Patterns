#include "Observer.hpp"
#include<iostream>
using namespace std;

user::user(int id){
    this->id = id;
};

void user::notify(string msg){
    cout<<"Message received to user: "<<id<<" is ->"<<msg<<"."<<endl;
}

void group::subscribe(subscriber* id){
    subs.push_back(id);
}

void group::unsubscribe(subscriber* id){
    subs.remove(id);
}

void group::notify(string msg){
    for(auto u : subs){
        u->notify(msg);
    }
}