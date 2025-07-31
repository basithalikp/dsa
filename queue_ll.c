#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
}*front, *rear;


void enqueue(){
    int item;
    printf("Enter the element to be added : ");
    scanf("%d",&item);

    struct node* new = (struct node*)malloc(sizeof(struct node));
    if (new==NULL)
    {
        fprintf(stderr,"No enough memory!\n");
        return;
    }
    new->data=item;
    new->link=NULL;

    if (front == NULL)
    {
        front = rear = new;
    }
    else
    {
        rear->link = new;
        rear = new;
    }
    printf("Element %d was successfully added!\n",item);
    return;
}

void dequeue(){
    if (front==NULL)
    {
        fprintf(stderr,"Queue Underflow!\n");
        return;
    }
    struct node* temp=front;
    front=front->link;
    if (front == NULL)
    {
        rear = NULL;
    }
    printf("Deleted item is %d\n",temp->data);
    free(temp);
    return;
}

void display(){
    if (front==NULL)
    {
        fprintf(stderr,"Queue is empty!\n");
        return;
    }

    struct node* ptr=front;
    while (ptr!=NULL)
    {
        printf("%d\n",ptr->data);
        ptr=ptr->link;
    }
}

int main(){

    while (1)
    {
        int option;
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
            printf("Invalid option\n");
            break;
        }
    }
    
    return 0;
}
