#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

int stack[10],item;
int top=-1,size;

void push(){

    if ((top+1)==size)
    {
        printf("\nStack overflow!\n");
        return;
    }

    else
    {
        printf("\nEnter the element to be added : \n");
        scanf("%d",&item);
        top++;
        stack[top]=item;
        return;
    }
    
}

void pop(){
    if (top==-1)
    {
        printf("\nStack Underflow!\n");
        return;
    }
    else
    {
        item=stack[top];
        printf("Deleted item is %d \n",item);
        top--;
        return;
    }  
}

void display(){

    register int i;

    if (top==-1)
    {
        printf("\nEmpty stack! \n");
        return;
    }
    else
    {
        printf("Current stack is : \n");
        for ( i = top; i >= 0 ; i--)
        {
            printf("%d \n",stack[i]);
        }
        
    }

}

int main(){
    int option;

    printf("Enter the size of the stack : ");
    scanf("%d",&size);

    if (size>=MAX_SIZE)
    {
        fprintf(stderr,"Error : Maximum allocated memory overflowed!");
        exit(1);
    }

    while (1)
    {

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
            printf("Invalid option");
            break;
        }
    }
    
    return 0;
    
}