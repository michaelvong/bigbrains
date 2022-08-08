#pragma once

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Dock
{
private:
    std::string name;
    std::string filePath;
    int size;
    std::string data;
public:
    Dock();
    Dock(string fileName) {this->name = fileName; }
    void setData (std::string);
    void setPath (std::string);
    std::string getName () {return this->name;}
    std::string getPath ();
    void print ();
};

//Default Constructor
Dock::Dock(){
    name = "";
    filePath = "";
    size = 0;
}

//set data from the json file
void Dock::setData(std::string d){
    this->data = d;
}

//set path of json file
void Dock::setPath(std::string path){
    this->filePath = path+this->name;
}

//get the path of json file
std::string Dock::getPath(){
    return this->filePath;
}


//prints the raw data
void Dock::print(){
    std::cout << this->data;
}