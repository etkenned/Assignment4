#include <iostream>
#include "StudentNode.h"

using namespace std;

StudentNode::StudentNode()
{
  right = NULL;
  left = NULL;
  timeNeeded = 0;
  timeWaited = 0;
}
StudentNode::StudentNode(int tN, int tW)
{
  right = NULL;
  left = NULL;
  timeNeeded = tN;
  timeWaited = tW;
}
StudentNode::StudentNode(int w)
{
  right = NULL;
  left = NULL;
  timeNeeded = w;
  timeWaited = 0;
}
StudentNode::~StudentNode()
{

}
