#ifndef _PERSON
#define _PERSON

#include <iostream>
#include <string>
using namespace std;

class Person
{
private:
  string name;
  string birthday;
public:
  Person(string name, string birthday);
  string getName();                   
  string getBirthday();                
  string getBirthMonth(string bday);               
  bool isSameBirthMonth(string bday);   
}; 

#endif
