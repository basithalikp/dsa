#include <stdio.h>
#define MAX_SIZE 20

int arr[MAX_SIZE], size = 0;

void read(){
    printf("Please enter your size : ");
    scanf("%d", &size);
    for (int i = 0; i < size; i++)
    {
        printf("Enter the %dth element : ", i + 1);
        scanf("%d", &arr[i]);
    }
}

void display(){
    if (size == 0)
    {
        printf("Empty array!\n");
        return;
    }
    
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void swap(int i, int j){
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void bubbleSort(){
    for (int i = 0; i < size-1; i++)
    {
        for (int j = 0; j < size-i-1; j++)
        {
            if (arr[j] > arr[j+1])
            {
                swap(j,j+1);
            }
        }
    }
    printf("The sorted array is : ");
    display();
}

void insertionSort(){
    for (int i = 1; i < size; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
    printf("The sorted array is : ");
    display();
}

void selectionSort(){
    for (int i =0; i < size - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
        swap(i, minIndex);
    }
    printf("The sorted array is : ");
    display();
}

int main(){
    int choice;
    printf("This is a menu driven program for sorting!\n");
    printf("Please Input the array you want to sort!\n");
    read();
    printf("This is the input unsorted array : ");
    display();
    while (1)
    {
        printf("Choose\n1 for Bubble sort\n2 for Insertion Sort\n3 for Selection Sort\n4 to display\n5 to exit\nPlease enter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            bubbleSort();
            break;
        case 2:
            insertionSort();
            break;
        case 3:
            selectionSort();
            break;
        case 4:
            display();
            break;
        case 5:
            return 0;
            break;
        default:
            break;
        }
    }
    return 0;
}