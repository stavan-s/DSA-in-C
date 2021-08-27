#include<stdio.h>
#include<stdlib.h>

typedef struct node {

    int data;
    struct node *next;
    struct node *prev;

} node;

node *newNode, *head, *tail, *curNode;

void printList() {

    curNode = head;

    printf("\nThe Linked List is -> ");

    while(curNode != 0) {
        printf("%d ", curNode->data);

        curNode = curNode->next;
    }
    
}

void printReverse() {

    curNode = tail;

    printf("\nThe Linked List in reverse order is -> ");

    while(curNode != 0) {
        printf("%d ", curNode->data);

        curNode = curNode->prev;
    }

}

int main() {

    head = curNode = 0;

    int choice = 1;

    while(choice) {

        newNode = (node*)malloc(sizeof(node));

        printf("\nEnter the data -> ");
        scanf("%d", &newNode->data);

        newNode->prev = newNode->next = 0;

        if(head == 0) {
            head = curNode = newNode;
        }
        else {
            newNode->prev = curNode;
            curNode->next = newNode;
            curNode = newNode;
            tail = curNode;
        }

        printf("\nDo you want to continue? (0, 1) -> ");
        scanf("%d", &choice);
        
    }

    printList();

    printReverse();

    return 0;
}