#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* link;
}*head, *new, *ptr, *prev;

void insert_begin(int item){
    new=(struct node*)malloc(sizeof(struct node));
    new->data=item;
    new->link=head;
    head=new;
}

void insert_end(int item){
    new=(struct node*)malloc(sizeof(struct node));
    new->data=item;
    new->link=NULL;
    ptr=head;
    while (ptr->link!=NULL)
        ptr=ptr->link;
    ptr->link=new;
}

void insert_between(int item){
    new=(struct node*)malloc(sizeof(struct node));
    new->data=item;

    int key;
    printf("Enter key : ");
    scanf("%d",&key);

    ptr=head;
    while ((ptr->data!=key)&&(ptr->link!=NULL))
        ptr=ptr->link;
    if (ptr->link!=NULL)
    {
        new->link=ptr->link;
        ptr->link=new;
    }
    else
    printf("Key not found");
}

void delete_front(){
    if (head==NULL)
    {
        printf("Empty!");
    }
    ptr=head;
    printf("Deleted item : %d\n",ptr->data);
    head=head->link;
    free(ptr);
}

void delete_between(){

    int key;
    printf("Enter the key : ");
    scanf("%d",&key);

    prev=NULL;
    ptr=head;
    while ((ptr->data!=key)&&(ptr->link!=NULL))
    {
        prev=ptr;
        ptr=ptr->link;
    }
    if (ptr->link!=NULL)
    {
        printf("Deleted item : %d\n",ptr->data);
        prev->link=ptr->link;
        free(ptr);
    }
    else
    {
        printf("Key not found!\n");
    }   
}

void delete_end(){
    if (head==NULL)
    {
        printf("Empty!");
    }
    prev=NULL;
    ptr=head;

    while ((ptr->link!=NULL))
    {
        prev=ptr;
        ptr=ptr->link;
    }
    printf("Deleted item : %d\n",ptr->data);
    prev->link=NULL;
    free(ptr);
}

void display(){
    if (head==NULL)
        printf("Empty!");

    for (int i = 0; i < 10; i++)
        printf("_");
    printf("\n");
    ptr=head;
    while (ptr!=NULL)
    {
        printf("%d\n",ptr->data);
        ptr=ptr->link;
    }
}

int main(){
    int menu,choice,item;

    while(1){
        printf("This is a menu driven program for queue :  \n Type 1 for insertion :  \n Type 2 for deletion :  \n Type 3 for displaying the queue :  \n Type 0 for quitting : \n");
        scanf("%d",&menu);
        switch(menu){
        case 1:
            printf("1 for front\n 2 for end\n 3 for between : ");
            scanf("%d",&choice);
            printf("Enter the item : ");
            scanf("%d",&item);
            if (choice==1)
            insert_begin(item);
            else if(choice==2)
            insert_end(item);
            else
            insert_between(item);
            break;
        case 2:
            printf("1 for front\n 2 for end\n 3 for between : ");
            scanf("%d",&choice);
            if (choice==1)
            delete_front();
            else if(choice==2)
            delete_end();
            else
            delete_between();
            break;
        case 3:
            display();
            break;
        case 0:
            exit(0);
            break;
        default:
            printf("Invalid");
        }
        }
}