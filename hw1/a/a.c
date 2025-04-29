#include <stdio.h>

/*
! Read a file(numbers) and find the smallest number

(repeat until no more file)
1. read a file
  1) make a filename -> find/open the file -> read a file
2. read a number and compare with the next number until eof
3. print out the result
4. move to the next file
5. if there is no file, break the loop
*/

int main(){
  int i = 1; 

  // Assume the number of file is not fixed 
  while(1){
    char filename[10]; // filename

    // make a filename(file1.txt, file2.txt), and open the file (file1.txt ...)
    sprintf(filename, "file%d.txt", i);
    FILE *fp = fopen(filename,"r");

    // if the file cannot be found or opened, exit the loop 
    if(fp == NULL){
      // printf("File Error");
      break;
    }

    printf("Input filename: %s\n", filename);

    int num = 0;
    int smallNum = 0;
    int first = 1;

    // read numbers until eof
    while(fscanf(fp, "%d", &num) != EOF){
      // the first number is the smallest 
      if(first == 1){
        smallNum = num;
        first = 0;
      }
      else{ // compare and find the smallest number
        if(num < smallNum){
          smallNum = num;
        }
      }

      
    }

    // close the file and print the result
    fclose(fp); 
    printf("The smallNum number is %d\n", smallNum);
    printf("\n");

    i++; 
  }
  return 0;
}