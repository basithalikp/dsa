#include <stdio.h>
#define MAX_SIZE 20

int size, arr[MAX_SIZE];

int linearSearch(int element){
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == element)
        {
            return i;
        }
    }
    return -1;
}

void sort(){
    for (int i = 0; i < size-1; i++)
    {
        for (int j = 1; j < size-i-1; i++)
        {
            if (arr[j] > arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int binarySearch(int element){
    int l = 0, r = size - 1;
    while (l <= r)
    {
        int mid = (l + r)/2;
        if (element < arr[mid])
        {
            r = mid-1;
        }
        else if (element > arr[mid])
        {
            l = mid+1;
        }
        else
        {
            return mid;
        }
    }
}

void read(){
    printf("Enter the size : ");
    scanf("%d", &size);
    for (int i = 0; i < size; i++)
    {
        printf("Enter %dth element : ", i+1);
        scanf("%d", &arr[i]);
    }
}

void display(){
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(){
    int choice, element;
    printf("This is a program for search!");
    printf("Input the array : \n");
    read();
    printf("Enter the element to search : ");
    scanf("%d", &element);
    printf("Which searching algorithm to use?\n1 for Linear Search\n2 for Binary search\n Enter your choice : ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        element = linearSearch(element);
        break;
    case 2:
        element = binarySearch(element);
        break;
    default:
        printf("Invalid!\n");
        break;
    }
    if (element < 0)
    {
        printf("Not found!");
    }
    else
    {
        printf("Element found at %d",element+1);
    }
    return 0;
}