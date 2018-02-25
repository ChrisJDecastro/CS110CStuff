#include "heap.h" // Header file

Heap::Heap()
{
  root = itemCount = 0;
  maxItems = SIZE;
} 

bool Heap::add(string newData)
{
  if (itemCount == maxItems)
  {
    return false;
  }

  items[itemCount] = newData;

  int newDataIndex = itemCount;
  bool inPlace = false;
  while ((newDataIndex > 0) && !inPlace)
  {
    int parentIndex = (newDataIndex - 1) / 2;
    if (items[newDataIndex] < items[parentIndex])
    {
      inPlace = true;
    }
    else
    {
      swap(items[newDataIndex], items[parentIndex]);
      newDataIndex = parentIndex;
    }
  }
  itemCount++;
  return true;
} 

string Heap::peekTop()
{
  return items[0];
} 

bool Heap::remove()
{
  if (itemCount == 0)
  {
    return false;
  }

  items[0] = items[itemCount-1];
  items[itemCount-1];       
  itemCount--;

  heapRebuild(0, items, itemCount);
  return true;
}

void Heap::heapRebuild(int rootIndex, string items[], int itemCount)
{
  if (!isLeaf(rootIndex))
  {
    int largerChildIndex = 2 * rootIndex + 1; 

    if (hasRightChild(rootIndex))
    {
      int rightChildIndex = 2 * rootIndex + 2; 
      if (items[rightChildIndex] > items[largerChildIndex])
      {
        swap(items[rightChildIndex], items[largerChildIndex]);
      }
    }

    if (items[rootIndex] < items[largerChildIndex])
    {
      swap(items[rootIndex], items[largerChildIndex]);
      heapRebuild(largerChildIndex, items, itemCount);
    }
  }
}

void Heap::swap(string& item1, string& item2)
{
  string temp = item1;
  item1 = item2;
  item2 = temp;
}

bool Heap::isLeaf(int node)
{
  bool result;
  if((items[(2 * node) + 1] != "") || (hasRightChild(node)))
  {
  result = false;
  }
  else 
  {
    result = true;
  }
  return result;
} 

bool Heap::hasRightChild(int node)
{
  bool result;
  if(items[(2 * node) + 2] == "")
  {
    result = false;
  }
  else
  {
    result = true;
  }
  return result;
}
