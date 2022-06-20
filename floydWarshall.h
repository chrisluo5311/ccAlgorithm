//
// Created by chris on 2022/6/19.
//

#ifndef CPRACTICE_FLOYDWARSHALL_H
#define CPRACTICE_FLOYDWARSHALL_H

#define size 4
#define INF 99999

// A function to print the solution matrix
void printSolutionF(int dist[][size]);

void floydWarshall (int graph[][size]) {
    int dist[size][size], i, j, k;

    for (i = 0; i < size; i++)
        for (j = 0; j < size; j++)
            dist[i][j] = graph[i][j];

    for (k = 0; k < size; k++) {//經過哪個點
        for (i = 0; i < size; i++) {//起始點
            for (j = 0; j < size; j++) {//終點
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }

    // Print the shortest distance matrix
    printSolutionF(dist);
}

/* A utility function to print solution */
void printSolutionF(int dist[][size]) {
    printf ("The following matrix shows the shortest distances"
            " between every pair of vertices \n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (dist[i][j] == INF)
                printf("%7s", "INF");
            else
                printf ("%7d", dist[i][j]);
        }
        printf("\n");
    }
}

// driver program to test above function
int floydWarshallExecute()
{
    /* Let us create the following weighted graph
            10
       (0)------->(3)
        |         /|\
      5 |          |
        |          | 1
       \|/         |
       (1)------->(2)
            3           */
    int graph[size][size] = {{0,   5,   INF, 10},
                         {INF, 0,   3, INF},
                         {INF, INF, 0,   1},
                         {INF, INF, INF, 0}
    };

    // Print the solution
    floydWarshall(graph);
    return 0;
}

#endif //CPRACTICE_FLOYDWARSHALL_H
