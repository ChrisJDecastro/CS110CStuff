#include "stack.h"
using namespace std;

bool stack::isEmpty()
{
  if(top == 0)
  {
    return true;
  }
  else
  {
    return false;
  }
}

bool stack::push(char newEntry)
{
  bool result = false;
  if(top < SIZE)
  {
    result = true;
    aStack[top] = newEntry;
    top++;
  }
  return false;
}

bool stack::pop()
{
  bool result = false;
  if(top != 0)
  {
    result = true;
    aStack[top] = '\0';
    top--;
  }
  return result;
}

char stack::peek()
{
  if(top != 0)
  {
    return aStack[top-1];
  }
}
