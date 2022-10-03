#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define LENGTH 50

typedef struct {
    int head, tail;
    int data[LENGTH];
} queue;

queue *newQueue();
void enqueue(queue *q, int value);
int dequeue(queue *q);

int isQueueEmpty(queue *q);
int isQueueFull(queue *q);
void showQueue(queue *q);

int main() {
    setLocale(LC_ALL, "");
    queue *q = newQueue();

    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    showQueue(q);

    return 0;
}

queue *newQueue() {
    queue *q = (queue *)malloc(sizeof(queue));
    q->head = 0;
    q->tail = 0;

    return q;
}

void enqueue(queue *q, int value) {
    if(isQueueFull(q)) {
        printf("Queue Overflow\n");
        exit(1);
    }

    q->data[q->tail % LENGTH] = value;
    q->tail++;
}

int dequeue(queue *q) {
    if(isQueueEmpty(q)) {
        printf("Dequeue Underflow\n");
        exit(1);
    }

    int var = q->data[q->head % LENGTH];
    q->head++;
    return var;
}

int isQueueEmpty(queue *q) {
    return q->head == q->tail;
}

int isQueueFull(queue *q) {
    return q->tail - q->head == LENGTH;
}

void showQueue(queue *q){
    if(isQueueEmpty(q)) {
        printf("Dequeue Underflow\n");
        return;
    }

    int i;
    for(i=q->head; i<q->tail; i++) {
        printf(" %d ", q->data[i % LENGTH]);
    }
    printf("\n");
}
