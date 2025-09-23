#include <stdio.h>
#include <stdlib.h>

struct node
{
    int size, address;
    struct node *link;
} *head = NULL;

int addressPointer = 1000;

struct node* createNode(int size, int address){
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->size = size;
    newNode->address = address;
    newNode->link = NULL;
    return newNode;
}

void blockAllocator(int size, int address){
    struct node *newNode = createNode(size, address);
    if (head == NULL) {
        head = newNode;
        return;
    }
    struct node *ptr = head;
    while (ptr->link != NULL)
    {
        ptr = ptr->link;
    }
    ptr->link = newNode;
}

int addressAllocator(){
    return addressPointer+=1000;
}

void display(){
    int counter = 1;
    struct node *ptr = head;
    if (ptr == NULL)
    {
        printf("No blocks allocated!\n");
        return;
    }
    do
    {
        printf("%d) Address: %d Size: %d\n", counter++, ptr->address, ptr->size);
        ptr = ptr->link;
    } while (ptr != NULL);
}

void firstFit(int size){
    struct node *temp = head, *prev = NULL;
    while (temp != NULL)
    {
        if (temp->size == size)
        {
            if (prev == NULL)
            {
                head = head->link;
            }
            else
            {
                prev->link = temp->link;
            }
            free(temp);
            return;
        }
        else if (temp->size > size)
        {
            temp->address += size;
            temp->size -= size;
            return;
        }
        else
        {
            prev = temp;
            temp = temp->link;
        }
    }
}

void Fit(int size, int whichFit){
    struct node *temp = head, *prev = NULL, *bestBlock = NULL, *bestPrev = NULL;
    while (temp != NULL)
    {
        if (temp->size >= size)
        {
            if (bestBlock == NULL || (whichFit == 1 ? temp->size < bestBlock->size : temp->size > bestBlock->size))
            {
                bestPrev = prev;
                bestBlock = temp;
            }
        }
        prev = temp;
        temp = temp->link;
    }
    if (bestBlock == NULL)
    {
        printf("No sufficient block left!\n");
        return;
    }
    if (bestBlock->size == size)
    {
        if (bestPrev == NULL)
        {
            head = head->link;
        }
        else
        {
            bestPrev->link = bestBlock->link;
        }
        free(bestBlock);
    }
    else if (bestBlock->size > size)
    {
        bestBlock->address += size;
        bestBlock->size -= size;
    }
}

int main(){
    char choice = 'y';
    int size, address, option;
    printf("This is a menu driven program for memory allocation\n");
    while (choice != 'n' && choice != 'N')
    {
        printf("__Memory block distribution__\n");
        printf("Enter the size of the memory block: ");
        scanf("%d", &size);
        printf("Enter the address of the memory block\n  or  \nEnter a negative number for automatic address: ");
        scanf("%d", &address);
        if (address < 0)
        {
            address = addressAllocator();
        }
        blockAllocator(size, address);
        printf("Memory block of size %d and address %d allocated successfully!\n", size, address);
        printf("Currently allocated blocks : \n");
        display();
        printf("Do you want more blocks? (y/N) ");
        scanf(" %c", &choice);
    }
    while (1)
    {
        printf("__Memory allocation__\n");
        printf("Choose\n1 for First fit\n2 for Best fit\n3 for Worst fit\n4 to display\n5 to exit\n");
        printf("Please choose an option: ");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            printf("__FIRST FIT__\n");
            printf("Enter the requested size : ");
            scanf("%d", &size);
            firstFit(size);
            break;
        case 2:
            printf("__BEST FIT__\n");
            printf("Enter the requested size : ");
            scanf("%d", &size);
            Fit(size,1);
            break;
        case 3:
            printf("__WORST FIT__\n");
            printf("Enter the requested size : ");
            scanf("%d", &size);
            Fit(size,0);
            break;
        case 4:
            printf("Allocated memory blocks:\n");
            display();
            break;
        case 5:
            printf("Quitting program...\n");
            exit(0);
            break;
        default:
            printf("Invalid option!\n");
            break;
        }
    }
    return 0;
}