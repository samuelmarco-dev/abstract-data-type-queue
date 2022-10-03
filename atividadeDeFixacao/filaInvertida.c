#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <string.h>

#define N 100

typedef struct {
    int head, tail;
    int data[N];
} queue;

typedef struct {
    int top;
    int data[N];
} stack;

queue *newQueue();
void enqueue(queue *q, int value);
int dequeue(queue *q);
void showQueue(queue *q);
int queueEmpty(queue *q);
int queueFull(queue *q);

stack *newStack();
void push(stack *s, int value);
int pop(stack *s);
int showStack(stack *s);
int stackEmpty(stack *s);
int stackFull(stack *s);

void reverse(queue *q, stack *s);

int main() {
    setlocale(LC_ALL, "");
    queue *q = newQueue();
    stack *s = newStack();
    int opcao, value;

    printf("Selecione uma op��o: \n1-Inserir elementos na fila; \n2-Inverter a fila; \n3-Exibir a fila; \nOp��o: ");
    scanf("%d", &opcao);
    while(opcao < 1 || opcao > 3) {
        printf("Selecione uma op��o: \n1-Inserir elementos na fila; \n2-Inverter a fila; \n3-Exibir a fila; \nOp��o: ");
        scanf("%d", &opcao);
    }

    if(opcao == 1) {
        enqueue(q, 10);
        enqueue(q, 20);
        enqueue(q, 30);
        printf("Selecione uma op��o: \n1-Inserir elementos na fila; \n2-Inverter a fila; \n3-Exibir a fila; \n0-Sair; \nOp��o: ");
        scanf("%d", &opcao);
    }
    if(opcao == 2) {
        reverse(q, s);
        printf("Selecione uma op��o: \n1-Inserir elementos na fila; \n2-Inverter a fila; \n3-Exibir a fila; \n0-Sair; \nOp��o: ");
        scanf("%d", &opcao);
    }
    if(opcao == 3) {
        showQueue(q);
        printf("Selecione uma op��o: \n1-Inserir elementos na fila; \n2-Inverter a fila; \n3-Exibir a fila; \n0-Sair; \nOp��o: ");
        scanf("%d", &opcao);
    }
    if(opcao == 0) exit(1);

    return 0;
}

void reverse(queue *q, stack *s) {
    if(queueEmpty(q)) {
        printf("Cannot reverse an empty queue!\n");
        exit(1);
    }

    int i, remove;
    for(i=q->head; i<q->tail; i++) {
        push(s, q->data[i]);
        dequeue(q);
    }

    printf("Reverse:\n-> ");
    while(!stackEmpty(s)) {
        remove = pop(s);
        printf("%d ", remove);
        enqueue(q, remove);
    }
    printf("\n");
}

queue *newQueue() {
    queue *q = (queue *)malloc(sizeof(queue));
    q->head = 0;
    q->tail = 0;

    return q;
}

void enqueue(queue *q, int value) {
    if(queueFull(q)) {
        printf("Queue overflow!\n");
        exit(1);
    }

    q->data[q->tail % N] = value;
    q->tail++;
}

int dequeue(queue *q) {
    if(queueEmpty(q)) {
        printf("Queue underflow!\n");
        exit(1);
    }

    int element = q->data[q->head % N];
    q->head++;
    return element;
}

void showQueue(queue *q) {
    if(queueEmpty(q)) {
        printf("Queue underflow!\n");
        return;
    }
    
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

void push(stack *s, int value) {
    if(stackFull(s)) {
        printf("Stack overflow!\n");
        exit(1);
    }

    s->data[s->top] = value;
    s->top++;
}

int pop(stack *s) {
    if(stackEmpty(s)) {
        printf("Stack underflow!\n");
        exit(1);
    }

    s->top--;
    return s->data[s->top];
}

int showStack(stack *s) {
    if(stackEmpty(s)) {
        printf("Stack underflow!\n");
        return;
    }

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
