#include "person.h"
#include "dictionary.h"

int main()
{
  int numPeople = 7;
  string names[] = {"Chris", "Christian", "Reggie", "Luke", "Kyle", "Chiong", "Ari"};
  string birthdays[] = {"January 14, 1997", "August 24, 1996", "July 24, 1997",
                        "Jan 2, 1923", "May 20, 2919", "May 14, 2014", "May 8, 1988"};
  Dictionary birthdayDict;

  cout << "MAX NUMBER OF ITEMS ALLOWED IN DICTIONARY: 6" << endl;

  cout << "Testing addEntry: " << names[0] << endl;
  birthdayDict.addEntry(Person(names[0], birthdays[0]));
  birthdayDict.displayAllEntries();
  cout << endl;

  cout << "Testing addEntry: " << names[1] << endl;
  birthdayDict.addEntry(Person(names[1], birthdays[1]));
  birthdayDict.displayAllEntries();
  cout << endl;

  cout << "Testing addEntry: " << names[2] << endl;
  birthdayDict.addEntry(Person(names[2], birthdays[2]));
  birthdayDict.displayAllEntries();
  cout << endl;

  cout << "Testing addEntry: " << names[3] << endl;
  birthdayDict.addEntry(Person(names[3], birthdays[3]));
  birthdayDict.displayAllEntries();
  cout << endl;

  cout << "Testing addEntry: " << names[4] << endl;
  birthdayDict.addEntry(Person(names[4], birthdays[4]));
  birthdayDict.displayAllEntries();
  cout << endl;

  cout << "Testing addEntry: " << names[5] << endl;
  birthdayDict.addEntry(Person(names[5], birthdays[5]));
  birthdayDict.displayAllEntries();
  cout << endl;

  cout << "Testing addEntry: " << names[6] << endl;
  birthdayDict.addEntry(Person(names[6], birthdays[6]));
  birthdayDict.displayAllEntries();
  cout << endl;

  cout << "Testing search dictionary for the birthday of Chris: " << birthdayDict.getBirthdayForName("Chris") << endl;
  cout << "Testing search dictionary for the birthday of Gary: " << birthdayDict.getBirthdayForName("Gary") << endl << endl;

  birthdayDict.displayBornInMonth("May");
  birthdayDict.displayBornInMonth("January");
  birthdayDict.displayBornInMonth("July");

  cout << endl << "TESTING REMOVE, removing Chris:" << endl;
  birthdayDict.removeEntry("Chris");
  birthdayDict.displayAllEntries();
  cout << endl;

  cout << endl << "TESTING REMOVE, removing Reggie:" << endl;
  birthdayDict.removeEntry("Reggie");
  birthdayDict.displayAllEntries();
  cout << endl;

  cout << endl << "TESTING REMOVE, removing Christian:" << endl;
  birthdayDict.removeEntry("Christian");
  birthdayDict.displayAllEntries();
  cout << endl;

  cout << endl << "TESTING REMOVE, removing Luke:" << endl;
  birthdayDict.removeEntry("Luke");
  birthdayDict.displayAllEntries();
  cout << endl;

  cout << endl << "TESTING REMOVE, removing Chiong:" << endl;
  birthdayDict.removeEntry("Chiong");
  birthdayDict.displayAllEntries();
  cout << endl;

  return 0;
}
