#include <stdio.h>
#include <ctype.h>

/*
! count the alphabet and number (ignore case sensitivity)

1. Enter the sentence
2. check the word
  use isalpha() ==> alphabet 
  use isdigit ==> number
3. count the character array or number array
*/


int main(){
  char alphabet[26] = {0};
  int number[10] = {0};
  char line[100] = "";

  // Enter the sentence
  fgets(line, sizeof(line), stdin);

  // until the end(null)
    // if character is a word, convert to a uppercase and count
    // if character is a number, just count => count by ASCII 
  for(int i = 0; line[i] != '\0'; i++){
    if(isalpha(line[i])){
      char c = toupper(line[i]);
      alphabet[c - 'A']++;
    }
    if(isdigit(line[i])){
      number[line[i] - '0']++;
    }
  }

  // print the result
  for(int i = 0; i < 26; i++){
    printf("%c: %d\n", 'A' + i, alphabet[i]);
  }
  for(int i = 0; i < 10; i++){
    if(i == 9){ // If the line is end, no new line
      printf("%c: %d", '0' + i, number[i]);
    }
    else{
      printf("%c: %d\n", '0' + i, number[i]);
    }
  }


  return 0;
}