//
// Created by chris on 2022/5/30.
//

#ifndef CPRACTICE_SINGLESOURCESHORTESTPATH_H
#define CPRACTICE_SINGLESOURCESHORTESTPATH_H

#include <limits.h>
#include <stdio.h>
#include <stdbool.h>

// Number of vertices in the graph
#define V 11

int minDistance(int dist[], bool sptSet[])
{
    printf("dist array:\n");
    printArray(dist, Vf);
    printf("sptSet:\n");
    printBoolArray(sptSet, Vf);
    // Initialize min value
    int min = INT_MAX, min_index;

    for (int v = 0; v < Vf; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;

    return min_index;
}

void printSolution(int dist[])
{
    printf("Vertex \t\t Distance from Source\n");
    for (int i = 0; i < Vf; i++)
        printf("%d \t\t %d\n", i, dist[i]);
}

void dijkstra(int graph[Vf][Vf], int src)
{
    int dist[Vf]; // The output array.  dist[i] will hold the shortest distance from src to i

    bool sptSet[Vf]; // sptSet[i] will be true if vertex i is included in the shortest path tree or shortest distance from src to i is finalized

    // Initialize all distances as INFINITE and stpSet[] as false
    for (int i = 0; i < Vf; i++)
        dist[i] = INT_MAX, sptSet[i] = false;

    // Distance of source vertex from itself is always 0
    dist[src] = 0;

    for (int count = 0; count < Vf - 1; count++) {
        printf("\n【Before】");
        int u = minDistance(dist, sptSet);
        printf("minimum distance(u): %d\n",u);

        // Mark the picked vertex as processed
        sptSet[u] = true;

        // Update dist value of the adjacent vertices of the picked vertex.
        for (int v = 0; v < Vf; v++){
            printf("dist[u](到該點的原距離): %d,graph[u][v](該點到鄰近點的距離): %d, dist[v]: %d \n",dist[u],graph[u][v],dist[v]);
            // Update dist[v] only if is not in sptSet, there is an edge from
            // u to v, and total weight of path from src to  v through u is
            // smaller than current value of dist[v]
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]){
                dist[v] = dist[u] + graph[u][v];
            }
        }

        printf("【After】");
        printf("dist array:\n");
        printArray(dist, Vf);
        printBoolArray(sptSet, Vf);
    }

    printSolution(dist);
}

int singleSourceShortestPath()
{
    int graph[Vf][Vf] = {{0, 3, 4, 0, 5, 0, 0, 0, 0 , 0, 0},
                         {3, 0, 0, 3, 1, 0, 4, 0, 0 , 0, 0},
                         {4, 0, 0, 0, 4, 5, 0, 0, 0 , 2, 1},
                         {0, 3, 0, 0, 4, 0, 3, 2, 0 , 0, 0},
                         {0, 0, 0, 0, 0, 0, 0, 0, 0 , 0, 0},
                         {0, 0, 0, 0, 0, 0, 0, 0, 0 , 0, 0},
                         {0, 0, 0, 0, 0, 0, 0, 0, 0 , 0, 0},
                         {8, 0, 0, 0, 0, 0, 0, 0, 0 , 0, 0},
                         {0, 0, 0, 0, 0, 0, 0, 0, 0 , 0, 0},
                         {0, 0, 0, 0, 0, 0, 0, 0, 0 , 0, 0},
                         {0, 0, 0, 0, 0, 0, 0, 0, 0,  0, 0}};

    dijkstra(graph, 0);

    return 0;
}


#endif //CPRACTICE_SINGLESOURCESHORTESTPATH_H
