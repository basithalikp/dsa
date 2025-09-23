#include <stdio.h>
#define MAX_SIZE 20

int visited[MAX_SIZE], adjascentMatrix[MAX_SIZE][MAX_SIZE], front = -1, rear = -1, queue[MAX_SIZE], size;

void enqueue(int element) {
    if (rear == MAX_SIZE - 1) {
        printf("queue overflow!\n");
        return;
    }
    if (front == -1) {
        front = 0;
    }
    queue[++rear] = element;
}

int dequeue() {
    if (front == -1 || front > rear) {
        printf("Empty queue!\n");
        return -1;
    }
    int element = queue[front];
    front++;
    return element;
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

void breadthFirstSearch(int v) {
    visited[v] = 1;
    enqueue(v);
    while (front != -1 && front <= rear) {
        v = dequeue();
        printf("%d ", v);
        for (int j = 0; j < size; j++) {
            if (adjascentMatrix[v][j] == 1 && visited[j] == 0) {
                visited[j] = 1;
                enqueue(j);
            }
        }
    }
}

int main() {
    int element;
    printf("This is a program for Breadth First Search\n");
    printf("Enter the graph : \n");
    read();
    printf("Enter the element to search : ");
    scanf("%d", &element);
    printf("BFS traversal starting from vertex %d: ", element);
    breadthFirstSearch(element);
    printf("\n");
    return 0;
}