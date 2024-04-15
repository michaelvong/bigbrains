# FluxDB

Description: 
- We made a Document Database application that can process and work with JSON Files
- Follows MongoDB's implementation of organization through Databases, Collections, and Documents
- This project encapsulates a small subet of features that noSQL Databases, such as MongoDB, offer. 
- Some of the functionality emulated include CRUD Operations, Sequential Searching, and Threaded Searching

Software Prequisties:

- C++17
- Utilizes Rapidjson parser, found at: https://github.com/Tencent/rapidjson

Command to Compile: 

- Terminal -> Run Build Task (CTRL+SHIFT+B)
- Build with C/C++:g++.exe active build file

Command to Run:

- .\main

Commands for Functionality:
Menu is accessible by numbers from the keyboard (0-9):
1. Add
2. Remove
3. Update
4. Query
5. Print
6. Query Threaded
7. Quit

Submenus options are selected by number as well:

Ex. 1. Add
1
Please select an option:
1. Add a document       
2. Add a collection     
3. Add a database
3
Enter database name: db1

When prompted for names, letters, numbers, and symbols are available.

Ex. (Query Thread Search): 

Enter a document. EX: { "name" : "michael" }

{"player_name":"Travis Knight"}
