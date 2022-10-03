#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define N 50

typedef struct {
    int head, tail;
    int amount, current;
    char data[N];
} queue;

queue *newQueue();
void enqueue(queue *q, char str);
char dequeue(queue *q);
void showQueue(queue *q);

int isQueueEmpty(queue *q);
int isQueueFull(queue *q);
int numberElementsInserted(queue *q);
int numberElementsCurrent(queue *q);

int main() {
    setlocale(LC_ALL, "");

    queue *q = newQueue();
    enqueue(q, 'S');
    enqueue(q, 'a');
    enqueue(q, 'm');
    enqueue(q, 'u');
    enqueue(q, 'e');
    enqueue(q, 'l');
    showQueue(q);
    printf("N�mero de elementos inseridos: %d\n", numberElementsInserted(q));
    printf("N�mero de elementos atuais: %d\n", numberElementsCurrent(q));

    dequeue(q);
    dequeue(q);
    showQueue(q);
    printf("N�mero de elementos inseridos: %d\n", numberElementsInserted(q));
    printf("N�mero de elementos atuais: %d\n", numberElementsCurrent(q));
}

queue *newQueue() {
    queue *q = (queue *)malloc(sizeof(queue));
    q->head = 0;
    q->tail = 0;
    q->amount = 0;
    q->current = 0;

    return q;
}

void enqueue(queue *q, char str) {
    if(isQueueFull(q)) {
        printf("Queue Overflow\n");
        exit(1);
    }

    q->data[q->tail % N] = str;
    q->tail++;
    q->amount++;
    q->current++;
}

char dequeue(queue *q) {
    if(isQueueEmpty(q)) {
        printf("Queue Underflow\n");
        exit(1);
    }

    char element = q->data[q->head % N];
    q->head++;
    q->current--;

    return element;
}

void showQueue(queue *q) {
    if(isQueueEmpty(q)) {
        printf("Queue Underflow\n");
        return;
    }

    int i;
    for(i = q->head; i<q->tail; i++) {
        printf("Element in Array: %c\n", q->data[i % N]);
    }
}

int isQueueEmpty(queue *q) {
    return q->tail == q->head;
}

int isQueueFull(queue *q) {
    return q->tail - q->head == N;
}

int numberElementsInserted(queue *q) {
    return q->amount;
}

int numberElementsCurrent(queue *q) {
    return q->current;
}
