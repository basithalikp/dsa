#include <stdio.h>
#include <stdlib.h>

struct node{
    int coefficient;
    int exponent;
    struct node* link;
}*phead=NULL,*qhead=NULL;

struct node* insert(int coeff, int exp, struct node* head){
    struct node* new = (struct node*)malloc(sizeof(struct node));
    new->coefficient = coeff;
    new->exponent = exp;
    new->link = NULL;

    if (head == NULL || exp > head->exponent){
        new->link = head;
        head = new;
    }
    else{
        struct node* temp = head;
        while (temp->link != NULL && temp->link->exponent > exp)
            temp = temp->link;
        new->link = temp->link;
        temp->link = new;
    }
    return head;
}

struct node* polynomial(struct node* head){
    int size,exp,coeff;
    printf("Enter the size of the polynomial : ");
    scanf("%d",&size);
    for (int i = 0; i < size; i++)
    {
        printf("Enter the coefficient of %dth term of the polynomial : ",i+1);
        scanf("%d",&coeff);
        printf("Enter the exponent of %dth term of the polynomial : ",i+1);
        scanf("%d",&exp);
        head=insert(coeff,exp,head);
    }
    return head;
}

void display(struct node* head){
    if (head==NULL)
        printf("Empty polynomial!");
    for (struct node* i = head; i!=NULL; i=i->link){
        printf("%dx^%d",i->coefficient,i->exponent);
        if(i->link!=NULL)
            printf("+");
    }
    printf("\n");
}

int main(){
    printf("This is a menu driven program for polynomials\n");
    printf("Enter the first polynomial : \n");
    phead=polynomial(phead);
    display(phead);
    return 0;
}