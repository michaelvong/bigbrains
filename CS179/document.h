#pragma once

#include <iostream>
#include <string>
#include <vector>


class Dock
{
private:
    std::string name; //not needed?
    std::string filePath;
    int size;
    std::string data;
public:
    void setData (std::string);
    void setPath (std::string);
    std::string getPath ();
    void print ();
};

//set data from the json file
void Dock::setData(std::string d){
    this->data = d;
}

//set path of json file
void Dock::setPath(std::string path){
    this->filePath = "/" + path;
}

//get the path of json file
std::string Dock::getPath(){
    return this->filePath;
}


//prints the raw data
void Dock::print(){
    std::cout << this->data;
}
