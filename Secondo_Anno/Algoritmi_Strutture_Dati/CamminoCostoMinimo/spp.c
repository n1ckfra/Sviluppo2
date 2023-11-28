#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>
#include <stdbool.h>

#define MAXL 10000 //max length of a line of the input file
#define MAXN 10000

int findNextNode(int dist[], bool visited[], int n) {
    int min = INT_MAX, min_index = -1;

    for (int v = 0; v < n; v++)
        if (!visited[v] && dist[v] <= min)
            min = dist[v], min_index = v;

    return min_index;
}

int dijkstra(int **matrix, int source, int destination, int N) {
    int dist[N];
    bool visited[N];

    for (int i = 0; i < N; i++)
        dist[i] = INT_MAX, visited[i] = false;

    dist[source] = 0;

    for (int count = 0; count < N - 1; count++) {
        int u = findNextNode(dist, visited, N);

        if (u == -1 || u == destination)
            break;

        visited[u] = true;

        for (int v = 0; v < N; v++)
            if (!visited[v] && matrix[u][v] && dist[u] != INT_MAX && dist[u] + matrix[u][v] < dist[v])
                dist[v] = dist[u] + matrix[u][v];
    }

    return dist[destination];
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
