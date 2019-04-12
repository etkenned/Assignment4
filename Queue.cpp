#include "Queue.h"
#include <iostream>

using namespace std;

Queue::Queue()
{
    line = DoubleLinkedList();
    totalNumOfQueue = 0;
}

Queue::~Queue()
{

}

void Queue::pushToQueue(int w)// sends a student into the queue at the end
{
  line.insertBack(w);
  totalNumOfQueue++;
}

void Queue::pushToQueue(int w, int tN)
{
  line.insertFront(w,tN);
  totalNumOfQueue++;
}

void Queue::popQueue()
{
    line.deleteFront();
}

void Queue::printTimeWaited()
{
  line.printWait();
}

void Queue::advanceTimeWaited()
{
  line.advanceTime();
}

int Queue::getTimeNeeded()
{
  return line.front->timeNeeded;
}
int Queue::getTimeWaited()
{
  return line.front->timeWaited;
}

int Queue::getTotalNumOfQueue()
{
  return totalNumOfQueue;
}
bool Queue::isEmpty()
{
  return line.isEmpty();
}
