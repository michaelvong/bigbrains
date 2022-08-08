#include <iostream>
#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
#include "rapidjson/filereadstream.h"
#include "rapidjson/filewritestream.h"
#include <cstdio>
#include <filesystem>
#include "database.h"
#include "document.h"
#include "inputHandler.h"

using namespace std;
using namespace rapidjson;
int main(){
    vector<Database*> allDatabases;
    InputHandler inputManager;
    inputManager.readData(&allDatabases);

    bool complete = false;
	while (!complete)
	{
        int option = inputManager.displayMenu();
        if (option == 1){
            int addOpt = inputManager.displayAddMenu();
            if (addOpt == 1){ //add doc
                inputManager.addDoc(&allDatabases);
            }
            else if (addOpt == 2){ //add coll
                inputManager.addColl(&allDatabases);
            }
            else if (addOpt == 3){ //add db
                inputManager.addDB(&allDatabases);
            }
        }
        //REMOVE
        else if (option == 2){
            int subOpt = inputManager.displaySubMenu();
            if (subOpt == 1){ //remove doc
                inputManager.removeDoc(&allDatabases);
            }
            else if (subOpt == 2){ //remove coll
                inputManager.removeColl(&allDatabases);
            }
            else if (subOpt == 3){ //remove DB
                inputManager.removeDB(&allDatabases);
            }
        }
        else if (option == 3){ //print
            for (int i = 0; i < allDatabases.size(); i++){
                allDatabases.at(i)->printAll();
            }
        }
        else if (option == 4){ //exit
            complete = true;
        }
    }
    return 0;
}
