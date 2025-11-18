#include <stdio.h>


typedef struct Node {
    int data;
    struct Node* next;
}Node;

void test() {
    Node n1={1,NULL};
    Node n2={ 2,NULL};
    Node n3={ 3,NULL};
    Node n4={ 4,NULL};
    Node n5={ 5,NULL};


    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;
    n5.next = NULL;

    Node * current=&n1;
    while (current!=NULL) {
        printf("%d",current->data);
        current=current->next;

    }
}


int main() {
    test();
    return 0;
}