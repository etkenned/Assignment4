#include "Queue.h"
#include <iostream>

using namespace std;

class StartSimulation
{
  private:
    Queue windowLine;
    Queue data;
    int * Windows;
    int * windowData;
    int numWindows;
    bool nextStudent;
  public:
    StartSimulation();
    StartSimulation(string fileName);
    ~StartSimulation();

    void createWindow(int num);
    void TimePasses();
    void WindowQueue();
    void PrintStats();
    bool finish();
};
