#include <iostream>
#include <fstream>
#include "StartSimulation.h"

using namespace std;

StartSimulation::StartSimulation()
{
}
StartSimulation::StartSimulation(string fileName)
{
  data = Queue();
  windowLine = Queue();
  fstream inputFile(fileName);
  string line = "";
  if(inputFile.is_open())
  {
    int time = 0;
    getline(inputFile, line);
    createWindow(stoi(line)); // sets the number of open windows
    getline(inputFile, line);
    int setTime = stoi(line); // time when the students will arrive
    nextStudent = true;
    int lineNum = 0;
    while(true)
    {
      if(time == setTime)
      {
        nextStudent = false;
        getline(inputFile, line); // gets how many students are arriving at the set time
        lineNum = stoi(line);
        for(int i = 0; i < lineNum; i++)
        {
          getline(inputFile, line);
          windowLine.pushToQueue(stoi(line)); // sends the student into the queue
        }
        getline(inputFile, line);
        if(!inputFile.eof())
        {
          setTime = stoi(line);
        }
      }
      WindowQueue();
      windowLine.advanceTimeWaited();
      if(finish() && !nextStudent) // checks if the program has reached the end / run out of students
      {
        break;
      }
      TimePasses();
      time++;
    }
    PrintStats();
  }
}
StartSimulation::~StartSimulation()
{

}

void StartSimulation::createWindow(int num)
{
  numWindows = num;
  Windows = new int[num];
  windowData = new int[num];

  for(int i = 0; i < num; i++)
  {
    Windows[i] = 0;
    windowData[i] = 0;
  }
}

void StartSimulation::TimePasses() // advances time for the students at the windows
{
  for(int i = 0; i < numWindows; i++)
  {
    if(Windows[i] == 0)
      windowData[i]++;
  }
  for(int j = 0; j < numWindows; j++)
  {
    if(Windows[j] > 0)
    {
      Windows[j]--;
    }
  }
}
void StartSimulation::WindowQueue() // sends a student from the queue to an open window
{
  for(int i = 0; i < numWindows; i++)
  {
    if(Windows[i] == 0 && !windowLine.isEmpty())
    {
      Windows[i] = windowLine.getTimeNeeded();
      data.pushToQueue(windowLine.getTimeNeeded(), windowLine.getTimeWaited());
      windowLine.popQueue();
    }
  }
}

void StartSimulation::PrintStats()
{
  int numTotal = data.getTotalNumOfQueue();
  int stats[numTotal];
  float medianWait = 0.0;
  float meanWait = 0.0;
  int num10Wait = 0;
  int longestWait = 0;
  float meanWindowIdle = 0;
  int longestWindowIdle = 0;
  int numWindowIdle5 = 0;

  for(int i = 0; i < numTotal; i++)
  {
    stats[i] = data.getTimeWaited();
    data.popQueue();
  }

  for(int i = 0; i < numTotal; i++)
  {
    for(int j = i; j > 0 && stats[j-1] > stats[j]; j--)
    {
      int temp = stats[j];
      stats[j] = stats[j-1];
      stats[j-1] = temp;
    }
  }

  if(numTotal % 2 != 0) // finds the median wait time
  {
    medianWait = stats[numTotal/2];
  }
  else
  {
    medianWait = (stats[numTotal/2] + stats[numTotal/2 - 1]) / 2.0;
  }

  for(int i = 0; i < numTotal; i++) // finds the mean wait time for the students
  {
    meanWait += stats[i];
    if(stats[i] > 10) // counts how many students had to wait over 10 minutes
    {
      num10Wait ++;
    }
    if(stats[i] > longestWait) // finds the longest wait time
    {
      longestWait = stats[i];
    }
  }
  meanWait = meanWait / numTotal;

  for(int i = 0; i < numWindows; i++) // finds the mean wait time for idle windows
  {
    meanWindowIdle += windowData[i];
    if(windowData[i] > longestWindowIdle) // finds the longest window idle time
    {
      longestWindowIdle = windowData[i];
    }
    if(windowData[i] > 5) // counts how many windows go idle for longer than 5 minutes
    {
      numWindowIdle5++;
    }
  }
  meanWindowIdle = meanWindowIdle / numWindows;
  cout << "STATS" << endl;
  cout << "mean student wait time : " << meanWait << endl;
  cout << "median student wait time : " << medianWait << endl;
  cout << "longest student wait time : " << longestWait << endl;
  cout << "number of students waiting longer than 10 minutes : " << num10Wait << endl;
  cout << "mean window idle time : " << meanWindowIdle << endl;
  cout << "longest window idle time : " << longestWindowIdle << endl;
  cout << "number of windows idle over 5 minutes : " << numWindowIdle5 << endl;
}

bool StartSimulation::finish()
{
  for(int i = 0; i < numWindows; i++)
  {
    if(Windows[i] != 0)
    {
      return false;
    }
  }
  return true;
}
