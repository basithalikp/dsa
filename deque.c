#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 10

int arr[MAX_SIZE],size,front=-1,rear=-1;

void invalid(){
    fprintf(stderr,"Invalid choice!");
    exit(1);
}

int is_full(){
    if (front==(rear+1)%size)
    {
        printf("Queue full!\n");
        return 1;
    }
    return 0;
}

int is_empty(){
    if(front==-1&&rear==-1)
    {
        printf("Queue empty!\n");
        return 1;
    }
    return 0;
}

void enqueue_front(int item){
    if (is_full)
        return;
    if (front==0)
        front=size-1;
    else
        front--;
    arr[front]=item;
}

void enqueue_rear(int item){
    if (is_full)
        return;
    rear=(rear+1)%size;
    arr[rear]=item;
    if (front==-1)
        front++;
}

void dequeue_front(){
    if (is_empty)
        return;
    printf("Deleted item is %d\n",arr[front]);
    if (front==rear)
    {
        front=-1;
        rear=-1;
    }
    else
        front=(front+1)%size;
}

void dequeue_rear(){
    if(is_empty)
        return;
    printf("Deleted item is %d\n",arr[rear]);
    if(rear==0)
        rear=size-1;
    else
        rear--;
}

int main(){
    int choice,item;

    printf("This is a menu driven program for Deque!\n");
    printf("Please enter the size of the deque : ");
    scanf("%d",&size);

    if (size>MAX_SIZE)
    {
        fprintf(stderr,"Error maximum allocated memory exceeded!");
        exit(1);
    }

    while (1)
    {
        printf("__DEQUE MENU__ ");
        printf("Type\n 1 for enqueue\n2 for dequeue\n3 for displaying\n4 to exit the program\n");
        printf("Please enter your option here : ");
        scanf("%d",&choice);

        switch (choice)
        {
        case 1:
            printf("__ENQUEUE__");
            printf("Enter the element to be added : ");
            scanf("%d",&item);
            printf("Type\n1 for enqueue front\n2 for enqueue rear\n");
            printf("Choose an option : ");
            scanf("%d",&choice);
            if (choice==1)
                enqueue_front(item);
            else if(choice==2)
                enqueue_rear(item);
            else
                invalid();
            break;

        case 2:
            printf("__DEQUEUE__");
            printf("Type\n1 for dequeue front\n2 for dequeue rear\n");
            printf("Choose an option : ");
            scanf("%d",&choice);
            if (choice==1)
                dequeue_front();
            else if(choice==2)
                dequeue_rear();
            else
                invalid();
            break;
        
        case 3:
            display();
        
        default:
            invalid();
            break;
        }
    }
    
    
}