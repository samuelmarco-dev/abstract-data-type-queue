#include <stdio.h>
#include <stdlib.h>

#define N 10

typedef struct {
  int head, tail;
  int data[N];
} queue;

queue *newQueue();
void enqueue(queue *q, int value);
int dequeue(queue *q);
int isQueueEmpty(queue *q);
int isQueueFull(queue *q);
void showQueue(queue *q);

int main() {
  int a, b;
  queue *fila = newQueue();
  showQueue(fila);
  enqueue(fila, 5);
  enqueue(fila, 15);
  enqueue(fila, 22);
  enqueue(fila, 7);
  a = dequeue(fila);
  b = dequeue(fila);
  printf("Valores removidos: %d %d\n", a, b);
  showQueue(fila);
}

queue *newQueue() {
  queue *q = (queue *)malloc(sizeof(queue));
  q->head = 0;
  q->tail = 0;
}

void enqueue(queue *q, int value) {
  if (isQueueFull(q)) {
    printf("Fila cheia, nao eh possivel inserir um novo valor\n");
    return;
  }
  q->data[q->tail] = value;
  q->tail++;
}

int dequeue(queue *q) {
  if (isQueueEmpty(q)) {
    printf("Fila vazia, nao eh possivel remover um valor\n");
    return -1;
  }
  return q->data[q->head++];
}

int isQueueEmpty(queue *q) {
  return q->head == q->tail;
}

int isQueueFull(queue *q) {
  return q->tail == N;
}

void showQueue(queue *q) {
  int i;
  if (isQueueEmpty(q)) {
    printf("Fila vazia");
  } else {
    printf("Fila: \n");
  }
  for (i=q->head; i<q->tail; i++) {
    printf(" [%2d] ", q->data[i]);
  }
  printf("\n");
}
