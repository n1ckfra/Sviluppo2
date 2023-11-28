#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>
#include <stdbool.h>

#define MAXL 100 //max length of a line of the input file
#define MAXN 5000

// Function to find the vertex with minimum distance value, from the set of vertices not yet included in shortest path tree
int minDistance(int dist[], int visited[], int N) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < N; v++)
        if (visited[v] == 0 && dist[v] <= min)
            min = dist[v], min_index = v;

    return min_index;
}

// Dijkstra's algorithm for a graph represented using adjacency matrix
int dijkstra(int **graph, int src, int dest, int N) {
    int dist[N];  // The output array. dist[i] will hold the shortest distance from src to i
    int visited[N]; // visited[i] will be true if vertex i is included in shortest path tree or shortest distance from src to i is finalized

    // Initialize all distances as INFINITE and visited[] as false
    for (int i = 0; i < N; i++)
        dist[i] = INT_MAX, visited[i] = 0;

    // Distance of source vertex from itself is always 0
    dist[src] = 0;

    // Find shortest path for all vertices
    for (int count = 0; count < N - 1; count++) {
        int u = minDistance(dist, visited, N);

        // Mark the picked vertex as processed
        visited[u] = 1;

        // Update dist value of the adjacent vertices of the picked vertex.
        for (int v = 0; v < N; v++)
            if (!visited[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }

    return dist[dest];
}

int main() {

    //Graph data
    int N, A;           //Number of nodes N, number of arcs A
    int** matrix;       //Adjacent Matrix with arc information
    int i, j, cost;     //Temporary variables to store an arc: from (i), to (j), cost of the arc
    int source, destination;

    //Read the Graph from input file
    FILE *file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("Error: could not read input file.\n");
        return 0;
    }

    char line[MAXL];                            //Line of the txt file
    char command;
    while (fgets(line, sizeof(line), file) != NULL) {
        command = line[0];                      //Command of the txt file: 'c' = comment, 'p' = problem, 'a' = arc
        switch (command) {
            case 'p':
                //Read problem data: number of nodes and number of arcs full of 0
                sscanf(line, "p sp %d %d %d %d", &N, &A, &source, &destination);
                //Initialize matrix N*N
                matrix = (int**)malloc(N * sizeof(int*));
                for (int r = 0; r < N; r++)
                    matrix[r] = calloc(N, sizeof(int));
                break;
            case 'a':
                //Read arc data: from (i), to (j), cost of the arc
                sscanf(line, "a %d %d %d", &i, &j, &cost);
                //Decrease i-j so that the range is from 0 to N-1
                i--;
                j--;
                matrix[i][j] = cost;
                break;
            default:
                break;
        }
    }

    clock_t start = clock();

    //Perform dijkstra algorithm
    int route_cost = dijkstra(matrix, source, destination, N);

    clock_t end = clock();
    double time = (end-start)/(double)CLOCKS_PER_SEC ;
    printf("The shortest path from %d to %d costs %d.\nTime: %.4f\n", source, destination, route_cost, time);

    //Free matrix memory
    for (int r = 0; r < N; r++)
        free(matrix[r]);
    free(matrix);
}
