#include "DoubleLinkedList.h"
#include <iostream>

using namespace std;

class Queue
{
  private:
    DoubleLinkedList line;
    int totalNumOfQueue;
  public:
    Queue();
    ~Queue();
    void pushToQueue(int w);
    void pushToQueue(int w, int tN); // sends a student into the Queue
    void popQueue(); // removes the next student in Queue
    void printTimeWaited();
    void advanceTimeWaited();
    int getTimeNeeded();
    int getTimeWaited();
    int getTotalNumOfQueue();
    bool isEmpty();


};
