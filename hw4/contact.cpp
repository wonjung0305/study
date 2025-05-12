/*
Implement load and print
  contact.h => use class Contact(total_num, persons(struct, name/email/phone/dob))
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <string>
#include <fstream>
#include "contact.h"
#include <iostream>

using namespace std;
const int lineText= 256;

// no implement
Person str2person(char*);
Date str2date(char*);
char* trim(char*);

// read the data from file
  // store data to contact.h (Contact class)
void Contact::load(string file_name) {
  
  char c_str[1024];
  strcpy(c_str, file_name.c_str());

  // open the file 
  FILE* fp = fopen(c_str, "r");

  // File Error
  if(fp == NULL){
    cout << "File Error";
    return;
  }

  char line[lineText];
  while(fgets(line,sizeof(line), fp)){
    // remove \n
    if(line[strlen(line) - 1] == '\n'){
      line[strlen(line) - 1] = '\0';
    }

    char* name = strtok(line, ";");
    char* birth = strtok(NULL, ";");
    char* email = strtok(NULL, ";");
    char* phone = strtok(NULL, ";");

    // remove the space behind ; ( )
    birth = trim(birth);
    email = trim(email);
    phone = trim(phone);

    strcpy(persons[total_num].name, name);
    strcpy(persons[total_num].email, email);
    strcpy(persons[total_num].phone, phone);

    // birthday information to dob(Person) in contact.h
    // year
    // month
    // day
    persons[total_num].dob.year = (birth[0] - '0') * 1000 + (birth[1] - '0')*100 + (birth[2] - '0') *10 + (birth[3] - '0');
    persons[total_num].dob.month = (birth[4] - '0') * 10 + (birth[5] - '0');
    persons[total_num].dob.day = (birth[6] - '0') * 10 + (birth[7] - '0');

    total_num++;

  }
  fclose(fp);
  
}

char* Contact::trim(char* str){
  while(isspace(*str)){
    str++;
  }

  return str;
}

// print out the contact
void Contact::print() {
  string division = "; ";
  
  // birthday formatting and print the information
  for(int i = 0; i < total_num; i++){
    char birth_format[9];
    sprintf(birth_format, "%04d%02d%02d", persons[i].dob.year, persons[i].dob.month, persons[i].dob.day);

    cout << persons[i].name << division << birth_format << division << persons[i].email << division << persons[i].phone  << endl;
  }
}

// implement the other functions here (No implement)
Person str2person(char*){

}

Date str2date(char*){

}