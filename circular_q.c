#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

int queue[10],item;
int front=-1,rear=-1,size;

void enqueue(){

    if ((rear+1)%size==front)
    {
        printf("\nqueue overflow!\n");
        return;
    }

    printf("\nEnter the element to be added : \n");
    scanf("%d",&item);
    rear=(rear+1)%size;
    queue[rear]=item;
    if (front==-1)
        front++;
    
    return;    
}

void dequeue(){

    if (front==-1 && rear==-1)
    {
        printf("\nqueue Underflow!\n");
        return;
    }
    
    item=queue[front];
    printf("Deleted item is %d \n",item);

    if (front==rear)
    {
        front=-1;
        rear=-1;
    }
    else
        front=(front+1)%size;

    return;
}

void display(){

    register int i;

    if (front==-1)
    {
        printf("\nEmpty queue! \n");
        return;
    }
    else
    {
        printf("Current queue is : \n");
        for ( i = front; i != rear ; i=(i+1)%size)
            printf("%d \n",queue[i]);

        printf("%d \n",queue[rear]);
    }

}

int main(){
    int option;

    printf("Enter the size of the queue : ");
    scanf("%d",&size);

    if (size>=MAX_SIZE)
    {
        fprintf(stderr,"Error : Maximum allocated memory overflowed!");
        exit(1);
    }

    while (1)
    {
        printf("This is a menu driven program for queue \n ");
        printf("Please choose an option : \n");
        printf("1 for enqueue (Addition of an element)\n");
        printf("2 for dequeue (Deletion of an element)\n");
        printf("3 for display (Displaying all elements)\n");
        printf("4 to exit the program\n");
        printf("Please choose an option : ");
        scanf("%d",&option);

        switch (option)
        {
        case 1:
            enqueue();
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
            printf("Invalid option");
            break;
        }
    }
    
    return 0;
    
}