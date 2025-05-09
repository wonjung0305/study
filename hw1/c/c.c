#include <stdio.h>
#include <ctype.h>

/*
! Change upper characters to lower characters, lower characters to upper characters

1. input the line
2. check the line that it is lowercase or uppercase(isupper(), islower())
3. convert and print out (toupper(), tolower())
*/

int main(){

  char line[99];
  
  // Enter the sentence
  fgets(line, sizeof(line), stdin);

  // Check the char whether it is lowercase or uppercase, and convert them
  for(int i = 0; line[i] != '\0'; i++){
    if(islower(line[i])) line[i] = toupper(line[i]);
    else if(isupper(line[i])) line[i] = tolower(line[i]);
  }

  // print the result
  printf("%s", line);

  return 0;
}