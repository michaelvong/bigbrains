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
    Database database;
    Collection collection1;
    //InputHandler inputManager;
    Dock *doc = new Dock();
    Dock *doc2 = new Dock();
    Collection *coll1 = new Collection();

    //database.add(&collection1);

    FILE* fp = fopen("sample1.json", "rb"); // non-Windows use "r" 
 
    char readBuffer[65536];
    FileReadStream is(fp, readBuffer, sizeof(readBuffer));

    Document d;
    d.ParseStream(is);

    fclose(fp);
    // cout << readBuffer;
    
    // std::string test = readBuffer;
    // doc->setData(readBuffer);
    // doc->print();
    // cout << "============" << endl;
    // collection1.add(doc);
    // collection1.print();

    //cout << readBuffer;

    doc->setData(readBuffer);
    //doc->print(); /works
    doc->setPath("test.json");
    doc2->setPath("test2.json");
    collection1.add(doc);
    collection1.add(doc2);
    collection1.print();
    cout << "=====" << endl;
    collection1.remove(doc->getPath());
    collection1.print();

    database.add(&collection1);


    //doc->setPath("metadata.json");
    //cout << doc->getPath();
    //cout << inputManager.displayMenu();
    return 0;


    // bool complete = false;
	// while (!complete)
	// {
    //     int option = inputManager.displayMenu();
    //     if (option == 1){
            
    //     }
    // }
}