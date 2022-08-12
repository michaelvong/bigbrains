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

    /* 8/8 - 8/15 Sprint 3 tests: 
        Query Search
        Search for document within a collection within a database
        Search for a collection within a database
        Remove a document from a collection using Query Search
    */

    vector<Database*> allDatabases;
    Document tempDoc;
    Collection tempColl;
    InputHandler inputManager;
    int option;

    //Tests searchDoc
    tempDoc = inputManager.searchDoc(&allDatabases, field, value);
    if (tempDoc->getDoc() == ("{\"" + field + "\": \"" + value + "\"}").c_str())
    {
        cout << "SearchDoc Test Pass" << endl;
        return true;
    }

    //Tests searchColl
    tempColl = input.Manager.searchColl(&allDatabases, nameChoose);
    if (tempColl->getColl() == nameChoose)
    {
        cout << "SearchColl Test Pass" << endl;
        return true;
    }
        
    //Tests searchRemove
    input.Manager.searchRemove(&allDatabases, nameChoose);
    if (searchColl(allDatabases, nameChoose) == null)
    {
        cout << "SearchRemove Test Pass" << endl;
        return true;
    }
    
    
    return 0;
}