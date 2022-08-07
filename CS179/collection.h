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
    Collection();
    Collection(std::string collName) { this->name = collName;}
    void add (Dock*);
    void remove (std::string);
    void remove (int);
    void print ();
    void setName (std::string);
    std::string getPath ();
    void setPath (std::string);
    std::string getName();
    std::vector<Dock*> getDocuments() {return this->documents; }
    Dock* getDocuments(int);
};


//Default Constructor
Collection::Collection(){
    name = "";
    filePath = "";
    size = 0;
}

//add a document to this collection
void Collection::add (Dock* doc){
    this->documents.push_back(doc);
}

//removes a doc from vector by matching path names
void Collection::remove (std::string path){
    for (int i = 0; i < this->documents.size(); i++){
        if (this->documents.at(i)->getPath() == path){
            this->documents.erase(this->documents.begin()+i);
            std::cout << "Sucessfully removed" << std::endl;
        }
    }
}

//removes a doc from vector by index
void Collection::remove (int i){
    this->documents.erase(this->documents.begin()+i);
    std::cout << "Sucessfully removed" << std::endl;
}

//prints the jsons that are in this collection
void Collection::print(){
    if (this->documents.size() == 0){
        std::cout << "This collection is empty" << endl;
    }
    else{
        for (int i = 0; i < this->documents.size(); i++){
            std::cout << i << ". " << documents.at(i)->getPath() << std::endl;
        }
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

//get the name of collection
std::string Collection::getName(){
    return this->name;
}

//return documents 
Dock* Collection::getDocuments(int i){
    return documents.at(i);
}