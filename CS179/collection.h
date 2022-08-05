#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "document.h"

using namespace std;

class Collection
{
private:
    std::string name;
    std::string filePath;
    int size;
    std::vector<Dock*> documents;
public:
    void add (Dock*);
    void remove (std::string);
    void print ();
    void setName (std::string);
    std::string getPath ();
    void setPath (std::string);
};

//add a document to this collection
void Collection::add (Dock* doc){
    this->documents.push_back(doc);
}

//removes a doc from vector by matching path names
void Collection::remove (std::string path){
    for (int i = 0; i < this->documents.size(); i++){
        if (this->documents.at(i)->getPath() == path){
            this->documents.erase(this->documents.begin()+i);
        }
    }
}

//prints the jsons that are in this collection
void Collection::print(){
    for (int i = 0; i < this->documents.size(); i++){
        std::cout << documents.at(i)->getPath() << std::endl;
    }
}

//set the name of this collection
void Collection::setName(std::string n){
    this->name = n;
}

//set path of json file
void Collection::setPath(std::string path){
    this->filePath = "/" + path;
}

//get the path of json file
std::string Collection::getPath(){
    return this->filePath;
}
