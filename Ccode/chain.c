#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

typedef struct Node {
    int data;
    char name[20];
    struct Node *next;
} Node;

void Print(Node *head) {
    Node *p = head->next;
    while (p != NULL) {
        printf("Name: %s, Data: %d\n", p->name, p->data);
        p = p->next;
    }
    printf("Traversal completed.\n");
}

Node* create() {
    Node *head = (Node*)malloc(sizeof(Node));
    head->next = NULL;

    Node *tail = head;

    for (int i = 0; i < 3; i++) {
        Node *newNode = (Node*)malloc(sizeof(Node));
        newNode->data = i;
        sprintf(newNode->name, "Node_%d", i);
        newNode->next = NULL;

        tail->next = newNode;
        tail = newNode;
    }

    return head;
}

int main() {
    Node *head = create();
    Print(head);

    Node *current = head;
    while (current != NULL) {
        Node *next = current->next;
        free(current);
        current = next;
    }

    return 0;
}
