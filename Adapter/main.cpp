#include <bits/stdc++.h>
#include <string>

using namespace std;

class XMLData{
private:
    string xmldata;
public:
    XMLData(string data){
        this->xmldata = data;
    }
    string getdata(){
        return xmldata;
    }
};

class JSONData{
    string jsondata;
public:
    JSONData(string data){
        this->jsondata = data;
    }
    string getdata(){
        return jsondata;
    }
};

class processor{
    XMLData* xmldata;
public:
    processor(){
        
    }
    processor(XMLData* data){
        this->xmldata = data;
    }

    virtual void processData(){
        cout<<"processing xml data and data is: "<<xmldata->getdata()<<endl;
    }
};

class Adapter : public processor{
    JSONData* jsondata;
public:
    Adapter(JSONData* data){
        this->jsondata = data;
    }

    void processData() override {
        cout<<"converting json data into xml data and json data is :"<<jsondata->getdata()<<endl;
        XMLData* xmldata = new XMLData("Converted data");
        processor* pro = new processor(xmldata);
        pro->processData();
    }
};

int main(){
    XMLData* data1 = new XMLData("XML Data input");
    JSONData* data2 = new JSONData("JSON Dat input");
    
    // Processor pro = new Processor(data1); Problem here is we have JSONData not xml data to process, so we need adapter.
    processor* pro = new Adapter(data2);
    pro->processData();

    return 0;
}