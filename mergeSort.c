#include<stdio.h>
#define MAX_SIZE 30

void merge(int leftArray[], int rightArray[], int array[], int size){
    int leftSize = size / 2;
    int rightSize = size - leftSize;
    int i = 0, r = 0, l = 0;

    while (l < leftSize && r < rightSize) {
        if (leftArray[l] <= rightArray[r]) {
            array[i] = leftArray[l];
            i++; l++;
        } else {
            array[i] = rightArray[r];
            i++; r++;
        }
    }

    while (l < leftSize) {
        array[i] = leftArray[l];
        i++; l++;
    }

    while (r < rightSize) {
        array[i] = rightArray[r];
        i++; r++;
    }
}

void mergeSort(int array[], int size){
    if (size <= 1) {
        return;
    }

    int middle = size / 2;
    int leftArray[MAX_SIZE], rightArray[MAX_SIZE];

    for (int i = 0; i < middle; i++) {
        leftArray[i] = array[i];
    }

    for (int i = middle; i < size; i++) {
        rightArray[i - middle] = array[i];
    }

    mergeSort(leftArray, middle);
    mergeSort(rightArray, size - middle);

    merge(leftArray, rightArray, array, size);
}

void display(int array[], int size){
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main(){
    int array[MAX_SIZE], size;
    printf("This is a program for merge sort!\n");
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    if (size > MAX_SIZE || size <= 0) {
        printf("Invalid size! Please enter a size between 1 and %d.\n", MAX_SIZE);
        return 1;
    }

    printf("Enter the array: \n");
    for (int i = 0; i < size; i++) {
        printf("Enter the %dth element: ", i + 1);
        scanf("%d", &array[i]);
    }

    printf("Input array is: ");
    display(array, size);

    mergeSort(array, size);

    printf("The sorted array is: \n");
    display(array, size);
    return 0;
}