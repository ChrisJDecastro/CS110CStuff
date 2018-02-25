#ifndef HEAP
#define HEAP

#include <iostream>
#include <string>
using namespace std;

const int SIZE = 10;

class Heap
{
private:
  string items[SIZE]; 
  int root;          
  int itemCount;      
  int maxItems;       

  void swap(string& item1, string& item2);
  bool isLeaf(int node);
  bool hasRightChild(int node);
 
public:
  Heap();
  bool add(string newData);
  string peekTop();
  bool remove();
  void heapRebuild(int rootIndex, string items[], int itemCount);
}; 

#endif
