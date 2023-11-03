#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define MAX_SIZE 100

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

struct Results
{
    float AvgWaitingTime;
    float AvgTurnAroundTime;
    int NoOfProcessesCompleted;
    int TimeQuantum;
    int TimeTaken;
};

struct Queue
{
    struct Process Processes[MAX_SIZE];
    int front;
    int rear;
};

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

int isEmpty(struct Queue *q)
{
    return (q->front == -1);
}

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
        }
    }

    Solution.AvgTurnAroundTime /= NumOfProcesses;
    Solution.AvgWaitingTime /= NumOfProcesses;

    return Solution;
}

struct Results SimulateRandomRoundRobin(struct Process ProcessTable[], int NumOfProcesses, int TotalSimulationTime)
{
    int TimeQuantum = rand() % 10 + 1;
    return SimulateRoundRobin(ProcessTable, NumOfProcesses, TotalSimulationTime, TimeQuantum);
}

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

void clearScreen()
{
    printf("\033[H\033[J");
}

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

struct Results FirstComeFirstServe(struct Process ProcessTable[], int NumOfProcesses, int TotalSimulationTime)
{
    SortProcessesByArrivalTime(ProcessTable, NumOfProcesses);

    int TimeSpent = ProcessTable[0].ArrivalTime;
    int CurrentProcess = 0;

    struct Results Answer;

    while (TimeSpent < TotalSimulationTime)
    {
        TimeSpent += ProcessTable[CurrentProcess].BurstTime;
        ProcessTable[CurrentProcess].IsCompleted = true;
        ProcessTable[CurrentProcess].CompletionTime = TimeSpent;
        ProcessTable[CurrentProcess].WaitingTime = TimeSpent - ProcessTable[CurrentProcess].BurstTime - ProcessTable[CurrentProcess].ArrivalTime;
        ProcessTable[CurrentProcess].TurnAroundTime = ProcessTable[CurrentProcess].WaitingTime + ProcessTable[CurrentProcess].BurstTime;
        CurrentProcess++;
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


void showSimulationData(struct Process ProcessTable[], int NumOfProcesses, struct Results Answer)
{
    clearScreen();
    printf("\x1b[33m========== Simulation Results ==========\x1b[0m\n\n");
    printf("\x1b[31m===== Round Robin =====\x1b[0m\n\n");
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
    printf("\nTime Quantum: %d\n\n", Answer.TimeQuantum);
    ResestProcessTable(ProcessTable, NumOfProcesses);
    struct Results FCFS = FirstComeFirstServe(ProcessTable, NumOfProcesses, 1000);
    printf("\x1b[31m===== FCFS =====\x1b[0m\n\n");
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
    printf("\nPress Enter to return to the main menu...");
    while (getchar() != '\n');
    getchar();
}

void printMenu()
{
    clearScreen();
    printf("\n\x1b[33m========== Process Scheduling Simulation ==========\x1b[0m\n\n");
    printf("1. Custom Input\n");
    printf("2. Random Input\n");
    printf("3. Quit\n");
    printf("Enter your choice: ");
}

void generateRandomInputAndSimulate()
{
    clearScreen();
    int NumOfProcesses = rand() % 10;
    NumOfProcesses = NumOfProcesses < 5 ? 5 : NumOfProcesses;
    struct Process *ProcessTable = GenerateRandomProcessTable(NumOfProcesses);
    struct Results Answer = SimulateRandomRoundRobin(ProcessTable, NumOfProcesses, 1000);
    showSimulationData(ProcessTable, NumOfProcesses, Answer);
}

void getCustomInput()
{
    clearScreen();
    printf("========== Custom Input ==========\n\n");
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
        printf("ArrivalTime for Process %d: ", i + 1);
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

int main()
{
    srand((unsigned int)time(NULL));

    int choice;

    while (1)
    {
        clearScreen();
        printMenu();
        
        choice = 0;
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            getCustomInput();
            break;
        case 2:
            generateRandomInputAndSimulate();
            break;
        case 3:
            clearScreen();
            printf("Goodbye!\n");
            exit(0);
        default:
            printf("Invalid choice. Please try again.\n");
            break;
        }
    }

    return 0;
}