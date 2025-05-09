#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/*
! find the number in the file 'example1.txt', add all of them and print out the result.
  // there are no negative number
  // use stof or atof

1. open and read a file
2. find the number(use isdigit()) 
3. change the string to num (use atof)
4. print out the sum
*/

int main(){
  char str[50]; // variable to store the word
  float sum = 0.0; // variable to store total sum

  // open and read the file
  FILE *fp = fopen("example1.txt", "r");

  // if the file is not opened, print the message and exit the program
  if(fp == NULL){
    printf("File Error");
    return 1;
  }

  // read the string until end of file
    // if the string is digit and the decimal point, extract the string
    // use atof, to convert the string to a float number
    // add a number
  while(fscanf(fp, "%s", str) != EOF){
    char number[99] = ""; // variable to store the number
    int index = 0;

    for(int i = 0; str[i] != '\0'; i++){
      if(isdigit(str[i]) || str[i] == '.') number[index++] = str[i];
    }

    float num = atof(number);
    sum += num;
    printf("%.2f\n", num);

  }
  fclose(fp);

  printf("The sum is %.2f.", sum);

  return 0;
}