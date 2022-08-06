#include <iostream>
#include "include/rapidjson/document.h" 
#include "include/rapidjson/writer.h"
#include "include/rapidjson/stringbuffer.h"
#include "include/rapidjson/filereadstream.h"
#include "include/rapidjson/filewritestream.h"
#include <cstdio>
#include <filesystem>
#include "collection.h"
#include "database.h"
#include "document.h"
//#include "inputHandler.h"

using namespace std;
using namespace rapidjson;

int main(){

    Database db1;
    Collection coll1, coll2, coll3;
    Dock dock1, dock2, dock3;

    //Testing Constructors of each class
    Dock();
    Collection();
    Database();
    
    Collection colltest;
    Database("DBTest");
    colltest.getName();
    
    

    //Database.print should print names of all collections contained
    coll1.setName("Player Stats 2020");
    coll2.setName("Player Stats 2021");
    coll3.setName("Player Stats 2022");
    db1.add(&coll1);
    db1.add(&coll2);
    db1.add(&coll3);
    db1.print();

    //Collection.print should print names of all documents (.jsons) contained
    dock1.setPath("sample1.json");
    dock2.setPath("sample2.json");
    dock3.setPath("sample3.json");
    coll1.add(&dock1);
    coll1.add(&dock2);
    coll1.add(&dock3);
    coll1.print();

    //Document.print should print entirety of .json file
    dock1.print();
    dock2.print();
    dock3.print();
}