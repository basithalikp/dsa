#include <stdio.h>
#include <limits.h>
#define MAX_SIZE 30

typedef struct {
    int value;
    int arrayIndex;
} HeapNode;

void swap(HeapNode *a, HeapNode *b)
{
    HeapNode temp = *a;
    *a = *b;
    *b = temp;
}

void minHeapify(HeapNode heap[], int index, int heapSize)
{
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < heapSize && heap[left].value < heap[smallest].value)
    {
        smallest = left;
    }
    if (right < heapSize && heap[right].value < heap[smallest].value)
    {
        smallest = right;
    }

    if (smallest != index)
    {
        swap(&heap[index], &heap[smallest]);
        minHeapify(heap, smallest, heapSize);
    }
}

void merge(int subArrays[][MAX_SIZE], int array[], int k, int subArraySizes[], int size)
{
    HeapNode heap[MAX_SIZE];
    int pointers[MAX_SIZE];
    int heapSize = 0;

    for (int i = 0; i < k; i++)
    {
        pointers[i] = 0;
        if (subArraySizes[i] > 0)
        {
            heap[heapSize].value = subArrays[i][0];
            heap[heapSize].arrayIndex = i;
            heapSize++;
        }
    }

    for (int i = (heapSize / 2) - 1; i >= 0; i--)
    {
        minHeapify(heap, i, heapSize);
    }

    for (int i = 0; i < size; i++)
    {
        HeapNode root = heap[0];
        array[i] = root.value;
        
        pointers[root.arrayIndex]++;

        if (pointers[root.arrayIndex] < subArraySizes[root.arrayIndex])
        {
            heap[0].value = subArrays[root.arrayIndex][pointers[root.arrayIndex]];
            heap[0].arrayIndex = root.arrayIndex;
        }
        else
        {
            heap[0].value = INT_MAX;
        }
        
        minHeapify(heap, 0, heapSize);
    }
}

void mergeSort(int array[], int size, int k)
{
    if (size <= 1)
    {
        return;
    }

    int subArrays[MAX_SIZE][MAX_SIZE];
    int subArraySizes[MAX_SIZE];
    int currentPosition = 0;

    for (int i = 0; i < k; i++)
    {
        int chunkSize = size / k;
        if (i < size % k)
        {
            chunkSize++;
        }
        
        subArraySizes[i] = chunkSize;
        for (int j = 0; j < chunkSize; j++)
        {
            subArrays[i][j] = array[currentPosition++];
        }
    }
    
    for (int i = 0; i < k; i++)
    {
        if(subArraySizes[i] > 0)
        {
            mergeSort(subArrays[i], subArraySizes[i], k);
        }
    }
    
    merge(subArrays, array, k, subArraySizes, size);
}

void display(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main()
{
    int array[MAX_SIZE], size, k;
    printf("This is a program for k-way merge sort!\n");
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    if (size > MAX_SIZE || size <= 0)
    {
        printf("Invalid size! Please enter a size between 1 and %d.\n", MAX_SIZE);
        return 1;
    }

    printf("Enter the value for k: ");
    scanf("%d", &k);
    
    if (k <= 1)
    {
        printf("Invalid value for k! Please enter a k greater than 1.\n");
        return 1;
    }

    printf("Enter the array: \n");
    for (int i = 0; i < size; i++)
    {
        printf("Enter the %dth element: ", i + 1);
        scanf("%d", &array[i]);
    }

    printf("Input array is: ");
    display(array, size);

    mergeSort(array, size, k);

    printf("The sorted array is: \n");
    display(array, size);
    return 0;
}