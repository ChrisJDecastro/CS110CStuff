#ifndef QUEUE
#define QUEUE

const int MAX_QUEUE = 101;

class queue 
{
  private:
    char entries[MAX_QUEUE];
    int front;
    int back;
    int count; 
  public:
    queue()
    {
      front = 0;
      back = MAX_QUEUE-1;
      count = 0;
    }

    bool enqueue(char newEntry);
    bool dequeue();
    char peek();
    bool isEmpty();
};

#endif
