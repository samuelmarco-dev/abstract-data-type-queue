#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <string.h>

#define SIZE 100

typedef struct {
    int head, tail;
    char data[SIZE];
} queue;

queue *newQueue();
void enqueue(queue *q, char element);
char dequeue(queue *q);
void showQueue(queue *q);
void process(queue *q, char str[]);

int isQueueEmpty(queue *q);
int isQueueFull(queue *q);

int main() {
    setlocale(LC_ALL, "");
    char string[] = "Minha    string para ser enfileira";
    queue *q = newQueue();

    process(q, string);
    showQueue(q);

    return 0;
}

queue *newQueue() {
    queue *q = (queue *)malloc(sizeof(queue));
    q->head = 0;
    q->tail = 0;

    return q;
}

void process(queue *q, char str[]) {
    for(int i=0; i<strlen(str); i++) {
        if(str[i] != ' ') {
            enqueue(q, str[i]);
            enqueue(q, str[i]);
        }
    }
}

void enqueue(queue *q, char element) {
    if(isQueueFull(q)) {
        printf("Queue Overflow\n");
        exit(1);
    }

    q->data[q->tail % SIZE] = element;;
    q->tail++;
}

char dequeue(queue *q) {
    if(isQueueEmpty(q)) {
        printf("Queue Underflow\n");
        exit(1);
    }

    char var = q->data[q->head % SIZE];
    q->head++;

    return var;
}
void showQueue(queue *q) {
    if(isQueueEmpty(q)) {
        printf("Queue Underflow\n");
        return;
    }

    printf("Queue: \n");
    for(int i=q->head; i<q->tail; i++) {
        printf("%c", q->data[i % SIZE]);
    }
    printf("\n");
}

int isQueueEmpty(queue *q) {
    return q->tail == q->head;
}

int isQueueFull(queue *q) {
    return q->tail - q->head == SIZE;
}
