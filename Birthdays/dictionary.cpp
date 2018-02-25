#include "dictionary.h"

Dictionary::Dictionary()
{
  //dict[SIZE];
  numItems = 0;
}

bool Dictionary::addEntry(Person newPerson)
{
  bool result = false;
  bool foundInsertPoint = false;

  if (numItems == 0)
  {
    dict[0] = &newPerson;
    numItems++;
    result = true;
  }
  else if (numItems == MAX_SIZE-1)
  {
    cout << "ERROR: Array is full, cannot add another entry." << endl;
    return false;
  }
  else
  {
    string searchKey = newPerson.getName(); 
    int i = 0;
    while (!foundInsertPoint && i < numItems)
    {
      if (searchKey < dict[i]->getName()) 
      {
        shiftArrayRight(i, numItems); 
        dict[i] = &newPerson; 
        numItems++;
        foundInsertPoint = true;
        result = true;
      }
      else if (i == numItems-1) 
      {
        dict[i+1] = &newPerson;
        numItems++;
        foundInsertPoint = true;
        result = true;
      }
      i++;
    }
  }

  return result;
}

bool Dictionary::removeEntry(string target)
{
  bool result = false;
  bool found = false;

  int i = 0;
  while (!found && i < numItems)
  {
    if (target == dict[i]->getName())
    {
      shiftArrayLeft(i, numItems);
      numItems--;
      result = true;
      found = true;
    }
    i++;
  }

  return result;
}

string Dictionary::getBirthdayForName(string target)
{
  string birthdayString;
  int searchResultIndex = binarySearch(target, 0, numItems-1);

  if(searchResultIndex == -1)
  {
    birthdayString = target + " not found...";
  }
  else
  {
    birthdayString = dict[searchResultIndex]->getBirthday();
  }

  return birthdayString;
}

void Dictionary::displayAllEntries()
{
  cout << "Displaying all " << numItems << " entries: " << endl;
  for (int i = 0; i < numItems; i++)
  {
    cout << dict[i]->getName() << " | " << dict[i]->getBirthday() << endl;
  }
}

void Dictionary::displayBornInMonth(string birthdayKey) 
{
  cout << "List of names of people born in " << birthdayKey << ": " << endl;
  string searchKey = makeLowercase(birthdayKey);
  for (int i = 0; i < numItems; i++)
  {
    if (searchKey == dict[i]->getBirthMonth(dict[i]->getBirthday()))
    {
      cout << dict[i]->getName() << " | " << dict[i]->getBirthday() << endl;
    }
  }
}

void Dictionary::shiftArrayRight(int start, int end)
{
  for (int i = end; i >= start; i--)
  {
    dict[i+1] = dict[i];
  }
}

void Dictionary::shiftArrayLeft(int start, int end)
{
  for (int i = start; i < end; i++)
  {
    dict[i] = dict[i+1];
  }
}

int Dictionary::binarySearch(string target, int left, int right)
{
  int numIterations = 0;
  while (left <= right)
  {
    int mid = (left + right) / 2;

    if (dict[mid]->getName() == target)
    {
      return mid;
    }
    else if (dict[mid]->getName() < target) // Case 2
    {
      left = mid + 1;
    }
    else // Case 3
    {
      right = mid - 1;
    }
  }

  return -1;
}

string Dictionary::makeLowercase(string s)
{
  string result;
  for (int i = 0; i < s.length(); i++)
  {
    result += tolower(s[i]);
  }
  return result;
}
