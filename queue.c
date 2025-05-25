#include <stdio.h>
#include <stdbool.h>

#define MAX_QUEUE 100

struct Queue
{
    int array[MAX_QUEUE];
    int front;
    int rear;
};

void initializeQueue(struct Queue *q)
{
    q->front = -1;
    q->rear = 0;
}

bool isFull(struct Queue *q)
{
    return q->rear == MAX_QUEUE;
}

bool isEmpty(struct Queue *q)
{
    return q->front == q->rear - 1;
}

void printQueue(struct Queue *q)
{
    if (isEmpty(q)) {
        puts("queue is empty");
        return;
    }

    puts("current queue:");
    for (size_t i = q->front + 1; i < q->rear; i++) {
        printf("%d ", q->array[i]);
    }
    puts("");
}

void printBoth(struct Queue *q)
{
    if (isEmpty(q)) {
        puts("queue is empty");
        return;
    }

    printf("Front: %d and Rear: %d\n", q->array[q->front + 1], q->array[q->rear - 1]);
}

void enqueue(struct Queue *q, int value)
{
    if (isFull(q)) {
        return;
    }

    q->array[q->rear] = value;
    q->rear++;
}

void dequeue(struct Queue *q)
{
    if (isEmpty(q))
        return;
    
    q->front++;
}

int main(void)
{
    struct Queue test_queue;
    initializeQueue(&test_queue);
    enqueue(&test_queue, 2);
    enqueue(&test_queue, 3);
    enqueue(&test_queue, 5);
    enqueue(&test_queue, 4);

    printBoth(&test_queue);
    printQueue(&test_queue);
    dequeue(&test_queue);
    dequeue(&test_queue);
    printBoth(&test_queue);
    printQueue(&test_queue);

    return 0;
}