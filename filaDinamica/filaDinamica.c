#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/*
Conceito de fila:
    O primeiro a entrar � o primeiro a sair
    O �ltimo a entrar � o �ltimo a sair

Fila din�mica:
    O �ltimo a entrar vai aponta para nulo
    E todos os seguintes, v�o receber a refer�ncia anterior
    de tail e tail receber� o n�
*/

typedef struct nodeitem {
    int information;
    struct nodeitem *next;
} node;

typedef struct {
    node *head;
    node *tail;
} queue;

queue *newQueue();
node *newNode(int value);
void enqueue(queue *q, int information);
int dequeue(queue *q);

void showQueue(queue *q);
int queueEmpty(queue *q);

int main() {
    setlocale(LC_ALL, "");
    queue *q = newQueue();

    enqueue(q, 5);
    enqueue(q, 10);
    enqueue(q, 15);
    enqueue(q, 20);
    showQueue(q);

    printf("\nValor removido: %d\n", dequeue(q));
    printf("Valor removido: %d\n\n", dequeue(q));
    showQueue(q);

    return 0;
}

queue *newQueue() {
    queue *q = (queue *)malloc(sizeof(queue));
    q->head = NULL;
    q->tail = NULL;

    return q;
}

node *newNode(int value) {
    node *n = (node *)malloc(sizeof(node));
    n->information = value;
    n->next = NULL;

    return n;
}

/*
    1. Criar o novo n� com a informa��o que desejamos inserir na fila
    Se a fila est� vazia:
        2. Precisamos atualizar head e tail para receber o novo n� instanciado
    Se a fila n�o est� vazia:
        2. Precisamos atualizar apenas tail, dessa forma o n� atual para qual tail aponta
        em next passa a apontar para o novo n� e tail aponta para o novo n� instanciado
*/
void enqueue(queue *q, int information) {
    node *n = newNode(information);

    if(queueEmpty(q)) {
        q->head = n;
        q->tail = n;
        return;
    }

    q->tail->next = n;
    q->tail = n;
}

/*
    1. Instancia uma estrutura para guardar o n� atual e dessa forma alterar head
    2. Armazenar o n� de head e retornar o campo information
    3. Como o n� armazenado ser� exclu�do, ent�o a nova refer�ncia para head ser� o
    campo next do n� que ser� exclu�do
    4. Ap�s liberar a refer�ncia do n� que ser� exclu�do, podemos liberar a mem�ria
*/
int dequeue(queue *q) {
    node *n;
    int aux;

    if(queueEmpty(q)) {
        printf("Queue underflow!\n");
        exit(1);
    }

    n = q->head;
    aux = n->information;
    q->head = n->next;

    if(q->head == NULL) {
        q->tail = NULL;
    }

    free(n);
    return aux;
}

void showQueue(queue *q) {
    if(queueEmpty(q)) {
        printf("Queue underflow!\n");
        return;
    }

    printf("Queue:\n-> ");
    node *n;
    n = q->head;

    while(n != NULL) {
        printf("%d ", n->information);
        n = n->next;
    }
    printf("\n");
}

int queueEmpty(queue *q) {
    return q->head == NULL || q->tail == NULL;
}
