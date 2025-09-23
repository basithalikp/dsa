#include <stdio.h>
#define MAX_SIZE 20

int visited[MAX_SIZE], adjascentMatrix[MAX_SIZE][MAX_SIZE], top = -1, stack[MAX_SIZE], size;

void push(int element) {
    if (top >= MAX_SIZE - 1) {
        printf("Stack overflow!\n");
        return;
    }
    stack[++top] = element;
}

int pop() {
    if (top == -1) {
        printf("Empty stack!\n");
        return -1; 
    }
    return stack[top--];
}

int initialization() {
    if (size > MAX_SIZE) {
        printf("Not enough memory!\n");
        return 0;
    }
    for (int i = 0; i < size; i++) {
        visited[i] = 0;
        for (int j = 0; j < size; j++) {
            adjascentMatrix[i][j] = 0;
        }
    }
    return 1;
}

void read() {
    int i, j, edges;
    printf("Enter the number of vertices : ");
    scanf("%d", &size);
    if (!initialization()) { 
        return;
    }
    printf("Enter the number of edges : ");
    scanf("%d", &edges);
    for (int e = 0; e < edges; e++) {
        printf("Enter two vertices of an edge : ");
        scanf("%d%d", &i, &j);
        adjascentMatrix[i][j] = adjascentMatrix[j][i] = 1;
    }
}

void deapthFirstSearch(int v) {
    push(v);
    visited[v] = 1;

    while (top != -1) {
        int popV = pop();
        printf("%d ", popV); 

        for (int j = 0; j < size; j++) { 
            if (adjascentMatrix[popV][j] == 1 && visited[j] == 0) {
                push(j);
                visited[j] = 1; 
            }
        }
    }
}

int main() {
    int element;
    printf("This is a program for Depth First Search\n");
    printf("Enter the graph : \n");
    read();
    printf("Enter the element to search : ");
    scanf("%d", &element);
    printf("DFS traversal starting from vertex %d: ", element);
    deapthFirstSearch(element);
    printf("\n");
    return 0;
}