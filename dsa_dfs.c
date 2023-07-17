#include<stdio.h>
#include <stdbool.h>

#define MAX_VERTICES 100


typedef struct {
    int vertices;
    int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES];
} Graph;

void initializeGraph(Graph* graph, int vertices);
void addEdge(Graph* graph, int src, int dest);
void depthFirstSearch(Graph* graph, int startVertex, bool visited[]);

int main()
{
    Graph graph;
    int vertices, src, dest;

    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);
    initializeGraph(&graph, vertices);

    int edges;
    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    printf("Enter the edges (source destination):\n");
    int i;
    for ( i = 0; i < edges; i++) {
        scanf("%d %d", &src, &dest);
        addEdge(&graph, src, dest);
    }

    bool visited[MAX_VERTICES] = { false };

    printf("Depth-First Traversal:\n");
    for ( i = 0; i < graph.vertices; i++) {
        if (!visited[i]) {
            depthFirstSearch(&graph, i, visited);
        }
    }

    return 0;
}


void initializeGraph(Graph* graph, int vertices) {
    graph->vertices = vertices;
    int i,j;
    for (i = 0; i < vertices; i++) {
        for ( j = 0; j < vertices; j++) {
            graph->adjacencyMatrix[i][j] = 0;
        }
    }
}


void addEdge(Graph* graph, int src, int dest) {
    graph->adjacencyMatrix[src][dest] = 1;
}


void depthFirstSearch(Graph* graph, int startVertex, bool visited[]) {
    printf("%d ", startVertex);
    visited[startVertex] = true;
    int i;
    for ( i = 0; i < graph->vertices; i++) {
        if (graph->adjacencyMatrix[startVertex][i] && !visited[i]) {
            depthFirstSearch(graph, i, visited);
        }
    }
}
