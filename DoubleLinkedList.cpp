#include <iostream>
#include "DoubleLinkedList.h"

using namespace std;

DoubleLinkedList::DoubleLinkedList()
{
  front = NULL;
  back = NULL;
}

DoubleLinkedList::~DoubleLinkedList()
{
  while(front)//cycles through list and sets every node to NULL before deleting them
  {
    StudentNode* temp = front;
    front = front->right;
    temp->right = NULL;
    temp->left = NULL;
    delete temp;
  }
}

bool DoubleLinkedList::isEmpty()// checks if the list is empty
{
  if(front == NULL && front == back)
  {
    return true;
  }
  else
  {
    return false;
  }
}
void DoubleLinkedList::insertFront(int w)// adds a node to the list at the front
{
  if(front == NULL && back == NULL)
  {
    front = new StudentNode(w);
    back = front;
  }
  else
  {
    StudentNode* temp = new StudentNode(w);
    temp->right = front;
    front = temp;
  }
}
void DoubleLinkedList::insertFront(int w, int t)
{
  if(front == NULL && back == NULL)
  {
    front = new StudentNode(w, t);
    back = front;
  }
  else
  {
    StudentNode* temp = new StudentNode(w, t);
    temp->right = front;
    front = temp;
  }
}

StudentNode* DoubleLinkedList::deleteFront() // removes the front node from the list
{
  if(front != back)
  {
    StudentNode* temp = front;
    front = front->right;
    front->left = NULL;
    temp->right = NULL;
    temp->left = NULL;
    delete temp;
  }
  else
  {
    delete front;
    front = back;
    back = 0;
  }
}

void DoubleLinkedList::insertBack(int w) // adds a node the the back of the list
{
  if(front == NULL && back == NULL)
  {
    front = new StudentNode(w);
    back = front;
  }
  else
  {
    StudentNode* temp = new StudentNode(w);
    back->right = temp;
    back = temp;
  }
}

void DoubleLinkedList::printWait() //prints how long every student in the line has waited
{
  StudentNode* current = front;
  cout << "The wait time of every student in the line: ";
  while(current != NULL)
  {
    cout << current->timeWaited << ", ";
    current = current->right;
  }
  cout << endl;
}

void DoubleLinkedList::advanceTime() // advances time by one for every node in the list
{
  StudentNode * current = front;
  while(current != NULL)
  {
    current->timeWaited++;
    current = current->right;
  }
}
