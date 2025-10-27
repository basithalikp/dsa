#include <stdio.h>
#include <stdlib.h>

#define MAX_CAPACITY 101
#define MAX_QUEUE_SIZE 10001

typedef struct {
    int x, y;
} State;

int visited[MAX_CAPACITY][MAX_CAPACITY];
State queue[MAX_QUEUE_SIZE];
State parent[MAX_CAPACITY][MAX_CAPACITY];
int front = -1, rear = -1;
int jug1Capacity, jug2Capacity, targetAmount;

void enqueue(State element) {
    if (rear == MAX_QUEUE_SIZE - 1) {
        printf("queue overflow!\n");
        return;
    }
    if (front == -1) {
        front = 0;
    }
    queue[++rear] = element;
}

State dequeue() {
    if (front == -1 || front > rear) {
        printf("Empty queue!\n");
        State empty = {-1, -1};
        return empty;
    }
    State element = queue[front];
    front++;
    return element;
}

void printSolutionPath(State s) {
    if (parent[s.x][s.y].x == -1) {
        printf("(%d, %d)\n", s.x, s.y);
        return;
    }
    printSolutionPath(parent[s.x][s.y]);
    printf("(%d, %d)\n", s.x, s.y);
}

void tryNextState(State currentState, int newX, int newY) {
    if (newX >= 0 && newX <= jug1Capacity && newY >= 0 && newY <= jug2Capacity && !visited[newX][newY]) {
        State nextState = {newX, newY};
        visited[newX][newY] = 1;
        parent[newX][newY] = currentState;
        enqueue(nextState);
    }
}

void breadthFirstSearch() {
    for (int i = 0; i <= jug1Capacity; i++) {
        for (int j = 0; j <= jug2Capacity; j++) {
            visited[i][j] = 0;
        }
    }

    State startState = {0, 0};
    enqueue(startState);
    visited[0][0] = 1;
    parent[0][0] = (State){-1, -1};

    while (front != -1 && front <= rear) {
        State currentState = dequeue();

        if (currentState.x == targetAmount || currentState.y == targetAmount) {
            printf("\nSolution found! The steps are:\n");
            printSolutionPath(currentState);
            return;
        }

        tryNextState(currentState, jug1Capacity, currentState.y);
        tryNextState(currentState, currentState.x, jug2Capacity);
        tryNextState(currentState, 0, currentState.y);
        tryNextState(currentState, currentState.x, 0);

        int pour1to2 = (currentState.x < jug2Capacity - currentState.y) ? currentState.x : (jug2Capacity - currentState.y);
        tryNextState(currentState, currentState.x - pour1to2, currentState.y + pour1to2);

        int pour2to1 = (currentState.y < jug1Capacity - currentState.x) ? currentState.y : (jug1Capacity - currentState.x);
        tryNextState(currentState, currentState.x + pour2to1, currentState.y - pour2to1);
    }

    printf("\nNo solution found.\n");
}

int main() {
    printf("This is a program for the Water Pouring Problem\n");
    printf("Enter the capacity of jug 1: ");
    scanf("%d", &jug1Capacity);
    printf("Enter the capacity of jug 2: ");
    scanf("%d", &jug2Capacity);
    printf("Enter the target amount: ");
    scanf("%d", &targetAmount);

    if (targetAmount > jug1Capacity && targetAmount > jug2Capacity) {
        printf("\nTarget is larger than both jug capacities. No solution possible.\n");
        return 0;
    }

    breadthFirstSearch();
    return 0;
}