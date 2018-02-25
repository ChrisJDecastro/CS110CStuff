#include "person.h"
#include <cctype>

Person::Person(string n, string b)
{
  name = n;
  birthday = b;
}

string Person::getName()
{
  return name;
}

string Person::getBirthday()
{
  return birthday;
}

string Person::getBirthMonth(string bday)
{
  string birthMonth = "";
  int i = 0;
  while (!isspace(bday[i]) && (i < bday.length()))
  {
    birthMonth += tolower(bday[i]);
    i++;
  }

  return birthMonth;
}

bool Person::isSameBirthMonth(string bday)
{
  string birthMonth1, birthMonth2;
  bool result;

  birthMonth1 = getBirthMonth(birthday);
  birthMonth2 = getBirthMonth(bday);

  if(birthMonth2 == birthMonth1)
  {
    result = true; 
  }
  else
  {
    result = false;
  }

  return result;
}
