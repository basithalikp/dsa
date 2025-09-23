#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *prev, *next;
} *head = NULL, *rhead = NULL;

struct node *getNode(int data){
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void enqueue_front(int element){
    struct node *newNode = getNode(element);
    if (head == NULL)
    {
        head = newNode;
        newNode->next = NULL;
        rhead = newNode;
        return;
    }
    
    if (newNode != NULL)
    {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    else
    {
        printf("Failed to allocate memory!");
        return;
    }
}

void enqueue_rear(int element){
    struct node *ptr = head;

    if (head == NULL)
    {
        enqueue_front(element);
        return;
    }

    struct node *newNode = getNode(element);

    if (newNode != NULL)
    {
        rhead->next = newNode;
        rhead = newNode;
    }
    else
    {
        printf("Failed to allocate memory!");
        return;
    }
}

void dequeue_front(){
    if (head == NULL)
    {
        printf("Empty list!\n");
        return;
    }
    
    struct node *ptr = head;
    head = ptr->next;
    if (head != NULL)
    {
        head->prev = NULL;
    }
    printf("Deleted element is : %d\n",ptr->data);
    free(ptr);
}

void dequeue_rear(){
    struct node *ptr = rhead;
    if (head == NULL)
    {
        printf("Empty list!\n");
        return;
    }
    if (rhead == head)
    {
        head = NULL;
        rhead = NULL;
    }
    else
    {
        rhead = rhead->prev;
    }
    printf("Deleted element is : %d\n",ptr->data);
    free(ptr);
}

void display(){
    struct node *ptr = head;
    if (ptr == NULL)
    {
        printf("Empty list!\n");
        return;
    }
    while (ptr != NULL)
    {
        printf("%d ",ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

int main(){
    int choice, element, key;

    while(1){
    printf("This is a menu driven program for double ended queue\n");
    printf("Enter\n1 for enqueue\n2 for dequeue\n3 for display\n4 to exit\nPlease enter your choice : ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        printf("__enqueue__\n1 - enqueue front\n2 - enqueue rear\nPlease enter your choice : ");
        scanf("%d", &choice);
        printf("Enter the element to be inserted : ");
        scanf("%d", &element);
        if (choice == 1)
        {
            enqueue_front(element);
        }
        else if (choice == 2)
        {
            enqueue_rear(element);
        }
        else
        {
            printf("Invalid option!\n");
        }
        break;
    case 2:
        printf("__dequeue__\n1 - dequeue front\n2 - dequeue rear\nPlease enter your choice : ");
        scanf("%d", &choice);
        if (choice == 1)
        {
            dequeue_front();
        }
        else if (choice == 2)
        {
            dequeue_rear();
        }
        else
        {
            printf("Invalid option!\n");
        }
        break;
    case 3:
        display();
        break;
    case 4:
        exit(0);
        break;
    default:
        printf("Invalid option!\n");
        break;
    }
    }
    return 0;
}
