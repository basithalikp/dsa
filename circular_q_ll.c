#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};

struct node *front = NULL, *rear = NULL;

void enqueue(int element){
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data=element;
    newNode->link=NULL;
    if (front==NULL)
    {
        front = rear = newNode;
        rear->link = front;
    }
    else{
        rear->link=newNode;
        rear=newNode;
        rear->link=front;
    }
}

void dequeue(){
    if (front == NULL)
    {
        printf("Empty Queue!\n");
        return;
    }
    else if (front == rear)
    {
        printf("The deleted element is %d\n",front->data);
        front = rear = NULL;
    }
    else{
        struct node *temp = front;
        printf("The deleted element is %d",front->data);
        front = front->link;
        rear->link = front;
        free(temp);
    }
}

void display(){
    if(front == NULL){
        printf("Empty Queue\n");
        return;
    }
    struct node* temp = front;
    do
    {
        printf("%d\n",temp->data);
        temp = temp->link;
    } while (temp!=front);
}

int main(){
    int option,element;

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
            printf("Enter the element to be inserted : ");
            scanf("%d",&element);
            enqueue(element);
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