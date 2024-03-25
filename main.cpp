#include <iostream>
#include <queue>
#include <fstream>
#include <vector>


class Process
{
public:
    int arrivalTime;
    int cpuCycle;
    int jobId;

    Process(int aT, int cpu, int job) : arrivalTime(), cpuCycle(), jobId()
    {

    }
    Process() 
    {
        arrivalTime = 0;
        cpuCycle = 0;
        jobId = 0;
    }
};

bool operator<(const Process& p1, const Process& p2)
{
    return p1.arrivalTime > p2.arrivalTime;
}

void printVectors(std::vector<int> myVector)
{
    for (int vec : myVector)
    {
        std::cout << vec << " ";
    }
    std::cout << std::endl;
}

void printQueue(std::queue<int> myQueue)
{
    int queueSize = myQueue.size(); 
 
    std::queue<int> tempQueue = myQueue;

    
    for (int i = 0; i < queueSize; i++)
    {
        std::cout << tempQueue.front() << " "; 
        tempQueue.pop(); 
    }
}

void FCFS(const std::vector<Process*>& processes)
{
    std::queue<int> wait_times;
    std::queue<int> turn_around_times;

    int turn_around_time = 0;
    int wait_time = 0;
    int finish_time = 0;

    for (int i = 0; i < processes.size(); i++)
    {
        if (i == 0) {
            finish_time = processes[i]->cpuCycle + processes[i]->arrivalTime;
            turn_around_time = finish_time - processes[i]->arrivalTime;
            wait_time = turn_around_time - processes[i]->cpuCycle; 

            wait_times.push(wait_time);
            turn_around_times.push(turn_around_time);
        }
        else {
            finish_time += processes[i]->cpuCycle;
            turn_around_time = finish_time - processes[i]->arrivalTime;
            wait_time = turn_around_time - processes[i]->cpuCycle; 

            wait_times.push(wait_time);
            turn_around_times.push(turn_around_time);
        }
    }
    printQueue(wait_times);
    std::cout << std::endl;
    printQueue(turn_around_times);

}
 void SJN(const std::vector<Process*>& processes)
 {
     std::queue<int> wait_times;
     std::queue<int> turn_around_times;

     int turn_around_time = 0;
     int wait_time = 0;
     int finish_time = 0;
 }
 void SRT(const std::vector<Process*>& processes, bool contextSwitching)
 {

 }
 void RR(const std::vector<Process*>& processes, int QQ)
 {

 }
std::vector<int> createProcess(const char* fileName)
{
    std::vector<int> totalNumbers;
    std::ifstream file(fileName);
    int number;
    while (file >> number)
    {
        totalNumbers.push_back(number);
    }
    return totalNumbers;
}


int main()
{
    
    std::vector<int> numbers = createProcess("Process.txt");
    std::vector<int> arrivalTime;
    std::vector<int> cpuCycles;
    std::vector<int> jobID;
    std::vector<Process*> myProcesses;
    
    int numberofProcess = numbers[0];
    numbers.erase(numbers.begin());

    for (int i = 0; i < numbers.size(); i += 3) {
        jobID.push_back(numbers[i]);
        arrivalTime.push_back(numbers[i + 1]);
        cpuCycles.push_back(numbers[i + 2]);
    }

    for (int i = 0; i < numberofProcess; i++) 
    {
        Process* newProcess = new Process;
        myProcesses.push_back(newProcess);
    }

    for (int i = 0; i < numberofProcess; i++) 
    {
        myProcesses[i]->jobId = jobID[i];
        myProcesses[i]->arrivalTime = arrivalTime[i];
        myProcesses[i]->cpuCycle = cpuCycles[i];
    }

    //std::cout << "Numbers: ";
    //printVectors(numbers);

   // std::cout << "JobID: ";
   // printVectors(jobID);

   // std::cout << "ArrivalTime: ";
   //printVectors(arrivalTime);

    //std::cout << "CPU Cycles: ";
    //printVectors(cpuCycles);
    
    //for (int i = 0; i < numberofProcess; i++)
   // {
     //   std::cout << myProcesses[i]->jobId << " ";
     //   std::cout << myProcesses[i]->arrivalTime  << " ";
     //   std::cout << myProcesses[i]->cpuCycle << " " << std::endl;
    //
   // }
    FCFS(myProcesses);

    return 0;
}