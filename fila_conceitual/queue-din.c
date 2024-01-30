#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct nodei {
    char info;
    struct nodei *prox;
} node;

typedef struct {
    node *head;
    node *tail;
    int total;
    int atual;
} queue;

node *newNode(char v);
queue *newQueue();
int isQueueEmpty(queue *f);
void enqueue(queue *f, char v);
char dequeue(queue *f);
void showQueue(queue *f);

int total(queue *f) {
    return f->total;
}
int atual(queue *f) {
    return f->atual;
}

int main() {
    int i;
    queue *fila = newQueue();
    char texto[] = "Eu gosto de estudar";

    for (i = 0; i<strlen(texto); i++) {
        if (texto[i] != ' ') {
            enqueue(fila, texto[i]);
        }
    }
    printf("Atual: %d, Total: %d\n", atual(fila), total(fila));
    while(!isQueueEmpty(fila)) {
        printf("%c", dequeue(fila));
    }
    printf("\nAtual: %d, Total: %d\n", atual(fila), total(fila));

}


node *newNode(char v) {
    node *n = (node *)malloc(sizeof(node));
    n->info = v;
    n->prox = NULL;
    return n;
}

queue *newQueue(){
    queue *f = (queue *)malloc(sizeof(queue));
    f->head = NULL;
    f->tail = NULL;
    f->total = 0;
    f->atual = 0;
    return f;
}

int isQueueEmpty(queue *f) {
    if (f->head == NULL) return 1;
    else return 0;
}

void enqueue(queue *f, char v) {
    if (isQueueEmpty(f)) {
        f->head = newNode(v);
        f->tail = f->head;
    } else {
        node *n = newNode(v);

        f->tail->prox = n;
        f->tail = n;
    }
    f->atual++;
    f->total++;
}

char dequeue(queue *f) {
    if (isQueueEmpty(f)) {
        printf("Fila vazia!");
        return '\0';
    }
    node *n = f->head;
    int aux = n->info;

    f->head = n->prox;
    free(n);
    if (f->head == NULL) {
        f->tail = NULL;
    }

    f->atual--;
    return aux;
}

void showQueue(queue *f) {
    node *n = f->head;
    while(n != NULL) {
        printf("%c", n->info);
        n = n->prox;
    }
}
