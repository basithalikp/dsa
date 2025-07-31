#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
}*head;


void push(){
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
    new->link=head;
    head=new;
    printf("Element %d was successfully added!\n",item);
    return;
}

void pop(){
    if (head==NULL)
    {
        fprintf(stderr,"Stack Underflow!\n");
        return;
    }
    struct node* temp=head;
    head=head->link;
    printf("Deleted item is %d\n",temp->data);
    free(temp);
    return;
}

void display(){
    if (head==NULL)
    {
        fprintf(stderr,"Stack Underflow!\n");
        return;
    }

    struct node* ptr=head;
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
        printf("This is a menu driven program for stack \n ");
        printf("Please choose an option : \n");
        printf("1 for push (Addition of an element)\n");
        printf("2 for pop (Deletion of an element)\n");
        printf("3 for display (Displaying all elements)\n");
        printf("4 to exit the program\n");
        printf("Please choose an option : ");
        scanf("%d",&option);

        switch (option)
        {
        case 1:
            
            push();
            break;
        case 2:
            pop();
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