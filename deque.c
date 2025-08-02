#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 10

int arr[MAX_SIZE], size, front = -1, rear = -1;

void invalid() {
    fprintf(stderr, "Invalid choice!\n");
}

int is_full() {
    if ((front == 0 && rear == size - 1) || front == rear + 1) {
        printf("Queue full!\n");
        return 1;
    }
    return 0;
}

int is_empty() {
    if (front == -1) {
        printf("Queue empty!\n");
        return 1;
    }
    return 0;
}

void enqueue_front(int item) {
    if (is_full())
        return;

    if (front == -1) {
        front = 0;
        rear = 0;
    } else if (front == 0)
        front = size - 1;
    else
        front--;

    arr[front] = item;
    printf("Element %d was successfully added to the front!\n", item);
}

void enqueue_rear(int item) {
    if (is_full())
        return;

    if (front == -1) {
        front = 0;
        rear = 0;
    } else if (rear == size - 1)
        rear = 0;
    else
        rear++;

    arr[rear] = item;
    printf("Element %d was successfully added to the rear!\n", item);
}

void dequeue_front() {
    if (is_empty())
        return;

    printf("Deleted item is %d\n", arr[front]);
    if (front == rear) {
        front = -1;
        rear = -1;
    } else {
        if (front == size - 1)
            front = 0;
        else
            front++;
    }
}

void dequeue_rear() {
    if (is_empty())
        return;

    printf("Deleted item is %d\n", arr[rear]);
    if (front == rear) {
        front = -1;
        rear = -1;
    } else if (rear == 0)
        rear = size - 1;
    else
        rear--;
}

void display() {
    if (is_empty())
        return;

    printf("Elements in deque are: \n");
    int i = front;
    while (1) {
        printf("%d\n", arr[i]);
        if (i == rear)
            break;
        i = (i + 1) % size;
    }
}

int main() {
    int choice, item;

    printf("This is a menu driven program for Deque!\n");
    printf("Please enter the size of the deque (max %d): ", MAX_SIZE);
    scanf("%d", &size);

    if (size > MAX_SIZE || size <= 0) {
        fprintf(stderr, "Error: Invalid size. Please enter a size between 1 and %d.\n", MAX_SIZE);
        exit(1);
    }

    while (1) {
        printf("\n__DEQUE MENU__\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Please enter your option here: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("\n__ENQUEUE__\n");
            printf("Enter the element to be added: ");
            scanf("%d", &item);
            printf("1. Enqueue Front\n");
            printf("2. Enqueue Rear\n");
            printf("Choose an option: ");
            scanf("%d", &choice);
            if (choice == 1)
                enqueue_front(item);
            else if (choice == 2)
                enqueue_rear(item);
            else
                invalid();
            break;

        case 2:
            printf("\n__DEQUEUE__\n");
            printf("1. Dequeue Front\n");
            printf("2. Dequeue Rear\n");
            printf("Choose an option: ");
            scanf("%d", &choice);
            if (choice == 1)
                dequeue_front();
            else if (choice == 2)
                dequeue_rear();
            else
                invalid();
            break;

        case 3:
            display();
            break;
        case 4:
            exit(0);
            break;
        default:
            invalid();
            break;
        }
    }

    return 0;
}
