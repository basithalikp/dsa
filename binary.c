#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 20

int stack[10],item;
int top=-1,size=MAX_SIZE;

void push(int element){

    if ((top+1)==size)
    {
        printf("\nStack overflow!\n");
        return;
    }

    else
    {
        top++;
        stack[top]=element;
        return;
    }
    
}

int pop(){
    if (top==-1)
    {
        printf("\nStack Underflow!\n");
        return -1;
    }
    else
    {
        item=stack[top];
        top--;
        return item;
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
    int number,remainder;

    printf("Enter the number to be converted to binary : ");
    scanf("%d",&number);

    while (number!=1)
    {
        remainder=number%2;
        number/=2;
        push(remainder);
    }
    push(number);
    display();
    return 0;

}