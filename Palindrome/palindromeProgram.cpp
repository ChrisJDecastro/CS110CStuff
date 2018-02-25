#include "stack.h"
#include "queue.h"
#include <iostream>
#include <string>

using namespace std;

bool palindromeChecker(string aString)
{
  stack aStack;
  queue aQueue;
  bool result = false;
  
  for(int i = 0;i<aString.length();i++)
  {
    aStack.push(aString[i]);
    aQueue.enqueue(aString[i]);
  }
  for(int i =0;i<aString.length();i++)
  {
    if(aStack.peek() == aQueue.peek())
    {
      aStack.pop();
      aQueue.dequeue();
      result = true;      
    }
    else 
    {
      result = false;
    }
  }
  return result;
}

int main()
{
  string word;

  cout << "Please enter a string to determine if it's a palinedrome." << endl;
  cin >> word;

  if(palindromeChecker(word))
  {
    cout << endl;
    cout << word << " is a palindrome." << endl;
  }
  else
  {
    cout << endl;
    cout <<  word  << " is not a palindrome." << endl;
  }  
}
