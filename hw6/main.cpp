/*
make a calculator which can calculate 4 operators and parenthesis (real numbers)

by Kim, Wonjung
*/

/*
1. Input the expression
2. Input the numbers in stack (double), input the operators in stack(char)
  => change infix to postfix
3. Calculate
4. print the result
*/

#include <iostream>
#include <string>
#include "calculator.h"

using namespace std;

int main(){

  // Enter the expression
  string expression = "";
  cout << "Enter the expression > ";
  getline(cin, expression);

  // Convert the expression to postfix, calculate it as a real number
  string postfix = makePostfix(expression);
  double result = eval(postfix);

  // print out the result
  cout << result;

  return 0;
}

// (3.4+5) * 2.3 / (2.3+1.2) 