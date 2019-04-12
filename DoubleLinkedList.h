#include <iostream>
#include "StudentNode.h"

using namespace std;

class DoubleLinkedList
{
  public:
    DoubleLinkedList();
    ~DoubleLinkedList();

    bool isEmpty();
    void insertFront(int w);
    void insertFront(int w, int t);
    StudentNode * deleteFront();
    void insertBack(int w);
    void printWait();
    void advanceTime();

    StudentNode * front;
    StudentNode * back;

};
