/*
1) Implement three operation
2) use make2dArray and free2dArray functions for 2D array

output 
1) if rows / columns do not match, print "Matrix dimensions mismatch"
2) dimension of the output matrix and the matrix elements in order

1. Enter the option character 'a','m','t' (addition, multiplication, transpose )
  - Enter the operation to perform
2. Read a input file
  - Read 1 or 2 files depending on the operation
  - Read the content(in the file)
  - In the first line, the size is entered
3. Check the matrix size for operations
4. If the condition is satisfied, print the output matrix after the size

*/

#include <stdio.h>
#include <stdlib.h>

float **add_matrix(float** a, int ah, int aw, float** b, int bh, int bw);
float **mul_matrix(float** a, int ah, int aw, float** b, int bh, int bw);
float **transpose_matrix(float** a, int ah, int aw);

float **make2dArray(int rows, int cols);
void free2dArray(float **arr, int rows);

#define fileSize 100

int main(){
  char operation = ' ';
  
  printf("What operation do you want? (‘a’, ‘m’, ‘t’)> ");
  scanf(" %c", &operation);

  char file1[fileSize], file2[fileSize];
  FILE *fp1;
  FILE *fp2;

  printf("Input files names: ");

  int ah, bh;
  int aw, bw;
  float **a, **b, **result;

  // if operation is a(addition) or m(multiply)
  if(operation == 'a' || operation == 'm' ){
    // file open (2)
    scanf("%s %s", file1, file2);
    fp1 = fopen(file1, "r");
    fp2 = fopen(file2, "r");

    // file error
    if(fp1 == NULL || fp2 == NULL){
      printf("File Error");
      return 1;
    }

    // read data (1)
    fscanf(fp1, "%d %d", &ah, &aw);
    a = make2dArray(ah,aw);
    for(int i = 0; i < ah; i++){
      for(int j = 0; j < aw; j++){
        fscanf(fp1, "%f", &a[i][j]);
      }
    }

    // read data(2)
    fscanf(fp2, "%d %d", &bh, &bw);
    b = make2dArray(bh, bw);
    for(int i = 0; i < bh; i++){
      for(int j = 0; j < bw; j++){
        fscanf(fp2, "%f", &b[i][j]);
      }
    }

    fclose(fp1);
    fclose(fp2);

    // depending on operation, run the function add or multiply
    if(operation == 'a') result = add_matrix(a,ah,aw,b,bh,bw);
    else if(operation == 'm') result = mul_matrix(a,ah,aw, b,bh,bw);

    if(result != NULL){
      int matrix_height = ah; // a's row
      int width = (operation == 'a') ? aw : bw; // column, multiply a row * b col

      printf("%d %d\n", matrix_height, width );
      for(int i = 0; i < matrix_height; i++){
        for(int j = 0; j < width; j++){
          printf("%.1f ", result[i][j]);
        }
        printf("\n");
      }
      free2dArray(result, matrix_height);
    }

    free2dArray(a, ah);
    free2dArray(b, bh);

  }
  // if operation is t, open one file
  else if(operation == 't'){
    scanf("%s", file1);

    fp1 = fopen(file1, "r");
    
    // File Error
    if(fp1 == NULL){
      printf("File Error");
      return 1;
    }

    // read data
    fscanf(fp1, "%d %d", &ah, &aw);
    a = make2dArray(ah, aw);
    for(int i = 0; i < ah; i++){
      for(int j = 0; j < aw; j++){
        fscanf(fp1, "%f", &a[i][j]);
      }
    }
    fclose(fp1);

    result = transpose_matrix(a, ah, aw);

    printf("%d %d\n", aw, ah);
    for(int i = 0; i < aw; i++){
      for(int j = 0; j < ah; j++){
        printf("%.1f ", result[i][j]);
      }
      printf("\n");
    }
    free2dArray(a, ah);
    free2dArray(result, aw);
  }

  return 0;
}

// creat 2D array
float **make2dArray(int rows, int cols){
  // arr == dynamically allocate an pointers to store the address(array)
  // arr[0] == allocate all memory block to store all elements
  float **arr = (float **)malloc(rows * sizeof(float *));
  arr[0] = (float *)malloc(rows * cols * sizeof(float)); 

  // set each row pointer (to access data by row)
  for(int i = 1; i < rows; i++){
    arr[i] = arr[0] + (i * cols);
  }

  return arr;
}

// free data and pointer array
void free2dArray(float **arr, int rows){
  if(arr != NULL){
    free(arr[0]);
    free(arr);
  }
}

// add
  // float** a , b == array, int ah, bh == height(row), int aw,bw == width(column)
float **add_matrix(float** a, int ah, int aw, float** b, int bh, int bw){
  // mismatch
  if(ah != bh || aw != bw){
    printf("Matrix dimensions mismatch\n");
    return NULL; // error
  }

  // Dynamically allocate 2D array to store the result
  float **result = make2dArray(ah,aw);

  // add each elements
  for(int i = 0; i < ah; i++){
    for(int j = 0; j < aw; j++){
      result[i][j] = a[i][j] + b[i][j];
    }
  }

  return result;
}

// multiply a matrix b matrix
float **mul_matrix(float** a, int ah, int aw, float** b, int bh, int bw){
  // mismatch
  if(aw != bh){
    printf("Matrix dimensions mismatch\n");
    return NULL; // error
  }

  // Allocate memory for result
  float **result = make2dArray(ah,bw);

  // multiply a * b 
  // matrix a row
    // matrix b col
      // a * b 
  for(int i = 0; i < ah; i++){
    for(int j = 0; j < bw; j++){
      result[i][j] = 0; // initialize
      for(int k = 0; k < aw; k++){
        result[i][j] += a[i][k] * b[k][j];
      }
    }
  }

  return result;
}

// transpose
float **transpose_matrix(float** a, int ah, int aw){
  float **result = make2dArray(aw, ah);

  // a[i][j] = a[j][i] (switch row and column)
  for(int i = 0; i < ah; i++){
    for(int j = 0; j < aw; j++){
      result[j][i] = a[i][j];
    }
  }

  return result;
}