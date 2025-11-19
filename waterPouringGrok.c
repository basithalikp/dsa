#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CAP_A 10
#define CAP_B 7
#define CAP_C 4

// Structure to represent a state
typedef struct {
    int a, b, c; // Water in containers A, B, C
} State;

// Structure for queue node
typedef struct {
    State state;
    char path[1000]; // To store the sequence of operations
} QueueNode;

// Queue implementation
typedef struct {
    QueueNode* nodes;
    int front, rear, size;
} Queue;

// Initialize queue
Queue* createQueue(int size) {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->nodes = (QueueNode*)malloc(size * sizeof(QueueNode));
    q->front = 0;
    q->rear = -1;
    q->size = size;
    return q;
}

void enqueue(Queue* q, State state, const char* path) {
    if (q->rear < q->size - 1) {
        q->rear++;
        q->nodes[q->rear].state = state;
        strcpy(q->nodes[q->rear].path, path);
    }
}

QueueNode dequeue(Queue* q) {
    return q->nodes[q->front++];
}

int isEmpty(Queue* q) {
    return q->front > q->rear;
}

// Check if state is valid and not visited
int isValidAndNew(State s, int visited[CAP_A + 1][CAP_B + 1][CAP_C + 1]) {
    if (s.a >= 0 && s.a <= CAP_A && s.b >= 0 && s.b <= CAP_B && s.c >= 0 && s.c <= CAP_C) {
        return !visited[s.a][s.b][s.c];
    }
    return 0;
}

// Check if goal is reached
int isGoal(State s) {
    return s.b == 2 || s.c == 2;
}

// Simulate pouring from one container to another
void pour(int from, int to, int cap_to, int* amt_from, int* amt_to, char* operation) {
    int poured = (*amt_from < (cap_to - *amt_to)) ? *amt_from : (cap_to - *amt_to);
    *amt_from -= poured;
    *amt_to += poured;
    sprintf(operation, "Pour %d liters from %c to %c\n", poured,
            from == 0 ? 'A' : from == 1 ? 'B' : 'C',
            to == 0 ? 'A' : to == 1 ? 'B' : 'C');
}

int main() {
    // Initialize visited array
    int visited[CAP_A + 1][CAP_B + 1][CAP_C + 1] = {0};
    Queue* q = createQueue(10000); // Arbitrary large size

    // Initial state
    State initial = {0, 7, 4};
    visited[0][7][4] = 1;
    enqueue(q, initial, "");

    while (!isEmpty(q)) {
        QueueNode current = dequeue(q);
        State s = current.state;

        // Check if goal is reached
        if (isGoal(s)) {
            printf("Goal reached: A=%d, B=%d, C=%d\n", s.a, s.b, s.c);
            printf("Sequence of operations:\n%s", current.path);
            free(q->nodes);
            free(q);
            return 0;
        }

        // Try all possible pourings
        State next;
        char new_path[1000];
        char operation[100];

        // Pour A to B
        next = s;
        pour(0, 1, CAP_B, &next.a, &next.b, operation);
        if (isValidAndNew(next, visited)) {
            visited[next.a][next.b][next.c] = 1;
            strcpy(new_path, current.path);
            strcat(new_path, operation);
            enqueue(q, next, new_path);
        }

        // Pour A to C
        next = s;
        pour(0, 2, CAP_C, &next.a, &next.c, operation);
        if (isValidAndNew(next, visited)) {
            visited[next.a][next.b][next.c] = 1;
            strcpy(new_path, current.path);
            strcat(new_path, operation);
            enqueue(q, next, new_path);
        }

        // Pour B to A
        next = s;
        pour(1, 0, CAP_A, &next.b, &next.a, operation);
        if (isValidAndNew(next, visited)) {
            visited[next.a][next.b][next.c] = 1;
            strcpy(new_path, current.path);
            strcat(new_path, operation);
            enqueue(q, next, new_path);
        }

        // Pour B to C
        next = s;
        pour(1, 2, CAP_C, &next.b, &next.c, operation);
        if (isValidAndNew(next, visited)) {
            visited[next.a][next.b][next.c] = 1;
            strcpy(new_path, current.path);
            strcat(new_path, operation);
            enqueue(q, next, new_path);
        }

        // Pour C to A
        next = s;
        pour(2, 0, CAP_A, &next.c, &next.a, operation);
        if (isValidAndNew(next, visited)) {
            visited[next.a][next.b][next.c] = 1;
            strcpy(new_path, current.path);
            strcat(new_path, operation);
            enqueue(q, next, new_path);
        }

        // Pour C to B
        next = s;
        pour(2, 1, CAP_B, &next.c, &next.b, operation);
        if (isValidAndNew(next, visited)) {
            visited[next.a][next.b][next.c] = 1;
            strcpy(new_path, current.path);
            strcat(new_path, operation);
            enqueue(q, next, new_path);
        }
    }

    printf("No solution found.\n");
    free(q->nodes);
    free(q);
    return 0;
}