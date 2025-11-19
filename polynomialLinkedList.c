#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int exponent, coefficient;
    struct node *link;
} Node;

Node *getNode(){
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->link = NULL;
    return newNode;
}

Node *addition(Node *pHead, Node *qHead){
    Node *i = pHead, *j = qHead, *sumHead = NULL, *k = NULL;
    Node *newNode;

    while (i != NULL && j != NULL)
    {
        newNode = NULL; 
        if (i->exponent > j->exponent)
        {
            newNode = getNode();
            newNode->coefficient = i->coefficient;
            newNode->exponent = i->exponent;
            i = i->link;
        }
        else if (j->exponent > i->exponent)
        {
            newNode = getNode();
            newNode->coefficient = j->coefficient;
            newNode->exponent = j->exponent;
            j = j->link;
        }
        else
        {
            int sumCoeff = i->coefficient + j->coefficient;
            if (sumCoeff != 0)
            {
                newNode = getNode();
                newNode->coefficient = sumCoeff;
                newNode->exponent = i->exponent;
            }
            i = i->link;
            j = j->link;
        }

        if (newNode != NULL)
        {
            if (sumHead == NULL)
            {
                sumHead = k = newNode;
            }
            else
            {
                k->link = newNode;
                k = newNode;
            }
        }
    }
    while (i != NULL)
    {
        newNode = getNode();
        newNode->coefficient = i->coefficient;
        newNode->exponent = i->exponent;
        i = i->link;
        if (sumHead == NULL) { sumHead = k = newNode; }
        else { k->link = newNode; k = newNode; }
    }
    while (j != NULL)
    {
        newNode = getNode();
        newNode->coefficient = j->coefficient;
        newNode->exponent = j->exponent;
        j = j->link;
        if (sumHead == NULL) { sumHead = k = newNode; }
        else { k->link = newNode; k = newNode; }
    }
    return sumHead;
}

Node *multiplication(Node *pHead, Node *qHead){
    Node *i = pHead, *j;
    Node *prodHead = NULL;
    Node *newNode;

    if (pHead == NULL || qHead == NULL) {
        return NULL;
    }

    for (i = pHead; i != NULL; i = i->link)
    {
        for (j = qHead; j != NULL; j = j->link)
        {
            int newCoeff = i->coefficient * j->coefficient;
            int newExp = i->exponent + j->exponent;

            if (newCoeff == 0) continue;

            Node *l = prodHead;
            Node *prev = NULL;
            
            while (l != NULL && l->exponent > newExp)
            {
                prev = l;
                l = l->link;
            }

            if (l != NULL && l->exponent == newExp)
            {
                l->coefficient += newCoeff;
                if (l->coefficient == 0)
                {
                    if (prev == NULL) {
                        prodHead = l->link;
                    } else {
                        prev->link = l->link;
                    }
                    free(l);
                }
            }
            else
            {
                newNode = getNode();
                newNode->coefficient = newCoeff;
                newNode->exponent = newExp;
                
                if (prev == NULL)
                {
                    newNode->link = prodHead;
                    prodHead = newNode;
                }
                else
                {
                    newNode->link = l;
                    prev->link = newNode;
                }
            }
        }
    }
    return prodHead;
}

Node *read(){
    Node *head = NULL;
    int size, coefficient, exponent;
    Node *newNode, *k, *prev;
    printf("Enter the number of terms in the polynomial : ");
    scanf("%d", &size);
    for (int i = 0; i < size; i++)
    {
        printf("Enter coefficient and exponent respectively : ");
        scanf("%d%d", &coefficient, &exponent);

        if (coefficient == 0) continue;

        newNode = getNode();
        newNode->coefficient = coefficient;
        newNode->exponent = exponent;

        if (head == NULL || newNode->exponent > head->exponent)
        {
            newNode->link = head;
            head = newNode;
        }
        else if (newNode->exponent == head->exponent)
        {
            head->coefficient += newNode->coefficient;
            free(newNode);
            if (head->coefficient == 0) {
                Node* temp = head;
                head = head->link;
                free(temp);
            }
        }
        else
        {
            prev = head;
            k = head->link;
            while (k != NULL && newNode->exponent < k->exponent)
            {
                prev = k;
                k = k->link;
            }
            
            if (k != NULL && newNode->exponent == k->exponent)
            {
                k->coefficient += newNode->coefficient;
                free(newNode);
                if (k->coefficient == 0) {
                    prev->link = k->link;
                    free(k);
                }
            }
            else
            {
                newNode->link = k;
                prev->link = newNode;
            }
        }
    }
    printf("Successfully read polynomial!\n");
    return head;
}

void display(Node *head){
    Node *ptr = head;
    if (head == NULL)
    {
        printf("0\n");
        return;
    }
    while (ptr->link != NULL)
    {
        printf("%dx^%d + ", ptr->coefficient, ptr->exponent);
        ptr = ptr->link;
    }
    printf("%dx^%d\n", ptr->coefficient, ptr->exponent);
}

int main(){
    Node *pHead = NULL, *qHead = NULL, *rHead = NULL;
    int choice;
    printf("This is a menu driven program for polynomial using SLL\n");
    printf("Enter the first polynomial : \n");
    pHead = read();
    printf("The entered polynomial is :\n");
    display(pHead);
    printf("Enter the second polynomial : \n");
    qHead = read();
    printf("The entered polynomial is :\n");
    display(qHead);
    while (1)
    {
        printf("Enter:\n1 for addition\n2 for multiplication\n3 to display result\n4 to exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            rHead = addition(pHead, qHead);
            printf("Sum:\n");
            display(rHead);
            break;
        case 2:
            rHead = multiplication(pHead, qHead);
            printf("Product:\n");
            display(rHead);
            break;
        case 3:
            printf("Current Result:\n");
            display(rHead);
            break;
        case 4:
            return 0;
            break;
        default:
            printf("Invalid!\n");
            break;
        }
    }
return 0;   
}