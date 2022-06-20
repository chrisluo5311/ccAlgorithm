//
// Created by chris on 2022/6/19.
//

#ifndef CPRACTICE_MULTISTAGEGRAPHSHORTESTPATH_H
#define CPRACTICE_MULTISTAGEGRAPHSHORTESTPATH_H

#define G 8
#define X 7
#define N 8
int maxNum = INT_MAX;

int shortestDist(int graph[X][G]){
    int dist[N];
    dist[N-1] = 0;

    for(int i = N-2 ; i >= 0 ; i--){
        dist[i] = INT_MAX;
        for(int j = i ; j < N ;j++){
            if(graph[i][j] == maxNum){
                continue;
            }
            dist[i] = (dist[i] < (graph[i][j]+dist[j])) ? dist[i] : graph[i][j]+dist[j];
        }
    }
    return dist[0];
}

int multistageGraphExecute(){
    int graph[X][G] = { {maxNum, 1,      2,      5,      maxNum , maxNum, maxNum, maxNum},
                        {maxNum, maxNum, maxNum, maxNum, 4 ,      11,     maxNum, maxNum},
                        {maxNum, maxNum, maxNum, maxNum, 9,       15,     16 ,    maxNum},
                        {maxNum, maxNum, maxNum, maxNum, maxNum,  maxNum, 2,      maxNum},
                        {maxNum, maxNum, maxNum, maxNum, maxNum,  maxNum, maxNum, 18},
                        {maxNum, maxNum, maxNum, maxNum, maxNum,  maxNum, maxNum, 13},
                        {maxNum, maxNum, maxNum, maxNum, maxNum,  maxNum, maxNum, 2}};


    int dist = shortestDist(graph);
    printf("最短距離為%d",dist);
    return 0;
}

#endif //CPRACTICE_MULTISTAGEGRAPHSHORTESTPATH_H
