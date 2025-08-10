#include <stdio.h>
#include <stdlib.h>

struct node {
    int coefficient;
    int exponent;
    struct node* link;
} * phead = NULL, *qhead = NULL, *sumhead=NULL;

struct node* createNode(int coeff, int exp) {
    struct node* new = (struct node*)malloc(sizeof(struct node));
    new->coefficient = coeff;
    new->exponent = exp;
    new->link = NULL;
    return new;
}

struct node* addTerm(struct node* head, int coeff, int exp) {
    if (coeff == 0) {
        return head;
    }

    struct node* new = createNode(coeff, exp);
    struct node* temp = head;
    struct node* prev = NULL;

    while (temp != NULL && temp->exponent > exp) {
        prev = temp;
        temp = temp->link;
    }

    if (temp != NULL && temp->exponent == exp) {
        temp->coefficient += coeff;
        free(new);
        if (temp->coefficient == 0) {
            if (prev == NULL) {
                head = temp->link;
            } else {
                prev->link = temp->link;
            }
            free(temp);
        }
    } else {
        if (prev == NULL) {
            new->link = head;
            head = new;
        } else {
            new->link = temp;
            prev->link = new;
        }
    }
    return head;
}

struct node* polynomial(struct node* head) {
    int size, exp, coeff;
    printf("Enter the number of terms in the polynomial: ");
    scanf("%d", &size);
    for (int i = 0; i < size; i++) {
        printf("Enter coefficient for term %d: ", i + 1);
        scanf("%d", &coeff);
        printf("Enter exponent for term %d: ", i + 1);
        scanf("%d", &exp);
        head = addTerm(head, coeff, exp);
    }
    return head;
}

void add(){
    struct node* i=phead, *j=qhead, *k=NULL, *new;
    sumhead = NULL;

    while (i != NULL && j != NULL)
    {
        new = NULL;
        if (i->exponent > j->exponent)
        {
            new = createNode(i->coefficient, i->exponent);
            i = i->link;
        }
        else if (i->exponent < j->exponent)
        {
            new = createNode(j->coefficient, j->exponent);
            j = j->link;
        }
        else
        {
            int coeff_sum = i->coefficient + j->coefficient;
            if (coeff_sum != 0)
            {
                new = createNode(coeff_sum, i->exponent);
            }
            i = i->link;
            j = j->link;
        }

        if (new != NULL) {
            if (sumhead == NULL)
            {
                sumhead = k = new;
            }
            else
            {
                k->link = new;
                k = new;
            }
        }
    }

    while (i != NULL)
    {
        new = createNode(i->coefficient, i->exponent);
        if (sumhead == NULL)
        {
            sumhead = k = new;
        }
        else
        {
            k->link = new;
            k = new;
        }
        i = i->link;
    }

    while (j != NULL)
    {
        new = createNode(j->coefficient, j->exponent);
        if (sumhead == NULL)
        {
            sumhead = k = new;
        }
        else
        {
            k->link = new;
            k = new;
        }
        j = j->link;
    }
}


void display(struct node* head) {
    if (head == NULL) {
        printf("0\n");
        return;
    }
    struct node* temp = head;
    while (temp != NULL) {
        if (temp->coefficient != 0) {
            if (temp != head && temp->coefficient > 0) {
                printf(" + ");
            } else if (temp->coefficient < 0) {
                printf(" - ");
            }

            if (abs(temp->coefficient) != 1 || temp->exponent == 0) {
                printf("%d", abs(temp->coefficient));
            }
            if (temp->exponent > 0) {
                printf("x");
                if (temp->exponent > 1) {
                    printf("^%d", temp->exponent);
                }
            }
        }
        temp = temp->link;
    }
    printf("\n");
}

int main() {
    int option;
    printf("This is a menu driven program for polynomials\n");
    printf("Enter the first polynomial:\n");
    phead = polynomial(phead);
    printf("\nThe polynomial is: ");
    display(phead);
    printf("Enter the second polynomial:\n");
    qhead = polynomial(qhead);
    printf("\nThe polynomial is: ");
    display(qhead);
    printf("1 for addition\n2 for multiplication\nPlease choose an option : ");
    scanf("%d",&option);
    switch (option)
    {
    case 1:
        add();
        printf("The sum of the polynomials is : ");
        display(sumhead);
        break;
    
    default:
        printf("Invalid option!");
    }
    return 0;
}