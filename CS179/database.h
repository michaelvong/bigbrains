#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "collection.h"
#include "document.h"

using namespace std;

class Database
{
private:
    std::string name;
    std::string filePath;
    int size;
    std::vector<Collection*> collections;
public:
    Database();
    Database(std::string dbName);
    void add (Collection*);
    void remove (std::string);
    void print ();
    void setName (std::string);
};


//Default Constructor
Database::Database(){
    name = "";
    filePath = "";
    size = 0;
}

//Constructor
Database::Database(std::string dbName){
    name = dbName;
    std::cout << "Database created, dbName: " << name << std::endl;
}

//add a collection to this database
void Database::add (Collection* coll){
    this->collections.push_back(coll);
}

//removes a doc from vector by matching path names
void Database::remove (std::string path){
    for (int i = 0; i < this->collections.size(); i++){
        if (this->collections.at(i)->getPath() == path){
            this->collections.erase(this->collections.begin()+i);
        }
    }
}

//prints the jsons that are in this collection
void Database::print(){
    for (int i = 0; i < this->collections.size(); i++){
        std::cout << collections.at(i)->getPath() << std::endl;
    }
}

//set the name of this collection
void Database::setName(std::string n){
    this->name = n;
}
