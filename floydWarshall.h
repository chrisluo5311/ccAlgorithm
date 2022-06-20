//
// Created by chris on 2022/6/19.
//

#ifndef CPRACTICE_FLOYDWARSHALL_H
#define CPRACTICE_FLOYDWARSHALL_H

#define Vf 4
#define INF INT_MAX

// A function to print the solution matrix
void printSolutionF(int dist[][Vf]);

void floydWarshall (int graph[][Vf]) {
    int dist[Vf][Vf], i, j, k;

    for (i = 0; i < Vf; i++)
        for (j = 0; j < Vf; j++)
            dist[i][j] = graph[i][j];

    for (k = 0; k < Vf; k++) {//經過哪個點
        for (i = 0; i < Vf; i++) {//起始點
            for (j = 0; j < Vf; j++) {//終點
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }

    // Print the shortest distance matrix
    printSolutionF(dist);
}

/* A utility function to print solution */
void printSolutionF(int dist[][Vf]) {
    printf ("The following matrix shows the shortest distances"
            " between every pair of vertices \n");
    for (int i = 0; i < Vf; i++) {
        for (int j = 0; j < Vf; j++) {
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
    int graph[Vf][Vf] = {{0,   5,   INF, 10},
                         {INF, 0,   3, INF},
                         {INF, INF, 0,   1},
                         {INF, INF, INF, 0}
    };

    // Print the solution
    floydWarshall(graph);
    return 0;
}

#endif //CPRACTICE_FLOYDWARSHALL_H
