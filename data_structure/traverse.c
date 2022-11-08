#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
}Node;

typedef struct LinkedQueue{
    struct Node* front;
    struct Node* rear;
    int len;
}LinkedQueue;

void init(LinkedQueue* queue) {
    queue->len = 0;
    queue->front = NULL;
    queue->rear = NULL;
}

int is_empty(LinkedQueue* queue) {
    if (queue->len == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void enqueue(LinkedQueue* queue, int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    if (is_empty(queue)) {
        queue->front = new_node;
        queue->rear = new_node;
    }
    else {
        queue->rear->next = new_node;
        queue->rear = queue->rear->next;
    }
    (queue->len)++;
}

int dequeue(LinkedQueue* queue) {
    if (is_empty(queue)) {
        printf("Queue is empty\n");
        exit(1);
    }
    Node* delNode = queue->front;
    int ret = delNode->data;
    queue->front = delNode->next;
    free(delNode);
    (queue->len)--;
    return ret;
}

void traverse(LinkedQueue* queue) {
    Node* temp = queue->front;
    if (is_empty(queue))
    {
        return;
    }
    for (int i = 0; i < queue->len; i++)
    {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}

int main()
{
    LinkedQueue* queue = malloc(sizeof(LinkedQueue));
    init(queue);
    enqueue(queue,100);
    enqueue(queue,200);
    traverse(queue);
}