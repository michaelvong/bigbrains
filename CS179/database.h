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
    Database(std::string dbName) {this->name = dbName;}
    void add (Collection*);
    void remove (std::string);
    void print ();
    void printAll();
    void setName (std::string);
    std::string getPath();
    Collection* getCollection(int);
};


//Default Constructor
Database::Database(){
    name = "";
    filePath = "";
    size = 0;
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

void Database::printAll(){
    if (this->collections.size() == 0){
        std::cout << "Database \"" << this->name << "\" is empty." << endl;
    }
    else{
        std::cout << "Database Name: " << this->name << endl;
        for (int i = 0; i < this->collections.size(); i++){
            std::cout << "Collection: " << this->collections.at(i)->getName() << std::endl;
            if (this->collections.at(i)->getDocuments().size() == 0){
                std::cout << "\t{This collection is empty}" << endl;
            } else {
                std::cout << "\tDocuments: " << std::endl;
                for (int j = 0; j < this->collections.at(i)->getDocuments().size(); j++){
                    std::cout << "\t\t" << this->collections.at(i)->getDocuments(j)->getPath() << endl;
                }
            }
        }
    }
}

std::string Database::getPath(){
    return this->name;
}


Collection* Database::getCollection(int i){
    return collections.at(i);
}