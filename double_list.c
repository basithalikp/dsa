#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next, *prev;
} *head = NULL;

void insert_first(int data){
    struct node *new = (struct node*)malloc(sizeof(struct node));
    if(new != NULL)
    {
        head->next = new;
        new->prev = head;
        new->next = NULL;
        new->data = data;
    }
    else
    {
        printf("No enough memory");
    }
}

void insert_begining(int data){
    struct node *ptr = head->next;
    if (ptr == NULL)
    {
        insert_first(data);
        return;
    }
    struct node *new = (struct node*)malloc(sizeof(struct node));
    if (new != NULL)
    {
        new->prev = head;
        head->next = new;
        ptr->prev = new;
        new->next = ptr;
        new->data = data;
    }
    else
    {
        printf("No enough memory!\n");
    }
}

void insert_end(int data){
    struct node *ptr = head;
    while (ptr->data != data && ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    struct node *new = (struct node*)malloc((sizeof(struct node)));
    if (new != NULL){
        new->prev = ptr;
        ptr->next = new;
        new->next = NULL;
        new->data = data;
    }
    else
    {
        printf("No enough memory");
        return;
    }
}

void insert_btw(int data, int key){
    struct node *ptr = head;
    while (ptr->data != key && ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    struct node *new = (struct node*)malloc(sizeof(struct node));
    if (new == NULL)
    {
        printf("No enough memory");
        return;
    }
    if (ptr->next == NULL)
    {
        printf("No enough memory");
        return;
    }
    else
    {
        struct node *nextNode = ptr->next;
        new->prev = ptr;
        new->next = nextNode;
        ptr->next = new;
        nextNode->prev = new;
        ptr = new;
        new->data = key;
    }
}

void delete_begining(){
    struct node *ptr = head->next;
    if (ptr == NULL)
    {
        printf("Key not found!");
        return;
    }
    else
    {
        struct node *nextNode = ptr->next;
        head->next = nextNode;
        if (nextNode != NULL)
        {
            nextNode->prev = head;
        }
        printf("Deleted element is %d",ptr->data);
        free(ptr);
    }
}

void delete_end(){
    struct node *ptr = head;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    if (ptr == head)
    {
        printf("Empty list!");
        return;
    }
    else
    {
        struct node *nextNode = ptr->prev;
        nextNode->next = NULL;
        printf("Deleted element is %d",ptr->data);
        free(ptr);
    }
}

void delete_btw(int key){
    struct node *ptr = head->next;
    if (ptr == NULL)
    {
        printf("Empty list!");
        return;
    }
    while (ptr->data != key && ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    if (ptr->data == key)
    {
        struct node *ptrPrev = ptr->prev, *ptrNext = ptr->next;
        ptrPrev->next = ptrNext;
        if (ptrNext != NULL)
        {
            ptrNext->prev = ptrPrev;
        }
        printf("Deleted element is %d",ptr->data);
        free(ptr);
    }
    else
    {
        printf("Key not found!");
        return;
    }
}

void display(){
    struct node *ptr = head->next;
    if (ptr == NULL)
    {
        printf("Empty list!");
        return;
    }
    
    while (ptr->next != NULL)
    {
        printf("%d ",ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

int main(){
    int choice, element, key;

    printf("This is a menu driven program for Doubly linked list\n");
    while (1){
    printf("Enter\n1 for insertion\n2 for deletion\n3 for display\n4 to exit\n");
    printf("Enter your choice : ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        printf("Enter the element you want to insert : ");
        scanf("%d", &element);
        printf("Where to insert?\n1 - begining\n2 - end\n3 - between\nEnter your choice : ");
        scanf("%d", &choice);
        if (choice == 1)
        {
            insert_first(element);
        }
        else if(choice == 2){
            insert_end(element);
        }
        else if (choice == 3)
        {
            printf("After which element you want to insert?");
            scanf("%d", &key);
            insert_btw(element,key);
        }
        else
        {
            printf("Invalid option!\n");
        }
        break;
    case 2:
        printf("Where to delete?\n1 - begining\n2 - end\n3 - between\nEnter your choice : ");
        scanf("%d", &choice);
        if (choice == 1)
        {
            delete_begining();
        }
        else if(choice == 2){
            delete_end();
        }
        else if (choice == 3)
        {
            printf("After which element you want to delete?");
            scanf("%d", &key);
            delete_btw(key);
        }
        else
        {
            printf("Invalid option");
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
    
    