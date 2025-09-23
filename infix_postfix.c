#include <stdio.h>
#include <string.h>
#include <math.h>

#define MAX_SIZE 20

char stack[MAX_SIZE]={0},postfix[MAX_SIZE]={0};
int top=-1;
void evaluate();

struct operator
{
    char operator;
    int priority;
}operators[5];

void priorityQueueCreator(){
    char raw_list_operators[5]={'-','+','*','/','^'};
    for (int i = 0; i < 5; i++)
    {
        operators[i].operator=raw_list_operators[i];
        operators[i].priority=(i/2)*2;
    }
}

int isOperator(char item){
    for (int i = 0; i < 5; i++)
    {
        if (operators[i].operator==item)
        {
            return 1;
        }
    }
    return 0;
}

int priorityOf(char operator){
    for (int i = 0; i < 5; i++)
    {
        if (operator==operators[i].operator)
        {
            return operators[i].priority;
        }
    }
    return -1;
}

void push(char stack[],char element){
    if (top+1==MAX_SIZE)
    {
        fprintf(stderr,"Stack overflow!\n");
        return;
    }
    top++;
    stack[top]=element;
}

char pop(char stack[]){
    char item;
    if (top==-1)
    {
        fprintf(stderr,"Stack underflow!\n");
        return '\0';
    }
    item=stack[top];
    top--;
    return item;
}

void converter(char infix[]){
    int j=0;
    push(stack,'(');
    strcat(infix,")");
    for (int i = 0; infix[i]!='\0'; i++)
    {
        if (infix[i]=='(')
        {
            push(stack,'(');
        }
        else if (isOperator(infix[i]))
        {
            while (stack[top]!='(' && priorityOf(stack[top])>=priorityOf(infix[i]))
            {
                postfix[j++]=pop(stack);
            }
            push(stack,infix[i]);
        }
        else if (infix[i]==')')
        {
            while (stack[top]!='(')
            {
                postfix[j++]=pop(stack);
            }
            pop(stack);
        }
        else
        {
            postfix[j++]=infix[i];
        }
    }
    postfix[j]='\0';
    char option;
    printf("Do you want to evaluate this postfix expression? (y/N) ");
    scanf(" %c",&option);
    if (option=='y'||option=='Y')
    {
        evaluate();
    }
}

int exponent(int a, int b){
    return (int)pow((double)a,(double)b);
}

int calculate(int a, int b, char operator){
    switch (operator)
    {
    case '+':
        return a+b;
    case '-':
        return b-a;
    case '*':
        return a*b;
    case '/':
        return a/b;
    case '^':
        return exponent(a,b);
    default:
        fprintf(stderr,"Unknown operator occurred!\n");
        return 0;
    }
}

void evaluate(){
    top=-1;
    for (int i = 0; postfix[i]!='\0'; i++)
    {
        if (!isOperator(postfix[i]))
        {
            push(stack,postfix[i]);
        }
        else
        {
            char b=pop(stack);
            char a=pop(stack);
            int result=calculate(a-'0',b-'0',postfix[i]);
            push(stack,(char)(result+'0'));
        }
    }
    printf("The result of evaluation of this expression is : %d\n",stack[top]-'0');
}

int main(){
    int option;
    char expression[MAX_SIZE];
    printf("1.Convert infix to postfix\n2 Evaluate postfix expression\nPlease enter your option : ");
    scanf("%d",&option);
    switch (option)
    {
        case 1:
            printf("Enter your infix expression : ");
            scanf("%s",expression);
            priorityQueueCreator();
            converter(expression);
            printf("The postfix of this expression is : %s\n",postfix);
            break;
        case 2:
            printf("Enter your postfix expression: ");
            scanf("%s",postfix);
            evaluate();
            break;
        default:
            fprintf(stderr,"Invalid option!\n");
            break;
    }
    return 0;
}