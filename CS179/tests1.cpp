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

    /* 8/1 - 8/8 Sprint 2 tests: 
        Add, Delete, Print, Read for Database, Collection, Documents
        Update for Database, Collection
        Menu interface implementation
        User input implementation
    */

    vector<Database*> allDatabases;
    InputHandler inputManager;
    int option;

    //Tests Read and Print for DB, Coll, Documents
    cout << "Testing read DB, Coll, Docu" << endl;
    inputManager.readData(&allDatabases);
    for (int i = 0; i < allDatabases.size(); i++){
        allDatabases.at(i)->printAll();
    }
    cout << "All existing db, coll, documents in STORAGE are printed." << endl;

    //Tests add DB, Coll, Doc
    cout << endl << "Testing addDB" << endl;
    inputManager.addDB(&allDatabases);
    cout << endl << "Testing addColl: Select DB and enter with form ___.json" << endl;
    inputManager.addColl(&allDatabases);
    cout << endl << "Testing addDoc: Select DB and Coll and enter with form {\"____\": \"____\"}" << endl;
    inputManager.addDoc(&allDatabases);
    for (int i = 0; i < allDatabases.size(); i++){
         allDatabases.at(i)->printAll();
    }

    //Tests update DB, Coll
    cout << endl << "Testing updateDB: Select DB and enter new name" << endl;
    inputManager.updateDB(&allDatabases);
    cout << endl << "Testing updateColl: Selection DB and Coll and enter new name" << endl;
    inputManager.updateColl(&allDatabases);
    for (int i = 0; i < allDatabases.size(); i++){
         allDatabases.at(i)->printAll();
    }


    //Tests remove DB, Coll
    cout << endl << "Testing removeColl" << endl;
    inputManager.removeColl(&allDatabases);
    cout << endl << "Testing removeDB" << endl;
    inputManager.removeDB(&allDatabases);
    for (int i = 0; i < allDatabases.size(); i++){
         allDatabases.at(i)->printAll();
    }




    
    




    
    return 0;

    


    
}