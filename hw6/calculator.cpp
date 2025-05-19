#include <iostream>
#include <string>
#include "calculator.h"

#include <cstdlib>

using namespace std;

// set size
const int main_size = 100;

// Stack for storing double numbers
// default Constructor
Stack::Stack(){
  top = -1;
  max_size = main_size;
  stack = new Element[max_size];
}

// constructor
Stack::Stack(int size){
  top = -1;
  max_size = size;
  stack = new Element[max_size];
}

// destructor
Stack::~Stack(){
  delete[] stack;
}

// add item into the stack
void Stack::Push(Element item){
  stack[++top] = item;
}

// bring out the top item from the stack
double Stack::Pop(){
  return stack[top--];
}

// check the top item
Element Stack::Peek(){
  return stack[top];
}

// check the stack if it is empty
bool Stack::IsEmpty(){
  return top == -1;
}

// Stack for strong char(operations)
// default constructor
CharStack::CharStack(){
  top = -1;
  max_size = 100;
  stack = new char[max_size];
}
// constructor
CharStack::CharStack(int size){
  top = -1;
  max_size = size;
  stack = new char[max_size];
}
// destructor
CharStack::~CharStack(){
  delete[] stack;
}
void CharStack:: Push(char item){
  stack[++top] = item;
}
char CharStack::Pop(){
  return stack[top--];
}
char CharStack::Peek(){
  return stack[top];
}
bool CharStack::IsEmpty(){
  return top == -1;
}


// check the character if it is operator
bool isOperator(char ch){
  if(ch == '+' || ch == '-' || ch == '*' || ch == '/' ){
    return true;
  }
  else{
    return false;
  }
}

// decide the priority
int precedence(char op){
  if(op == '+' || op == '-') return 1;
  if(op == '*' || op == '/') return 2;
  return 0;
}

// change infixexpression to postfix expression
string makePostfix(string expression){
  // Stack for storing operator
  // strings for storing postfix expression and number
  CharStack opStack(main_size);
  string postfix = "";
  string num = "";

  // check all character
  // get a character[i] 
  for(int i = 0; i < expression.length(); i++){
    char ch = (i <= expression.length()) ? expression[i] : ' '; // ' ' for last number

    // (If the ch is number) get a number (consider decimal number)
    // if no number,
    if(isdigit(ch) || ch == '.'){
      num += ch;
    }
    else{ 
      if(!num.empty()){
        postfix += num; // add number into postfix
        postfix += " "; 
        num = ""; // initialize
      }

      if(ch == ' '){  // skip the blank
        continue;
      }

      if(ch == '('){  // ( is added into operation Stack
        opStack.Push(ch);
      }
      else if(ch == ')'){ // ) ==> bring out operator to calculate
        while(opStack.Peek() != '('){
          postfix += opStack.Pop();
          postfix += " ";
        }
        if(!opStack.IsEmpty()){ // error check
          opStack.Pop();  // bring out (
        }
      }

      else if(isOperator(ch)){ // if it is operator (not parenthesis)
        while(!opStack.IsEmpty() && precedence(opStack.Peek()) >= precedence(ch)){ // check the priority
          postfix += opStack.Pop();
          postfix += " ";
        }
        opStack.Push(ch);
      }
    }
  }

  // bring out all operator(remain operators)
  while(!opStack.IsEmpty()){
    postfix += opStack.Pop();
    postfix += " ";
  }

  // return the postfix expression
  return postfix;
}

// calculate postfix expression
double eval(string postfix){
  // stack for storing numbers, strings to store character, operands
  Stack stack(main_size);
  string token = "";
  double first, second;
  
  // similar way to makepostfix(iteration)
  // last space is for buffer flush
  for(int i = 0; i <= postfix.length(); i++){
    char ch = (i < postfix.length()) ? postfix[i] : ' ';

    // not a blank, store ch in a token, += for decimal
    if(ch != ' '){
      token += ch;
    }
    else if(!token.empty()){
      if(isdigit(token[0]) ){ // if it is digit
        double value = atof(token.c_str()); // change string to number(string -> char -> double)
        stack.Push(value);  // input the number into stack
      }
      else if(isOperator(token[0])){ // if operator, bring out the operands and calculate and input into the stack
        second = stack.Pop();
        first = stack.Pop();

        switch(token[0]){
          case '+': 
            stack.Push(first + second);
            break;
          case '-': 
            stack.Push(first - second);
            break;
          case '*': 
            stack.Push(first * second);
            break;
          case '/': 
            stack.Push(first / second);
            break;
        }
      }
      token = ""; // initialize token
    }
  }
  return stack.Pop(); // return the result

}

