#include "queue.h" 
using namespace std;

bool queue::enqueue(char newEntry)
{
  bool result = false;
  if(count < MAX_QUEUE)
  {
    back = (back + 1) % MAX_QUEUE;
    entries[back] = newEntry;
    count++;
    result = true;
  }
  return result;
}


bool queue::dequeue()
{
  bool result = false;
  if(!isEmpty())
  {
    front = (front +1) % MAX_QUEUE;
    count--;
    result = true;
  }
  return result;
}

char queue::peek()
{
  if(!isEmpty())
  {
    return entries[front];
  }
}

bool queue::isEmpty()
{
  if(count == 0)
  {
    return true;
  }
  else
  {
    return false;
  }
}
