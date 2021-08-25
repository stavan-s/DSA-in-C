#include<stdio.h>
#include<stdlib.h>


// define the 'node' data type
typedef struct node {

    int data;
    struct node * next;
    
} node;


// Globally declare pointers
node *newNode, *curNode, *head;


// print the linked list
void printList() {

    curNode = head;

    printf("\nThe List is : ");

    while(curNode != 0) {

        printf("%d ", curNode->data);
        curNode = curNode->next;
    }

}


void printLength() {

    curNode = head;
    int length = 0;

    while(curNode != 0) {
        length++;
        curNode = curNode->next;
    }

    printf("\nThe length of the linked list is -> %d", length);
    
}

void insertAtBeginning() {

    newNode = (node*)malloc(sizeof(node));

    printf("\nEnter the data -> ");
    scanf("%d", &newNode->data);

    newNode->next = head;
    head = newNode;

    printf("\nSuccessfully inserted %d at the beginning of the list", newNode->data);
    
}

void insertAtEnd() {

    newNode = (node*)malloc(sizeof(node));

    printf("\nEnter the data -> ");
    scanf("%d", &newNode->data);

    newNode->next = 0;

    curNode = head;

    while(curNode->next != 0) {
        curNode = curNode->next;
    }

    curNode->next = newNode;

    printf("\nSuccessfully inserted %d at the end of the list", newNode->data);
    
}

void insertAtPosition() {

    newNode = (node*)malloc(sizeof(node));

    printf("\nEnter the data -> ");
    scanf("%d", &newNode->data);

    printf("\nEnter the position -> ");
    int pos;
    scanf("%d", &pos);

    int i = 2;

    curNode = head;

    while(i < pos) {
        curNode = curNode->next;
        i++;
    }

    newNode->next = curNode->next;
    curNode->next = newNode;


    printf("\nSuccessfully inserted %d at the position : %d of the list", newNode->data, pos);
}

void deleteFromBeginning() {

    curNode = head;

    int deletedData;

    if(head == 0) {
        printf("\nList is empty");
    }
    else {
        head = curNode->next;
        deletedData = curNode->data;
        free(curNode);
    }

    printf("\nSuccessfully deleted %d from the beginning of the list", deletedData);
    
}

void deleteFromEnd() {

    node *prevNode = head;
    curNode = head;
    int deletedData;

    while(curNode->next != 0) {
        prevNode = curNode;
        curNode = curNode->next;
    }

    prevNode->next = 0;
    deletedData = curNode->data;

    free(curNode);

    printf("\nSuccessfully deleted %d from the end of the list", deletedData);

}

void deleteFromPosition() {

    printf("\nEnter the position -> ");
    int pos;
    scanf("%d", &pos);

    curNode = head;
    node *prevNode = head;

    int i = 1, deletedData;

    while(i < pos) {
        prevNode = curNode;
        curNode = curNode->next;   
        i++;
    }

    prevNode->next = curNode->next;

    deletedData = curNode->data;

    free(curNode);

    printf("\nSuccessfully deleted %d from the position : %d of the list", deletedData, pos);
    
}

int main() {

    head = 0;

    int choice = 1;

    while(choice) {

        newNode = (node*)malloc(sizeof(node));

        printf("\nEnter the data -> ");
        scanf("%d", &newNode->data);

        newNode->next = 0;
    
        if(head == 0) {
            head = curNode = newNode;
        }
        else {
            curNode->next = newNode;
            curNode = newNode;
        }

        printf("\nDo you want to continue? (0, 1) -> ");
        scanf("%d", &choice);
    }

    int terminateCondition = 1;

    while(terminateCondition) {

        system("cls");

        printf("\nEnter 0 to Exit");
        printf("\nEnter 1 to print the list");
        printf("\nEnter 2 to print the length of the list");
        printf("\nEnter 3 to add a node");
        printf("\nEnter 4 to delete a node");

        printf("\n\nEnter your choice -> ");
        scanf("%d", &choice);

        switch(choice) {

            case 0:
                exit(0);
                break;
            
            case 1:
                printList();
                break;

            case 2:
                printLength();
                break;

            case 3:

                system("cls");

                printf("\nEnter 1 to insert node at the beginning");
                printf("\nEnter 2 to insert node at the end");
                printf("\nEnter 3 to insert node at a position");

                int choice2;

                printf("\nEnter your choice -> ");
                scanf("%d", &choice2);

                switch(choice2) {

                    case 1:
                        insertAtBeginning();
                        break;
                    case 2:
                        insertAtEnd();
                        break;
                    case 3:
                        insertAtPosition();
                        break;
                    
                    default:
                        printf("\nWrong choice");
                    
                }
                
                break;

            case 4:
                system("cls");

                printf("\nEnter 1 to delete node from the beginning");
                printf("\nEnter 2 to delete node from the end");
                printf("\nEnter 3 to delete node from a position");

                int choice3;

                printf("\nEnter your choice -> ");
                scanf("%d", &choice3);

                switch(choice3) {

                    case 1:
                        deleteFromBeginning();
                        break;
                    case 2:
                        deleteFromEnd();
                        break;
                    case 3:
                        deleteFromPosition();
                        break;
                    default:
                        printf("\nWrong choice entered!!");
                    
                }

                break;
                
            default:
                printf("\nEnter appropriate choice!!");
            
        }

        printf("\nDo you want to continue? (0, 1) -> ");
        scanf("%d", &terminateCondition);
        
    }

    return 0;
}