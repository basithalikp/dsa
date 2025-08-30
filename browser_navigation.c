#include <stdio.h>
#include <string.h>

#define MAX_SIZE 20

struct String
{
    char string[MAX_SIZE];
} forwardStack[MAX_SIZE], backwardStack[MAX_SIZE], currentURL;

int topForward = -1, topBackward = -1;

void push(struct String element, struct String arr[], int *top)
{
    if (*top == MAX_SIZE - 1)
    {
        fprintf(stderr, "Stack overflow!\n");
        return;
    }
    arr[++(*top)] = element;
}

struct String pop(struct String arr[], int *top)
{
    struct String empty = {""};
    if (*top == -1)
    {
        return empty;
    }
    return arr[(*top)--];
}

void flush(struct String arr[], int *top)
{
    *top = -1;
}

void backNavigation()
{
    if (topBackward == -1)
    {
        printf("No history\n");
        return;
    }
    if (topBackward == 0)
    {
        return;
    }
    push(currentURL, forwardStack, &topForward);
    currentURL = pop(backwardStack, &topBackward);
}

void forwardNavigation()
{
    if (topForward == -1)
    {
        printf("No history\n");
        return;
    }
    push(currentURL, backwardStack, &topBackward);
    currentURL = pop(forwardStack, &topForward);
}

void newURL()
{
    push(currentURL, backwardStack, &topBackward);
    printf("Enter the new URL: ");
    scanf("%s", currentURL.string);
    flush(forwardStack, &topForward);
}

void display()
{
    if (strlen(currentURL.string) == 0)
    {
        printf("No current page\n");
        return;
    }
    printf("Current page is: %s\n", currentURL.string);
}

int main()
{
    int choice = 0;
    while (choice != 5)
    {
        printf("This is a menu driven program for browser navigation!\n");
        printf("Enter:\n1 for Back\n2 for Forward\n3 to Enter new URL\n4 to display current URL\n");
        printf("5 to exit\nPlease choose an option: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            backNavigation();
            break;
        case 2:
            forwardNavigation();
            break;
        case 3:
            newURL();
            break;
        case 4:
            display();
            break;
        case 5:
            printf("Quitting program!\n");
            break;
        default:
            printf("Invalid option\n");
            break;
        }
    }
    return 0;
}