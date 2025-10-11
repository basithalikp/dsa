#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#define MAX 20

struct node
{
    char symbol;
    struct node *lc, *rc;
} *root = NULL;

struct node *stack[MAX];
int top = -1;

struct node *createNode(char symbol)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->symbol = symbol;
    newNode->rc = newNode->lc = NULL;
    return newNode;
}

void push(struct node *newNode)
{
    top++;
    stack[top] = newNode;
}

struct node *pop()
{
    return stack[(top--)];
}

void flush()
{
    top = -1;
}

struct node *expressionTree(char expression[])
{
    struct node *operator;
    flush();
    for (int i = 0; expression[i] != '\0'; i++)
    {
        if (isalnum(expression[i]))
        {
            push(createNode(expression[i]));
        }
        else
        {
            operator = createNode(expression[i]);
            operator->rc = pop();
            operator->lc = pop();
            push(operator);
        }
    }
    return stack[top];
}

void inOrder(struct node *p)
{
    if (p != NULL)
    {
        inOrder(p->lc);
        printf("%c ", p->symbol);
        inOrder(p->rc);
    }
}

void preOrder(struct node *p)
{
    if (p != NULL)
    {
        printf("%c ", p->symbol);
        preOrder(p->lc);
        preOrder(p->rc);
    }
}

void postOrder(struct node *p)
{
    if (p != NULL)
    {
        postOrder(p->lc);
        postOrder(p->rc);
        printf("%c ", p->symbol);
    }
}

int main()
{
    int choice, displayChoice;
    char expression[MAX];
    printf("This is a program for expression tree\n");
    while (1)
    {
        printf("\nEnter\n1 to Enter the expression\n2 to display\n3 to exit\nPlease enter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the postfix expression: ");
            scanf("%s", expression);
            root = expressionTree(expression);
            printf("Expression tree created.\n");
            break;
        case 2:
            if (root == NULL)
            {
                printf("Warning! The tree is empty. Please enter an expression first.\n");
            }
            else
            {
                printf("Display format?\n1 - prefix\n2 - postfix\n3 - infix\nEnter your choice : ");
                scanf("%d", &displayChoice);
                switch (displayChoice)
                {
                case 1:
                    printf("Prefix: ");
                    preOrder(root);
                    break;
                case 2:
                    printf("Postfix: ");
                    postOrder(root);
                    break;
                case 3:
                    printf("Infix: ");
                    inOrder(root);
                    break;
                default:
                    printf("Invalid display choice.\n");
                    break;
                }
                printf("\n");
            }
            break;
        case 3:
            exit(0);
            break;
        default:
            printf("Invalid choice\n");
            break;
        }
    }
    return 0;
}