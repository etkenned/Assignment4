#include <iostream>

using namespace std;

class StudentNode
{
  public:
    StudentNode();
    StudentNode(int tN, int tW);
    StudentNode(int w);
    ~StudentNode();

    StudentNode * right;
    StudentNode * left;

    int timeNeeded; // how much time the student needs at the window
    int timeWaited;// how much tme the student has waited to get to a window
};
