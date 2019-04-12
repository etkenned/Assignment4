#include <iostream>
#include <fstream>
#include "StartSimulation.h"
using namespace std;

int main(int argc, char** argv)
{


  if(argc > 1) // checks for user input of file name
  {
    StartSimulation run = StartSimulation(argv[1]);
  }
  else
  {
    cout << "Please run the program again with a valid file name in the command line" << endl;
  }
}
