#include <string>
using namespace std;

typedef double Element;

// Stack class
  // input the number
class Stack{
  private:
    int top;
    int max_size;
    Element* stack;

  public:
    Stack(); // default constructor
    Stack(int size);  // constructor
    ~Stack(); // destructor

    void Push(Element item);  // input the number
    Element Pop();  // bring out the number
    Element Peek(); // check the number
    bool IsEmpty(); // check stack if it is empty befor using pop or peek
};

// CharStack class
  // input the operator
class CharStack{
  private:
    int top;
    int max_size;
    char* stack;

  public:
    CharStack();
    CharStack(int size);
    ~CharStack();

    void Push(char item);
    char Pop();
    char Peek();
    bool IsEmpty();
};

int precedence(char op);
bool isOperator(char ch);

// change to postfix
// calculate the postfix
string makePostfix(string expression);
double eval(string postfix);

