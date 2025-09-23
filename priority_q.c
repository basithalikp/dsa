#include <stdio.h>
#include <stdlib.h>

struct node
{
    int id;
    int priority;
    struct node *next;
} *front = NULL;

void enqueue(int id, int priority){
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->id = id;
    newNode->priority = priority;
    newNode->next = NULL;
    if (front == NULL || newNode->priority < front->priority)
    {
        newNode->next = front;
        front = newNode;
    }
    else
    {
        struct node *temp = (struct node*)malloc(sizeof(struct node));
        temp = front;
        while (temp->next != NULL && temp->next->priority <= newNode->priority)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = NULL;
        free(temp);
    }
}

void dequeue(){
    if (front == NULL)
    {
        printf("No parcels left!\n");
        return;
    }
    else
    {
        struct node *temp = (struct node*)malloc(sizeof(struct node));
        temp = front;
        printf("Delivered item with id %d and priority %d",temp->id,temp->priority);
        front = front->next;
        free(temp);
    }
}

void display(){
    if (front == NULL)
    {
        printf("Empty Queue");
        return;
    }
    else
    {
        struct node *temp = (struct node*)malloc(sizeof(struct node));
        temp = front;
        while (temp != NULL)
        {
            printf("Order id : %d\nPriority : %d\n\n",temp->id,temp->priority);
            temp = temp->next;
        }
    }
}

int main(){
    int option,id,priority;
    while(1){
    printf("\nThis is a program for Parcel delivery!\n");
    printf("What would you like to do today?\n");
    printf("1 - Create new order\n2 - Deliver an order\n3 - Display an order\n4 - Exit");
    printf("\nPlease choose an option : ");
    scanf("%d",&option);
    switch (option)
    {
    case 1:
        printf("Enter the parcel id and priority : ");
        scanf("%d%d",&id,&priority);
        enqueue(id,priority);
        break;
    case 2:
        dequeue();
        break;
    case 3:
        display();
        break;
    case 4:
        exit(0);
        break;
    default:
        printf("Invalid!");
        break;
    }
    }
    return 0;
}