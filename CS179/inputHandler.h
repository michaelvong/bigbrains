#pragma once


#include <iostream>
#include "document.h"
#include "collection.h"
#include "database.h"
#include <string>
//#include "direct.h" //uncomment this when using windows
#include "unistd.h"
#include <sys/types.h>
#include <sys/stat.h>

using namespace std;

class InputHandler
{
private:
public:
    int displayMenu();
    int displayAddMenu();
    int displaySubMenu();
    void addDoc(vector<Database*>*);
    void addColl(vector<Database*>*);
    void addDB(vector<Database*>*);
    void removeDoc(vector<Database*>*);
    void removeColl(vector<Database*>*);
    void removeDB(vector<Database*>*);
};

//displays main menu for user and returns chosen option 
int InputHandler::displayMenu()
{
    std::string str;
    int option;
	cout << "Please select an option." << endl;
	cout << "1. Add" << endl;
	cout << "2. Remove" << endl;
	cout << "3. Print" << endl;
    cout << "4. Quit" << endl;
    getline(cin, str);
    option = stoi(str);
	return option;
}

//if add is chosen, display the ADD menu and return chosen option
int InputHandler::displayAddMenu(){
    std::string str;
    int option;
    cout << "1. Add a document" << endl;
    cout << "2. Add a collection" << endl;
    cout << "3. Add a database" << endl;
    getline(cin,str);
    option = stoi(str);
    return option;
}


//if remove is chosen, display the remove menu and return option
int InputHandler::displaySubMenu(){
    std::string temp;
    cout << "1. Remove a document" << endl;
    cout << "2. Remove a collection" << endl;
    cout << "3. Remove a database" << endl;
    getline(cin,temp);
    int option = stoi(temp);
    return option;
}

//removes doc from chosen db and collection
//prints success if successful
void InputHandler::removeDoc(vector<Database*>* DB){
    string DBchoose, collChoose, docRemove, path;
    if (DB->size() != 0){ //if database !empty, display them
        cout << "Choose a database: " << endl;
        for (int i = 0; i < DB->size(); i++){
            cout << i << ". " << DB->at(i)->getName() << endl;
        }
        getline(cin, DBchoose);
        cout << "Choose a collection from this database: " << endl;
        DB->at(stoi(DBchoose))->print(); //assuming DBchoose is int, prints all collections in the chosen DB
        getline(cin, collChoose);
        cout << "Choose a document to remove: " << endl;
        DB->at(stoi(DBchoose))->getCollection(stoi(collChoose))->print();
        getline(cin, docRemove);
        path = DB->at(stoi(DBchoose))->getCollection(stoi(collChoose))->getDocuments(stoi(docRemove))->getPath();
        const char *c = path.c_str();
        if(remove(c) != 0){
            cout << "Error in deleting document." << endl;
        } else {
            cout << "Document deleted!" << endl;
            DB->at(stoi(DBchoose))->getCollection(stoi(collChoose))->removeDoc(stoi(docRemove));
        }
    } else { //database empty
        cout << "No databases to choose from." << endl;
    }
}

//removes collection from chosen database
void InputHandler::removeColl(vector<Database*>* DB){
    string DBchoose, collChoose, temp;
    if (DB->size() != 0){ //if database !empty, display them
        cout << "Choose a database: " << endl;
        for (int i = 0; i < DB->size(); i++){
            cout << i << ". " << DB->at(i)->getName() << endl;
        }
        getline(cin, DBchoose);
        cout << "Choose a collection from this database: " << endl;
        DB->at(stoi(DBchoose))->print(); //assuming DBchoose is int, prints all collections in the chosen DB
        getline(cin, collChoose);
        temp = DB->at(stoi(DBchoose))->getCollection(stoi(collChoose))->getPath();
        const char *c = temp.c_str();
        if (!DB->at(stoi(DBchoose))->getCollection(stoi(collChoose))->getDocuments().empty()) {
            DB->at(stoi(DBchoose))->getCollection(stoi(collChoose))->deleteDocs();
        }
        if(rmdir(c) == -1){
            cout << "Error in removing collection." << endl;
        } else {
            DB->at(stoi(DBchoose))->remove(stoi(collChoose));
            cout << "Collection removed." << endl;
        }
    } else { //database empty
        cout << "No databases to choose from." << endl;
    }
}

//removes DB from main vector of DB
void InputHandler::removeDB(vector<Database*>* DB){
    string DBchoose, temp;
    if (DB->size() != 0){ //if database !empty, display them
        cout << "Choose a database: " << endl;
        for (int i = 0; i < DB->size(); i++){
            cout << i << ". " << DB->at(i)->getName() << endl;
        }
        getline(cin, DBchoose);
        temp = DB->at(stoi(DBchoose))->getPath();
        const char *c = temp.c_str();
        if (!DB->at(stoi(DBchoose))->getCollections().empty()) {
            DB->at(stoi(DBchoose))->deleteFiles();
        }
        if(rmdir(c) == -1){
            //cerr << " Error : " << strerror(errno) << endl;
            cout << "Error in removing database." << endl;
        } else {
            DB->erase(DB->begin() + stoi(DBchoose));
            cout << "Database removed!" << endl;
        }
    } else { //database empty
        cout << "No databases to choose from." << endl;
    }
}

//adds document to chosen database/collection
//takes in pointer to vector of databases
void InputHandler::addDoc(vector<Database*>* DB){
    string DBchoose, collChoose, docPath, temp;
    if (DB->size() != 0){ //if database !empty, display them
        cout << "Choose a database: " << endl;
        for (int i = 0; i < DB->size(); i++){
            cout << i << ". " << DB->at(i)->getName() << endl;
        }
        getline(cin, DBchoose);
        cout << "Choose a collection from this database: " << endl;
        DB->at(stoi(DBchoose))->print(); //assuming DBchoose is int, prints all collections in the chosen DB
        getline(cin, collChoose);
        cout << "Enter path of document: ";
        getline(cin, docPath);
        Dock* docAdd = new Dock(docPath);
        const char *c = docPath.c_str();
        temp = DB->at(stoi(DBchoose))->getCollection(stoi(collChoose))->getPath();
        ofstream myFile(temp+docPath);
        myFile.close();
        docAdd->setPath(temp);
        DB->at(stoi(DBchoose))->getCollection(stoi(collChoose))->add(docAdd);
    } else { //database empty
        cout << "No databases to choose from." << endl;
    }
}

//adds collection to chosen database, takes in pointer to vector of databases
void InputHandler::addColl(vector<Database*>* DB){
    string DBchoose1; //chosen database
    string collName; //new coll name
    string temp;
    if (DB->size() != 0){ //if database !empty, display them
        cout << "Choose a database: " << endl;
        for (int i = 0; i < DB->size(); i++){
           cout << i << ". " << DB->at(i)->getName() << endl;
        }
        getline(cin, DBchoose1);
        cout << "Name for collection: ";
        getline(cin, collName);
        Collection* collPtr = new Collection(collName);
        collPtr->setPath(DB->at(stoi(DBchoose1))->getPath());
        temp = collPtr->getPath();
        const char *f = temp.c_str();
        if(mkdir(f,0777) == -1){
            //cerr << " Error : " << strerror(errno) << endl;
            cout << "Error in creating collection." << endl;
        } else {
            DB->at(stoi(DBchoose1))->add(collPtr);
            cout << "Collection created!" << endl;
        }
    } else { //database empty
        cout << "No databases to choose from." << endl;
    }
}

//adds database
void InputHandler::addDB(vector<Database*>* DB){
    string DBname, temp;
    cout << "Enter database name: ";
    getline(cin, DBname);
    Database *databasePtr = new Database(DBname);
    temp = databasePtr->getPath();
    const char *c = temp.c_str();
    if(mkdir(c,0777) == -1){
        //cerr << " Error : " << strerror(errno) << endl; //check which error its giving
        cout << "Error in creating database." << endl;
    } else {
        DB->push_back(databasePtr);
        cout << "Database created!" << endl;
    }
}
