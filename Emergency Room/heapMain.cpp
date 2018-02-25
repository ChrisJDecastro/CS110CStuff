#include "heap.h"
#include <iostream>
using namespace std;

int main()
{

  Heap ER;
  ER.add("5 Bob");
  ER.add("9 Mary");
  ER.add("1 Max");
  cout << ER.peekTop() << " will now see the doctor.\n";
  ER.remove();
  ER.add("3 Julio");
  ER.add("7 Stacy");
  ER.add("4 Paul");
  ER.add("2 Reiko");
  ER.add("6 Jennifer");
  ER.add("5 Chang");
  cout << ER.peekTop() << " will now see the doctor.\n";
  ER.remove();
  cout << ER.peekTop() << " will now see the doctor.\n";
  ER.remove();
  cout << ER.peekTop() << " will now see the doctor.\n";
  ER.remove();
}
