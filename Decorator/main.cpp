#include <iostream>

using namespace std;

class pizza{
private:
    int cost;
public:
    virtual int getCost() = 0;
};

class margerita : public pizza{
private:
    int cost;
public:
    margerita(){
        cost = 100;
    }
    int getCost(){
        return cost;
    }
};

class cheesy : public pizza{
private:
    int cost;
public:
    cheesy(){
        cost = 200;
    }
    int getCost(){
        return cost;
    }
};

class topinsDecorator : public pizza{
private:
    pizza* p;
public:
    virtual int getCost() = 0;
};

class mushroom : public topinsDecorator{
private:
    pizza* p;
public:
    mushroom(pizza* p){
        this->p = p;
    }
    int getCost(){
        return p->getCost() + 30;
    }
};

class jalapino : public topinsDecorator{
private:
    pizza* p;
public:
    jalapino(pizza* p){
        this->p = p;
    }
    int getCost(){
        return p->getCost() + 50;
    }
};


int main(){
    pizza* p1 = new jalapino(new mushroom(new cheesy()));
    int finalCost1 = p1->getCost();
    cout<<finalCost1<<endl;
    pizza* p2 = new jalapino(new mushroom(new margerita()));
    int finalCost2 = p2->getCost();
    cout<<finalCost2<<endl;

    return 0;
}
