#include<bits/stdc++.h>
#include<string>

using namespace std;

class vehicle{
    public:
    static vehicle* createVehicle();
};

class bike: public vehicle{
    public:
    bike(){
        cout<<"bike created"<<endl;
    }
    static vehicle* createVehicle(){
        return new bike();
    }
};

class car: public vehicle{
    public:
    car(){
        cout<<"car created"<<endl;
    }
    static vehicle* createVehicle(){
        return new car();
    }
};

class factory{
    public:
    static vehicle* makeVehicle(string type){
        if(type == "bike"){
            return bike::createVehicle();
        }else{
            return car::createVehicle();
        }
    }
};


int main(){
    factory* fact = new factory();
    vehicle* v1 = fact->makeVehicle("bike");
    // v1->createVehicle();

    vehicle* v2 = fact->makeVehicle("car");
    // v2->createVehicle();


    return 0;
}