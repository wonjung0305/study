/*
Contact application (Class)

load: load a file into a structure array
save: save the structure array into a file

insert: add a new person into the structure array
delete: delete a person from the array

retrieve: search a person, and print out the person's information
print: print all contacts

!format
name; birthday; email; phone_number
henry choi; 20190303; hchoi@handong.edu; 010-1234-5678

implements only 'load' and 'print'
.cpp(function) and .h (client)
*/

#include <iostream>
#include <string>
#include "contact.h"
using namespace std;

#define MAX_NUM 1000 // can be given by standard input

int main() {
    string file_name;
    Contact* contacts;
    contacts = new Contact(MAX_NUM); 

    cout << "file name of contact data: "; // << endl;  I think it is not neccessary
    cin >> file_name;

    contacts->load(file_name);
    contacts->print();

    return 0;
}
