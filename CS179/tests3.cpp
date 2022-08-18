#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <sstream>
#include <fstream>
#include <cstring>
#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
#include "rapidjson/filereadstream.h"
#include "rapidjson/filewritestream.h"
#include <cstdio>
#include <filesystem>
#include "document.h"
#include "inputHandler.h"
#include "database.h"
#include "rapidjson/ostreamwrapper.h"
using namespace std;
using namespace rapidjson;
using std::filesystem::directory_iterator;

using namespace std;
using namespace rapidjson;

int main(){

    /* 8/15 - 8/22 Sprint 4 tests: 
        Multithreaded Query Search
        Multithreaded reading in existing data
    */

    vector<Database*> allDatabases;
    Document tempDoc, tempDoc2;
    Collection tempColl;
    InputHandler inputManager;
    int option;


    //Runs Query Search using key and value which will output time taken to execute
    //Runs Query Search multithreaded using the same key and value which will output time taken to execute
    //Can compare the times after they are outputted
    tempDoc = inputManager.searchQuery(&allDatabases, key, value);
    tempDoc2 = inputManager.searchQueryThreaded(&allDatabases, key, value);
    if (tempDoc->getDoc() == ("{\"" + field + "\": \"" + value + "\"}").c_str()){
        cout << "SearchDoc Test Pass" << endl;
        return true;
    }
    if (tempDoc2->getDoc() == ("{\"" + field + "\": \"" + value + "\"}").c_str()){
        cout << "SearchDoc2 Test Pass" << endl;
        return true;
    }

    //Tests reading data using multi threads and compares to reading data without threads
    cout << "Testing read DB, Coll, Docu" << endl;
    inputManager.readData(&allDatabases); //this function will print execution time
    inputManager.readDataThreaded(&allDatabases); //this function will print execution time
    //After running both functions, both times will be printed and compared
    return 0;
}