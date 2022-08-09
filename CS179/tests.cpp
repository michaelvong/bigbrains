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
    
    

    //Database.print should print names of all collections contained
    db1.setName("new db name");
    db1.getName();
    db1.print();

    //Document.print should print entirety of .json file
    db1.printAll();
}