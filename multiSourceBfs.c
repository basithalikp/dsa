#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

typedef struct {
    int row;
    int col;
} Point;

typedef struct QueueNode {
    Point point;
    struct QueueNode* next;
} QueueNode;

typedef struct {
    QueueNode *front, *rear;
} Queue;

Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    if (!q) return NULL;
    q->front = q->rear = NULL;
    return q;
}

void enqueue(Queue* q, Point point) {
    QueueNode* temp = (QueueNode*)malloc(sizeof(QueueNode));
    if (!temp) return;
    temp->point = point;
    temp->next = NULL;
    if (q->rear == NULL) {
        q->front = q->rear = temp;
        return;
    }
    q->rear->next = temp;
    q->rear = temp;
}

Point dequeue(Queue* q) {
    if (q->front == NULL) {
        Point p = {-1, -1};
        return p;
    }
    QueueNode* temp = q->front;
    Point p = temp->point;
    q->front = q->front->next;
    if (q->front == NULL) {
        q->rear = NULL;
    }
    free(temp);
    return p;
}

bool isEmpty(Queue* q) {
    return (q->front == NULL);
}

int** findShortestDistanceToMine(char** maze, int rows, int cols) {
    int** distances = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        distances[i] = (int*)malloc(cols * sizeof(int));
    }

    Queue* queue = createQueue();

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (maze[i][j] == 'M') {
                distances[i][j] = 0;
                Point p = {i, j};
                enqueue(queue, p);
            } else {
                distances[i][j] = INT_MAX;
            }
        }
    }

    int directions[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    while (!isEmpty(queue)) {
        Point current = dequeue(queue);

        for (int i = 0; i < 4; i++) {
            int newRow = current.row + directions[i][0];
            int newCol = current.col + directions[i][1];

            if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols &&
                maze[newRow][newCol] != 'X' &&
                distances[newRow][newCol] > distances[current.row][current.col] + 1)
            {
                distances[newRow][newCol] = distances[current.row][current.col] + 1;
                Point nextPoint = {newRow, newCol};
                enqueue(queue, nextPoint);
            }
        }
    }

    free(queue);
    return distances;
}

char** readMaze(int* rows, int* cols) {
    printf("Enter the number of rows: ");
    scanf("%d", rows);
    printf("Enter the number of columns: ");
    scanf("%d", cols);

    char** maze = (char**)malloc(*rows * sizeof(char*));
    for (int i = 0; i < *rows; i++) {
        maze[i] = (char*)malloc(*cols * sizeof(char));
    }

    printf("Enter the maze layout (M=Mine, X=Wall, O=Open), row by row:\n");
    for (int i = 0; i < *rows; i++) {
        for (int j = 0; j < *cols; j++) {
            scanf(" %c", &maze[i][j]);
        }
    }
    return maze;
}

int main() {
    int rows, cols;
    char** maze;

    printf("This is a program to find the shortest distance to a mine in a maze.\n");
    maze = readMaze(&rows, &cols);
    
    printf("\nInput Maze:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%c  ", maze[i][j]);
        }
        printf("\n");
    }

    int** resultDistances = findShortestDistanceToMine(maze, rows, cols);

    printf("\nShortest distance from each cell to the nearest mine:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (maze[i][j] == 'X') {
                printf("X  ");
            } else if (resultDistances[i][j] == INT_MAX) {
                printf("-  ");
            } else {
                printf("%-2d ", resultDistances[i][j]);
            }
        }
        printf("\n");
    }

    for (int i = 0; i < rows; i++) {
        free(maze[i]);
        free(resultDistances[i]);
    }
    free(maze);
    free(resultDistances);

    return 0;
}

