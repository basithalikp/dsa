#include <stdio.h>

struct node{
    int coefficient;
    int exponent;
    struct node* link;
}*head=NULL;

void insert(int coeff, int exp){
    struct node* new= (struct node*)malloc(sizeof(struct node));
    if (head==NULL||head->exponent<exp)
    {
        new->link=head->link;
        head=new;
    }
    else{
        struct node* temp=head;
        while (temp!=NULL&&temp->exponent<exp)
            temp=temp->link;
        new->link=temp->link;
        temp->link=new;
    }
}

void polynomial(){
    int size,exp,coeff;
    printf("Enter the size of the polynomial : ");
    scanf("%d",&size);
    for (int i = 0; i < size; i++)
    {
        printf("Enter the coefficient of %dth term of the polynomial : ");
        scanf("%d",&coeff);
        printf("Enter the exponent of %dth term of the polynomial : ");
        scanf("%d",&exp);
        insert(coeff,exp);
    }
}

int main(){
    printf("This is a menu driven program for polynomials\n");
    printf("Enter the first polynomial : \n");
    polynomial();
}