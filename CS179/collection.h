#pragma once

#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
#include "rapidjson/filereadstream.h"
#include "rapidjson/filewritestream.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;
using namespace rapidjson;

class Collection{
private:
    string name;
    string path;
    vector<Document*> documents;
public:
    Collection();
    Collection(string fileName, string dbPath) {this->path = dbPath+fileName; this->name = fileName;}
    string getPath(){return this->path;}
    string getName(){return this->name;}
    void addDoc(Document*);
    Document* getDocAt(int);
    vector<Document*> getDocs() {return this->documents;}
};

Collection::Collection(){}

void Collection::addDoc(Document* d){
    this->documents.push_back(d);
}

Document* Collection::getDocAt(int i){
    return this->documents.at(i);
}