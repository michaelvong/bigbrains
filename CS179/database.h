#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "collection.h"
#include "document.h"
#include "unistd.h"
using namespace std;

class Database
{
private:
    const std::string folder = "STORAGE/";
    std::string name;
    std::string filePath;
    int size;
    std::vector<Collection*> collections;
public:
    Database();
    Database(std::string dbName) {this->name = dbName; this->filePath = folder+dbName+"/"; } 
    void add (Collection*);
    void remove (std::string);
    void remove (int);
    void print ();
    void printAll();
    void setName (std::string);
    std::string getName();
    std::string getPath() {return this->filePath;}
    Collection* getCollection(int);
    std::vector<Collection*> getCollections() {return this->collections;}
    void deleteFiles();
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

//removes a collection from vector by matching path names
void Database::remove (std::string path){
    for (int i = 0; i < this->collections.size(); i++){
        if (this->collections.at(i)->getPath() == path){
            this->collections.erase(this->collections.begin()+i);
        }
    }
}

//removes a collection from vector by matching index
void Database::remove (int i){
    this->collections.erase(this->collections.begin()+i);
    std::cout << "Sucessfully removed" << std::endl;  
}

//prints the jsons that are in this collection
void Database::print(){
    if (this->collections.size() == 0){
        std::cout << "This database is empty" << endl;
    }
    else{
        for (int i = 0; i < this->collections.size(); i++){
            std::cout << i << ". " << collections.at(i)->getName() << std::endl;
        }
    }
}

//set the name of this collection
void Database::setName(std::string n){
    this->name = n;
}

//prints all the contents of a database
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
                    std::cout << "\t\t" << this->collections.at(i)->getDocuments(j)->getName() << endl;
                }
            }
        }
    }
}

std::string Database::getName(){
    return this->name;
}

//returns collection* at an index
Collection* Database::getCollection(int i){
    return collections.at(i);
}

//deletes all the collection directories in a database
void Database::deleteFiles(){
    string temp;
    for (int i = 0; i < this->collections.size(); i++){
        this->collections.at(i)->deleteDocs();
        temp = this->collections.at(i)->getPath();
        const char *c = temp.c_str();
        rmdir(c);
    }
}
