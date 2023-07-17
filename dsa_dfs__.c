
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Queue implementation
struct Queue {
    int items[MAX_SIZE];
    int front;
    int rear;
};

void initQueue(struct Queue* queue) {
    queue->front = -1;
    queue->rear = -1;
}

int isEmpty(struct Queue* queue) {
    return queue->front == -1;
}

void enqueue(struct Queue* queue, int value) {
    if (queue->rear == MAX_SIZE - 1) {
        printf("Queue is full\n");
        return;
    }
    if (queue->front == -1)
        queue->front = 0;
    queue->items[++queue->rear] = value;
}

int dequeue(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        exit(EXIT_FAILURE);
    }
    int item = queue->items[queue->front];
    if (queue->front == queue->rear)
        queue->front = queue->rear = -1;
    else
        queue->front++;
    return item;
}

// Graph representation using adjacency matrix
struct Graph {
    int adjacencyMatrix[MAX_SIZE][MAX_SIZE];
    int numVertices;
};

struct Graph* createGraph(int numVertices) {
    struct Graph* graph = malloc(sizeof(struct Graph));
    graph->numVertices = numVertices;

    // Initialize adjacency matrix with zeros
    for (int i = 0; i < numVertices; ++i) {
        for (int j = 0; j < numVertices; ++j) {
            graph->adjacencyMatrix[i][j] = 0;
        }
    }

    return graph;
}

void BFS(struct Graph* graph, int startVertex) {
    struct Queue* queue = malloc(sizeof(struct Queue));
    initQueue(queue);

    int numVertices = graph->numVertices;
    int* visited = calloc(numVertices, sizeof(int));

    enqueue(queue, startVertex);
    visited[startVertex] = 1;

    while (!isEmpty(queue)) {
        int currentVertex = dequeue(queue);
        printf("%d ", currentVertex);

        for (int i = 0; i < numVertices; ++i) {
            if (graph->adjacencyMatrix[currentVertex][i] && !visited[i]) {
                enqueue(queue, i);
                visited[i] = 1;
            }
        }
    }

    free(queue);
    free(visited);
}

int main() {
    int numVertices;
    printf("Enter the number of vertices: ");
    scanf("%d", &numVertices);

    struct Graph* graph = createGraph(numVertices);

    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < numVertices; ++i) {
        for (int j = 0; j < numVertices; ++j) {
            scanf("%d", &graph->adjacencyMatrix[i][j]);
        }
    }

    int startVertex;
    printf("Enter the starting vertex: ");
    scanf("%d", &startVertex);

    printf("BFS Traversal: ");
    BFS(graph, startVertex);

    return 0;
}


