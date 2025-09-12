#include<bits/stdc++.h>
#include<string>

using namespace std;

class button{
    public:
    virtual void press() = 0;
};

class macButton : public button{
    public:
    void press(){
        cout<<"mac button pressed."<<endl;
    }
};

class winButton : public button{
    public:
    void press(){
        cout<<"windows button pressed."<<endl;
    }
};

class textBox{
    public:
    virtual void showText() = 0;
};

class macTextBox : public textBox{
    public:
    void showText(){
        cout<<"mac textbox pressed."<<endl;
    }
};

class winTextBox : public textBox{
    public:
    void showText(){
        cout<<"windows textbox pressed."<<endl;
    }
};

class osFactory{
    public:
    virtual button* createButton() = 0;
    virtual textBox* createTextBox() = 0;
};

class macFactory : public osFactory{
    public:
    button* createButton(){
        return new macButton();
    }
    textBox* createTextBox(){
        return new macTextBox();
    }
};

class winFactory : public osFactory{
    public:
    button* createButton(){
        return new winButton();
    }
    textBox* createTextBox(){
        return new winTextBox();
    }
};

class mainFactory{
    public:
    osFactory* createFactory(string type){
        if(type == "mac"){
            return new macFactory();
        }else{
            return new winFactory();
        }
    }
};

int main(){
    mainFactory* fact = new mainFactory();
    osFactory* f = fact->createFactory("mac");
    button* b = f->createButton();
    textBox* t = f->createTextBox();
    b->press();
    t->showText();

    return 0;
}

