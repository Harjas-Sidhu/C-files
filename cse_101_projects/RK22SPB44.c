/*




    ----------------------------------------
    |  CA2: OS Simulation-Based Project    |
    ----------------------------------------
    | Author: Harjaspal Singh              |
    ----------------------------------------
    | Registration Number: 12219588        |
    ----------------------------------------
    | Roll Number: RK22SPB44               |
    ----------------------------------------
    | Section: K22SP                       |
    ----------------------------------------
    | Course Code: CSE316                  |
    ----------------------------------------



*/    


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

//Defines a constant `MAX_SIZE` to set the maximum size for queues and arrays.

#define MAX_SIZE 100


//Defines a struct `Process` to represent process details, including ProcessId, ArrivalTime, BurstTime, WaitingTime, 
//CompletionTime, TurnAroundTime, and a flag `IsCompleted`.
struct Process
{
    int ProcessId;
    int ArrivalTime;
    int BurstTime;
    int WaitingTime;
    int CompletionTime;
    int TurnAroundTime;
    bool IsCompleted;
};

//Defines a struct `Results` to store the results of simulation, including average waiting time, 
//average turnaround time, the number of processes completed, time quantum used, and total time taken.

struct Results
{
    float AvgWaitingTime;
    float AvgTurnAroundTime;
    int NoOfProcessesCompleted;
    int TimeQuantum;
    int TimeTaken;
};

//Defines a struct `Queue` to represent a queue data structure for processes with a circular array 
//of processes and front/rear indices.

struct Queue
{
    struct Process Processes[MAX_SIZE];
    int front;
    int rear;
};

//Initializes the queue by setting the front and rear indices and initializing the process data in the array.

void initializeQueue(struct Queue *q)
{
    q->front = -1;
    q->rear = -1;
    for (int i = 0; i < MAX_SIZE; i++)
    {
        q->Processes[i].ProcessId = 0;
        q->Processes[i].IsCompleted = false;
        q->Processes[i].ArrivalTime = 0;
        q->Processes[i].WaitingTime = 0;
        q->Processes[i].TurnAroundTime = 0;
        q->Processes[i].CompletionTime = 0;
        q->Processes[i].BurstTime = 0;
    }
}

//Checks if the queue is empty by comparing the front index with -1.

int isEmpty(struct Queue *q)
{
    return (q->front == -1);
}

//Adds a process to the queue by updating the rear and placing the process in the array.

void enqueue(struct Queue *q, struct Process ProcessToEnqueue)
{
    if (isEmpty(q))
    {
        q->front = q->rear = 0;
    }
    else
    {
        q->rear = (q->rear + 1) % MAX_SIZE;
    }
    q->Processes[q->rear] = ProcessToEnqueue;
}

//Removes a process from the queue by updating the front index and returning the dequeued process.

struct Process dequeue(struct Queue *q)
{
    struct Process DequeuedProcess;
    DequeuedProcess = q->Processes[q->front];
    if (q->front == q->rear)
    {
        q->front = q->rear = -1;
    }
    else
    {
        q->front = (q->front + 1) % MAX_SIZE;
    }
    return DequeuedProcess;
}

//Finds a process in the queue by comparing ProcessId and returns its index.

int found(struct Queue *q, struct Process TargetProcess)
{
    if (isEmpty(q))
    {
        return -1;
    }

    int current = q->front;

    while (current != (q->rear + 1) % MAX_SIZE)
    {
        if (q->Processes[current].ProcessId == TargetProcess.ProcessId)
        {
            return current;
        }
        current = (current + 1) % MAX_SIZE;
    }

    return -1;
}

//Sorts an array of processes based on their ArrivalTime in ascending order.

void SortProcessesByArrivalTime(struct Process ProcessTable[], int NumOfProcesses)
{
    for (int i = 0; i < NumOfProcesses; i++)
    {
        struct Process KeyProcess = ProcessTable[i];
        int j = i - 1;
        while (j >= 0 && KeyProcess.ArrivalTime < ProcessTable[j].ArrivalTime)
        {
            ProcessTable[j + 1] = ProcessTable[j];
            j -= 1;
        }
        ProcessTable[j + 1] = KeyProcess;
    }
}

//Simulates the Round Robin scheduling algorithm using the provided process data and parameters. 
//It returns the simulation results.

struct Results SimulateRoundRobin(struct Process ProcessTable[], int NumOfProcesses, int TotalSimulationTime, int TimeQuantum)
{

    SortProcessesByArrivalTime(ProcessTable, NumOfProcesses);

    int TimeSpent = ProcessTable[0].ArrivalTime;
    int InitialBurstTimes[NumOfProcesses];

    for (int i = 0; i < NumOfProcesses; i++)
    {
        InitialBurstTimes[i] = ProcessTable[i].BurstTime;
    }

    struct Queue JobQueue;
    initializeQueue(&JobQueue);

    struct Results Solution;
    Solution.TimeQuantum = TimeQuantum;
    Solution.NoOfProcessesCompleted = 0;
    Solution.AvgTurnAroundTime = 0;
    Solution.AvgWaitingTime = 0;
    Solution.TimeTaken = 0;

    while (TimeSpent < TotalSimulationTime)
    {

        for (int i = 0; i < NumOfProcesses; i++)
        {
            struct Process AvailableProcess = ProcessTable[i];

            if (!AvailableProcess.IsCompleted && TimeSpent >= AvailableProcess.ArrivalTime && found(&JobQueue, AvailableProcess) == -1)
            {
                enqueue(&JobQueue, AvailableProcess);
            }
        }

        if (isEmpty(&JobQueue))
        {
            TimeSpent += 1;
            continue;
        }

        struct Process DequeuedProcess = dequeue(&JobQueue);

        int ExecuteTime = (DequeuedProcess.BurstTime > TimeQuantum) ? TimeQuantum : DequeuedProcess.BurstTime;

        DequeuedProcess.BurstTime -= ExecuteTime;
        TimeSpent += ExecuteTime;

        if (DequeuedProcess.BurstTime <= 0)
        {
            DequeuedProcess.IsCompleted = true;
            DequeuedProcess.CompletionTime = TimeSpent;
        }

        for (int i = 0; i < NumOfProcesses; i++)
        {
            if (ProcessTable[i].ProcessId == DequeuedProcess.ProcessId)
            {
                ProcessTable[i] = DequeuedProcess;
                break;
            }
        }
        for (int i = 0; i < NumOfProcesses; i++)
        {
            struct Process AvailableProcess = ProcessTable[i];

            if (AvailableProcess.ProcessId != DequeuedProcess.ProcessId)
            {
                if (found(&JobQueue, AvailableProcess) == -1 && TimeSpent >= AvailableProcess.ArrivalTime)
                {
                    if (AvailableProcess.BurstTime > 0 && AvailableProcess.CompletionTime == 0)
                    {
                        enqueue(&JobQueue, AvailableProcess);
                    }
                }
            }
        }
    }

    for (int i = 0; i < NumOfProcesses; i++)
    {
        ProcessTable[i].BurstTime = InitialBurstTimes[i];

        if (ProcessTable[i].IsCompleted)
        {
            ProcessTable[i].TurnAroundTime = ProcessTable[i].CompletionTime - ProcessTable[i].ArrivalTime;
            ProcessTable[i].WaitingTime = ProcessTable[i].TurnAroundTime - ProcessTable[i].BurstTime;

            Solution.AvgTurnAroundTime += ProcessTable[i].TurnAroundTime;
            Solution.AvgWaitingTime += ProcessTable[i].WaitingTime;

            Solution.NoOfProcessesCompleted += 1;

            if(Solution.TimeTaken < ProcessTable[i].CompletionTime){
                Solution.TimeTaken = ProcessTable[i].CompletionTime;
            }
        }
    }

    Solution.AvgTurnAroundTime /= NumOfProcesses;
    Solution.AvgWaitingTime /= NumOfProcesses;

    return Solution;
}

//Generates a random Time Quantum, then calls `SimulateRoundRobin` with the random time quantum and returns the results.

struct Results SimulateRandomRoundRobin(struct Process ProcessTable[], int NumOfProcesses, int TotalSimulationTime)
{
    int TimeQuantum = rand() % 10 + 1;
    return SimulateRoundRobin(ProcessTable, NumOfProcesses, TotalSimulationTime, TimeQuantum);
}

//Generates a random process table with the specified number of processes and returns it.

struct Process *GenerateRandomProcessTable(int NumOfProcesses)
{
    struct Process *ProcessTable = (struct Process *)malloc(NumOfProcesses * sizeof(struct Process));

    for (int i = 0; i < NumOfProcesses; i++)
    {
        ProcessTable[i].ProcessId = i + 1;
        ProcessTable[i].CompletionTime = 0;
        ProcessTable[i].IsCompleted = 0;
        ProcessTable[i].TurnAroundTime = 0;
        ProcessTable[i].WaitingTime = 0;
        ProcessTable[i].ArrivalTime = rand() % 30 + 5;
        ProcessTable[i].BurstTime = rand() % 30 + 5;
    }

    return ProcessTable;
}

//Resets process data (IsCompleted, CompletionTime, WaitingTime, TurnAroundTime) for a given array of processes.

void ResestProcessTable(struct Process ProcessTable[], int NumOfProcesses)
{
    for (int i = 0; i < NumOfProcesses; i++)
    {
        ProcessTable[i].IsCompleted = false;
        ProcessTable[i].CompletionTime = 0;
        ProcessTable[i].WaitingTime = 0;
        ProcessTable[i].TurnAroundTime = 0;
    }
}

//Simulates the First-Come-First-Serve (FCFS) scheduling algorithm and returns the results.

struct Results FirstComeFirstServe(struct Process ProcessTable[], int NumOfProcesses, int TotalSimulationTime)
{
    SortProcessesByArrivalTime(ProcessTable, NumOfProcesses);

    int TimeSpent = ProcessTable[0].ArrivalTime;

    struct Results Answer;
    Answer.NoOfProcessesCompleted = 0;
    Answer.AvgTurnAroundTime = 0;
    Answer.AvgWaitingTime = 0;
    Answer.TimeTaken = 0;
    Answer.TimeQuantum = 0;

    for (int i = 0; i < NumOfProcesses; i++)
    {
        if (TimeSpent >= TotalSimulationTime)
        {
            break;
        }

        TimeSpent += ProcessTable[i].BurstTime;
        ProcessTable[i].IsCompleted = true;
        ProcessTable[i].CompletionTime = TimeSpent;
        ProcessTable[i].WaitingTime = TimeSpent - ProcessTable[i].ArrivalTime - ProcessTable[i].BurstTime;
        ProcessTable[i].TurnAroundTime = ProcessTable[i].BurstTime;
    }

    for (int i = 0; i < NumOfProcesses; i++)
    {
        if (ProcessTable[i].IsCompleted)
        {
            Answer.NoOfProcessesCompleted += 1;
            Answer.AvgWaitingTime += ProcessTable[i].WaitingTime;
            Answer.AvgTurnAroundTime += ProcessTable[i].TurnAroundTime;
            if (ProcessTable[i].CompletionTime > Answer.TimeTaken)
            {
                Answer.TimeTaken = ProcessTable[i].CompletionTime;
            }
        }
        Answer.AvgWaitingTime /= NumOfProcesses;
        Answer.AvgTurnAroundTime /= NumOfProcesses;
    }

    return Answer;
}

//Simulates the Shortest Job First (SJF) scheduling algorithm and returns the results.

struct Results ShortestJobFirst(struct Process ProcessTable[], int NumOfProcesses, int TotalSimulationTime)
{
    SortProcessesByArrivalTime(ProcessTable, NumOfProcesses);

    int TimeSpent = ProcessTable[0].ArrivalTime;

    struct Results Answer;
    Answer.NoOfProcessesCompleted = 0;
    Answer.AvgTurnAroundTime = 0;
    Answer.AvgWaitingTime = 0;
    Answer.TimeTaken = 0;
    Answer.TimeQuantum = 0;

    while (TimeSpent < TotalSimulationTime)
    {

        struct Process KeyProcess;
        KeyProcess.BurstTime = 1000;

        for (int i = 0; i < NumOfProcesses; i++)
        {
            if (!ProcessTable[i].IsCompleted && TimeSpent >= ProcessTable[i].ArrivalTime)
            {
                if (KeyProcess.BurstTime > ProcessTable[i].BurstTime)
                {
                    KeyProcess = ProcessTable[i];
                }
            }
        }

        if (KeyProcess.BurstTime == 1000)
        {
            break;
        }

        TimeSpent += KeyProcess.BurstTime;
        KeyProcess.IsCompleted = true;
        KeyProcess.CompletionTime = TimeSpent;

        for (int i = 0; i < NumOfProcesses; i++)
        {
            if (ProcessTable[i].ProcessId == KeyProcess.ProcessId)
            {
                ProcessTable[i] = KeyProcess;
                break;
            }
        }
    }

    for (int i = 0; i < NumOfProcesses; i++)
    {
        ProcessTable[i].TurnAroundTime = ProcessTable[i].CompletionTime - ProcessTable[i].ArrivalTime;
        ProcessTable[i].WaitingTime = ProcessTable[i].TurnAroundTime - ProcessTable[i].BurstTime;

        if (ProcessTable[i].IsCompleted)
        {
            Answer.NoOfProcessesCompleted += 1;
            Answer.AvgWaitingTime += ProcessTable[i].WaitingTime;
            Answer.AvgTurnAroundTime += ProcessTable[i].TurnAroundTime;
            if (ProcessTable[i].CompletionTime > Answer.TimeTaken)
            {
                Answer.TimeTaken = ProcessTable[i].CompletionTime;
            }
        }
        Answer.AvgWaitingTime /= NumOfProcesses;
        Answer.AvgTurnAroundTime /= NumOfProcesses;
    }

    return Answer;
}

//Displays simulation results for Round Robin, FCFS, and SJF, 
//including process details and a comparison of scheduling algorithms. It waits for user input to continue.

void showSimulationData(struct Process ProcessTable[], int NumOfProcesses, struct Results RR)
{
    system("cls");
    printf("\n\x1b[33m==========\x1b[0m Simulation Results \x1b[33m==========\x1b[0m\n\n");
    printf("\x1b[31m=====\x1b[0m Round Robin \x1b[31m=====\x1b[0m\n\n");
    printf("ProcessId\tArrivalTime\tBurstTime\tWaitingTime\tTurnAroundTime\tCompletionTime\n");

    for (int i = 0; i < NumOfProcesses; i++)
    {
        for (int j = 0; j < NumOfProcesses; j++)
        {
            if (ProcessTable[j].ProcessId == i + 1)
            {
                printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",
                       ProcessTable[j].ProcessId, ProcessTable[j].ArrivalTime, ProcessTable[j].BurstTime,
                       ProcessTable[j].WaitingTime, ProcessTable[j].TurnAroundTime, ProcessTable[j].CompletionTime);
                break;
            }
        }
    }
    printf("\nTime Quantum: %d\n\n", RR.TimeQuantum);
    ResestProcessTable(ProcessTable, NumOfProcesses);
    struct Results FCFS = FirstComeFirstServe(ProcessTable, NumOfProcesses, 1000);
    printf("\x1b[31m=====\x1b[0m FCFS \x1b[31m=====\x1b[0m\n\n");
    printf("ProcessId\tArrivalTime\tBurstTime\tWaitingTime\tTurnAroundTime\tCompletionTime\n");

    for (int i = 0; i < NumOfProcesses; i++)
    {
        for (int j = 0; j < NumOfProcesses; j++)
        {
            if (ProcessTable[j].ProcessId == i + 1)
            {
                printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",
                       ProcessTable[j].ProcessId, ProcessTable[j].ArrivalTime, ProcessTable[j].BurstTime,
                       ProcessTable[j].WaitingTime, ProcessTable[j].TurnAroundTime, ProcessTable[j].CompletionTime);
                break;
            }
        }
    }
    ResestProcessTable(ProcessTable, NumOfProcesses);
    struct Results SJF = ShortestJobFirst(ProcessTable, NumOfProcesses, 1000);
    printf("\n\x1b[31m=====\x1b[0m SJF \x1b[31m=====\x1b[0m\n\n");
    printf("ProcessId\tArrivalTime\tBurstTime\tWaitingTime\tTurnAroundTime\tCompletionTime\n");

    for (int i = 0; i < NumOfProcesses; i++)
    {
        for (int j = 0; j < NumOfProcesses; j++)
        {
            if (ProcessTable[j].ProcessId == i + 1)
            {
                printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",
                       ProcessTable[j].ProcessId, ProcessTable[j].ArrivalTime, ProcessTable[j].BurstTime,
                       ProcessTable[j].WaitingTime, ProcessTable[j].TurnAroundTime, ProcessTable[j].CompletionTime);
                break;
            }
        }
    }

    printf("\n\n\x1b[33m==========\x1b[0m Scheduling Algorithm Comparison \x1b[33m==========\x1b[0m\n\n");
    printf("\n\x1b[31m==============================\x1b[0m Comparison \x1b[31m==============================\x1b[0m\n");
    printf("| Metric                 | Round Robin       | FCFS              | SJF               |\n");
    printf("|------------------------|-------------------|-------------------|-------------------|\n");
    printf("| Average Waiting Time   | %.2f              | %.2f              | %.2f              |\n", RR.AvgWaitingTime, FCFS.AvgWaitingTime, SJF.AvgWaitingTime);
    printf("| Average Turnaround Time| %.2f              | %.2f              | %.2f              |\n", RR.AvgTurnAroundTime, FCFS.AvgTurnAroundTime, SJF.AvgTurnAroundTime);
    printf("| Processes Completed    | %d                  | %d                  | %d                  |\n", RR.NoOfProcessesCompleted, FCFS.NoOfProcessesCompleted, SJF.NoOfProcessesCompleted);
    printf("| Time Taken             | %d                  | %d                  | %d                  |\n", RR.TimeTaken, FCFS.TimeTaken, SJF.TimeTaken);
    printf("=============================================================================================\n");
    printf("\nPress Enter to return to the main menu...");
    while (getchar() != '\n');
    getchar();
}

//Displays the main menu for the user to select simulation options.

void printMenu()
{
    system("cls");
    printf("\n\x1b[33m==========\x1b[0m Process Scheduling Simulation \x1b[33m==========\x1b[0m\n\n");
    printf("1. Custom Input\n");
    printf("2. Random Input\n");
    printf("3. Quit\n");
    printf("Enter your choice: ");
}

//Gets custom input from the user and simulates the Round Robin algorithm.

void generateRandomInputAndSimulate()
{
    system("cls");
    int NumOfProcesses = rand() % 10;
    NumOfProcesses = NumOfProcesses < 5 ? 5 : NumOfProcesses;
    struct Process *ProcessTable = GenerateRandomProcessTable(NumOfProcesses);
    struct Results Answer = SimulateRandomRoundRobin(ProcessTable, NumOfProcesses, 1000);
    showSimulationData(ProcessTable, NumOfProcesses, Answer);
}

//Generates random input and simulates the Round Robin algorithm.

void getCustomInput()
{
    system("cls");
    printf("\x1b[31m=====\x1b[0m Custom Input \x1b[31m=====\x1b[0m\n\n");
    int NumOfProcesses = 0;
    printf("Enter the number of processes: ");
    scanf("%d", &NumOfProcesses);

    struct Process ProcessTable[NumOfProcesses];

    for (int i = 0; i < NumOfProcesses; i++)
    {
        ProcessTable[i].IsCompleted = false;
        ProcessTable[i].CompletionTime = 0;
        ProcessTable[i].WaitingTime = 0;
        ProcessTable[i].TurnAroundTime = 0;
        ProcessTable[i].ProcessId = i + 1;
        printf("\nArrivalTime for Process %d: ", i + 1);
        scanf("%d", &ProcessTable[i].ArrivalTime);
        printf("BurstTime for Process %d: ", i + 1);
        scanf("%d", &ProcessTable[i].BurstTime);
    }

    int TimeQuantum = 0;
    printf("\nEnter the Time Quantum: ");
    scanf("%d", &TimeQuantum);

    struct Results Answer = SimulateRoundRobin(ProcessTable, NumOfProcesses, 1000, TimeQuantum);
    showSimulationData(ProcessTable, NumOfProcesses, Answer);
}


//The main function initializes randomization, provides a menu for user choices, 
//and calls the appropriate functions based on the user's selection.

int main()
{
    srand((unsigned int)time(NULL));

    int choice;

    while (1)
    {
        system("cls");
        printMenu();

        choice = 0;
        scanf("%d", &choice);

        switch ((int)choice)
        {
        case 1:
            getCustomInput();
            break;
        case 2:
            generateRandomInputAndSimulate();
            break;
        case 3:
            system("cls");
            printf("Goodbye!\n");
            exit(0);
        default:
            printf("Invalid choice. Please try again.\n");
            break;
        }
    }

    return 0;
}

//The code mainly focuses on simulating different process scheduling algorithms (Round Robin, FCFS, and SJF) 
//and allows the user to choose between custom input or random input for simulation. 
//The results are then displayed, including process details and a comparison of scheduling algorithms.