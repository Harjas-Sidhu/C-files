#define MAX_SIZE 100

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
}

int isEmpty(struct Queue *q)
{
    return (q->front == -1);
}

int isFull(struct Queue *q)
{
    return ((q->rear + 1) % MAX_SIZE == q->front);
}

void enqueue(struct Queue *q, int item)
{
    if (isFull(q))
    {
        printf("Queue is full. Cannot enqueue.\n");
        return;
    }
    if (isEmpty(q))
    {
        q->front = q->rear = 0;
    }
    else
    {
        q->rear = (q->rear + 1) % MAX_SIZE;
    }
    q->Processes[q->rear] = item;
}

int dequeue(struct Queue *q)
{
    int item;
    if (isEmpty(q))
    {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1;
    }
    item = q->Processes[q->front];
    if (q->front == q->rear)
    {
        q->front = q->rear = -1;
    }
    else
    {
        q->front = (q->front + 1) % MAX_SIZE;
    }
    return item;
}