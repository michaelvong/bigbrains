#include "include/rapidjson/document.h"
#include "include/rapidjson//writer.h"
#include "include/rapidjson/stringbuffer.h"
#include <iostream>
#include <string>

using namespace rapidjson;
int Menu(){
     int option;
     std::cout << "Welcome to bigBrainsDB select from menu please: " << std::endl;
     std::cout << "1.)Add JSON File "<< std::endl;

     std::cout << "2.)View JSON File "<< std::endl;
     std::cout << "3.)Quit "<< std::endl;
     std:: cin >> option;
     return option;
}

int main() {
    // 1. Parse a JSON string into DOM.
    //Getting the file path



    const char* json = "{\"Hello\":\"rapidjson\",\"stars\":10}";
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
    return 0;
}