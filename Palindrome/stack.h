#ifndef STACK
#define STACK

const int SIZE = 100;

class stack
{ 
  private:
    char aStack[SIZE];
    int top;
  public:
    stack()
    { top =0; }
    bool isEmpty();
    bool push(char newEntry);
    bool pop();
    char peek();
};
#endif
