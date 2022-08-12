#pragma once
#include <iostream>
#include "collection.h"
#include <string>
#include "direct.h" //uncomment this when using windows
#include <sys/types.h>
#include <sys/stat.h>
#include <fstream>
#include <filesystem>
#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
#include "rapidjson/filereadstream.h"
#include "rapidjson/filewritestream.h"
#include "database.h"
using namespace std;
using namespace rapidjson;
class Database
{
private:
    const std::string folder = "STORAGE/";
    string name;
    string filePath;
    vector<Collection*> collections;
public:
    Database();
    Database(string n){this->name = n; this->filePath = folder+n+"/";}
    void addColl(Collection*);
    void removeColl(int);
    void updateDB(int);
    void print();
    string getPath() {return this->filePath; }
    Collection* getCollection (int);
    vector<Collection*> getCollections() {return this->collections;}
    string getName() {return this->name; }
    void printAll();
    void deleteFiles();
    void setName(std::string);
    void setPath(std::string n) {this->filePath = folder+n+"\\";}
};


//set the name of this collection
void Database::setName(std::string n){
    this->name = n;
    //cout << "in setName: " << endl << this->name << endl;
}


//add a collection to this database
void Database::addColl(Collection* c){
    this->collections.push_back(c);
}

//removes a collection from vector by matching index
void Database::removeColl (int i){
    this->collections.erase(this->collections.begin()+i);
    std::cout << "Sucessfully removed" << std::endl;  
}


//prints the jsons that are in this collection
void Database::print(){
    for (int i = 0; i < this->collections.size(); i++){
        std::cout << i << ". " << collections.at(i)->getName() << std::endl;
    }
}

//returns collection* at an index
Collection* Database::getCollection(int i){
    return collections.at(i);
}

//prints all the collections in database
void Database::printAll(){
    if (this->collections.size() == 0){
        std::cout << "Database \"" << this->name << "\" is empty." << endl;
    }
    else{
        std::cout << "Database Name: " << this->name << endl;
        for (int i = 0; i < this->collections.size(); i++){
            cout << "Collection: " << this->collections.at(i)->getName() << endl;
            for (int j = 0; j < this->collections.at(i)->getDocs().size(); j++){
                StringBuffer buffer;
                Writer<StringBuffer> writer(buffer);
                this->collections.at(i)->getDocAt(j)->Accept(writer);
                cout << "\t" << buffer.GetString() << endl;
            }
        }
    }
}

//removes the files from this database
void Database::deleteFiles(){
    string temp;
    for (int i = 0; i < this->collections.size(); i++){
        temp = this->collections.at(i)->getPath();
        const char *c = temp.c_str();
        remove(c); 
    }
}