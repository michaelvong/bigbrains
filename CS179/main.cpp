#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <sstream>
#include <fstream>
#include <cstring>
#include "include/rapidjson/document.h"
#include "include/rapidjson/writer.h"
#include "include/rapidjson/stringbuffer.h"
#include "include/rapidjson/filereadstream.h"
#include "include/rapidjson/filewritestream.h"
#include <cstdio>
#include <filesystem>
#include "document.h"
#include "inputHandler.h"
#include "database.h"
#include "include/rapidjson/ostreamwrapper.h"
using namespace std;
using namespace rapidjson;
using std::filesystem::directory_iterator;

int main(){
    /*
     // 1. Parse a JSON string into DOM.
    const char* json = "{\"project\":\"rapidjson\",\"stars\":10}";
    Document d;
    d.Parse(json);
    
    // 2. Modify it by DOM.
    Value& s = d["stars"];
    s.SetInt(s.GetInt() + 1);
    // 3. Stringify the DOM
    StringBuffer buffer;
    Writer<StringBuffer> writer(buffer);
    d.Accept(writer);
    // Output {"project":"rapidjson","stars":11}
    std::cout << buffer.GetString() << std::endl;
    */
    vector<Database*> allDatabases;
    InputHandler inputManager;

    inputManager.readData(&allDatabases);
    
    bool complete = false;
	while (!complete)
	{
        int option = inputManager.displayMenu();
        if (option == 1){
            int addOpt = inputManager.displayAddMenu();
            if (addOpt == 1){
                inputManager.addDoc(&allDatabases);
            }
            else if (addOpt == 2){
                inputManager.addColl(&allDatabases);
            }
            else if (addOpt == 3){
                inputManager.addDB(&allDatabases);
            }
        }
        else if (option == 2){
            int remOpt = inputManager.displaySubMenu();
            if (remOpt == 1){
                //remove doc
            }
            else if (remOpt == 2){
                //remove coll
            }
            else if (remOpt == 3){
                inputManager.removeDB(&allDatabases);
            }
        }
        if (option == 3){
            int updateOpt = inputManager.displayUpdateMenu();
            if (updateOpt == 1){
                //inputManager.updateDoc(&allDatabases);
            }
            else if (updateOpt == 2){
                //inputManager.updateColl(&allDatabases);
            }
            else if (updateOpt == 3){
                inputManager.updateDB(&allDatabases);
            }
        }
        else if (option == 4){ //print
            for (int i = 0; i < allDatabases.size(); i++){
                allDatabases.at(i)->printAll();
            }
        }
        else if (option == 5){
            complete = true;
        }
    }
    return 0;
}