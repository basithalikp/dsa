#include <stdio.h>
#define MAX_SIZE 20

int size, arr[MAX_SIZE];

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

int binarySearch(int element, int left, int right){
    sort();
    int mid = (left + right)/2;
    if (left > right)
    {
        return -1;
    }
    else if (element < arr[mid])
    {
        return binarySearch(element, left, mid - 1);
    }
    else if (element > arr[mid])
    {
        return binarySearch(element, mid + 1, right);
    }
    else
    {
        return mid;
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
        break;
    case 2:
        element = binarySearch(element, 0, size - 1);
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