#ifndef DICTIONARY
#define DICTIONARY

#include "person.h"
#include <string>
#include <cctype>

const int MAX_SIZE = 7;

class Dictionary
{
private:
  Person* dict[MAX_SIZE];
  int numItems;
  void shiftArrayRight(int start, int end);
  void shiftArrayLeft(int start, int end);
  int binarySearch(string target, int left, int right);
  string makeLowercase(string s);
public:
  Dictionary();
  bool addEntry(Person newPerson);
  bool removeEntry(string target);
  string getBirthdayForName(string target);
  void displayAllEntries();
  void displayBornInMonth(string birthdayKey);
};

#endif
