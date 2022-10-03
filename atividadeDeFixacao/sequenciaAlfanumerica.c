#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <string.h>

#define N 50

typedef struct {
    int head, tail;
    int data[N];
} queue;

typedef struct {
    int top;
    int data[N];
} stack;

queue *newQueue();
void enqueue(queue *q, char value);
char dequeue(queue *q);
void showQueue(queue *q);
int queueEmpty(queue *q);
int queueFull(queue *q);

stack *newStack();
void push(stack *s, char value);
char pop(stack *s);
void showStack(stack *s);
int stackEmpty(stack *s);
int stackFull(stack *s);

int main() {
    setlocale(LC_ALL, "");
    queue *q = newQueue();
    stack *s = newStack();
    char texto[] = "A 1 E 5 T 7 W 8 G";
    char remove;
    int i;

    for(i = 0; i < strlen(texto); i++) {
        if(texto[i] == ' ') continue;
        if(texto[i] >= '0' && texto[i] <= '9') {
            push(s, texto[i]);
            enqueue(q, '?');
        } else {
            enqueue(q, texto[i]);
        }
    }

    printf("%s -> ", texto);
    while(!queueEmpty(s)) {
        remove = dequeue(q);
        if(remove == '?') printf("%c ", pop(s));
        else printf("%c ", remove);
    }

    return 0;
}

queue *newQueue() {
    queue *q = (queue *)malloc(sizeof(queue));
    q->head = 0;
    q->tail = 0;

    return q;
}

void enqueue(queue *q, char value) {
    if(queueFull(q)) {
        printf("Queue overflow!\n");
        exit(1);
    }

    q->data[q->tail % N] = value;
    q->tail++;
}

char dequeue(queue *q) {
    if(queueEmpty(q)) {
        printf("Queue underflow!\n");
        exit(1);
    }

    char element = q->data[q->head % N];
    q->head++;
    return element;
}

void showQueue(queue *q) {
    int i;
    printf("Queue: \n-> ");
    for(i=q->head; i<q->tail; i++) {
        printf("%d ", q->data[i % N]);
    }
    printf("\n");
}

int queueEmpty(queue *q) {
    return q->tail == q->head;
}

int queueFull(queue *q) {
    return q->tail - q->head == N;
}

stack *newStack() {
    stack *s = (stack *)malloc(sizeof(stack));
    s->top = 0;

    return s;
}

void push(stack *s, char value) {
    if(stackFull(s)) {
        printf("Stack overflow!\n");
        exit(1);
    }

    s->data[s->top] = value;
    s->top++;
}

char pop(stack *s) {
    if(stackEmpty(s)) {
        printf("Stack underflow!\n");
        exit(1);
    }

    s->top--;
    return s->data[s->top];
}

void showStack(stack *s) {
    int i;
    printf("Stack: \n-> ");
    for(i=0; i<s->top; i++) {
        printf("%d ", s->data[i]);
    }
    printf("\n");
}

int stackEmpty(stack *s) {
    return s->top == 0;
}

int stackFull(stack *s) {
    return s->top == N;
}
