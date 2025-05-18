typedef int Element;

class Stack{
  private:
    int top;  // top(recent) index
    int max_size; // number of element
    Element* stack; // int*

  public:
    Stack(); // default Constructor
    Stack(int num); // Constructor
    ~Stack(); // Destructor

    bool IsFullS(); // check whether it is full
    bool IsEmptyS(); // check whether it is empty
    
    void Push(Element item); // add item
    Element Pop(); // return the value

    void Print() const; // print out the result
};