#pragma once


#include <iostream>
#include "document.h"
#include "collection.h"
#include "database.h"
#include <string>

using namespace std;

class InputHandler
{
private:
public:
    int displayMenu();
    int displayAddMenu();
    void addDoc(vector<Database*>*);
    void addColl(vector<Database*>*);
    void addDB(vector<Database*>*);
};

//displays main menu for user and returns chosen option 
int InputHandler::displayMenu()
{
    std::string str;
    int option;
	cout << "Please select an option." << endl;
	cout << "1. Add" << endl;
	cout << "2. Remove" << endl;
	cout << "3. Search" << endl;
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

//adds document to chosen database/collection
//takes in pointer to vector of databases
void InputHandler::addDoc(vector<Database*>* DB){
    string DBchoose, collChoose, docPath;
    if (DB->size() != 0){ //if database !empty, display them
        cout << "Choose a database: " << endl;
        for (int i = 0; i < DB->size(); i++){
            cout << i << ". " << DB->at(i)->getPath() << endl;
        }
        getline(cin, DBchoose);
        cout << "Choose a collection from this database: " << endl;
        DB->at(stoi(DBchoose))->print(); //assuming DBchoose is int, prints all collections in the chosen DB
        getline(cin, collChoose);
        cout << "Enter path of document: ";
        getline(cin, docPath);
        Dock* docAdd = new Dock(docPath);
        DB->at(stoi(DBchoose))->getCollection(stoi(collChoose))->add(docAdd);
    } else { //database empty
        cout << "No databases to choose from." << endl;
    }
}

//adds collection to chosen database, takes in pointer to vector of databases
void InputHandler::addColl(vector<Database*>* DB){
    string DBchoose1; //chosen database
    string collName; //new coll name
    if (DB->size() != 0){ //if database !empty, display them
        cout << "Choose a database: " << endl;
        for (int i = 0; i < DB->size(); i++){
           cout << i << ". " << DB->at(i)->getPath() << endl;
        }
        getline(cin, DBchoose1);
        cout << "Name for collection: ";
        getline(cin, collName);
        Collection* collPtr = new Collection(collName);
        DB->at(stoi(DBchoose1))->add(collPtr);
        } else { //database empty
            cout << "No databases to choose from." << endl;
        }
}

//adds database
void InputHandler::addDB(vector<Database*>* DB){
    string DBname;
    cout << "Enter database name: ";
    getline(cin, DBname);
    Database *databasePtr = new Database(DBname);
    DB->push_back(databasePtr);
}