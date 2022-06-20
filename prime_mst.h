//
// Created by chris on 2022/5/24.
//

#ifndef CPRACTICE_PRIME_MST_H
#define CPRACTICE_PRIME_MST_H

#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
// 圖中有幾個vertex
#define Vf 6

struct sequencePair{
    int parent;
    int child;
};

// 找到最小且未納入mst中的key
// 回傳該最小key的位址index
int minKey(int key[], bool mstSet[]){
    int min = INT_MAX, min_index;

    for (int v = 0; v < Vf; v++)
        if (mstSet[v] == false && key[v] < min)
            min = key[v], min_index = v;

    return min_index;
}

void primMST(int graph[Vf][Vf]){
    // 放父vertex的陣列
    int parent[Vf];
    // 放最小weight的值
    int key[Vf];
    // 設置已包含在mst中的布林值
    bool mstSet[Vf];
    //紀錄圖形連結順序
    struct sequencePair sequencePair[Vf];

    // 初始化所有key值為最大數 所有mst為false表示都尚未列入mst中
    for (int i = 0; i < Vf; i++)
        key[i] = INT_MAX, mstSet[i] = false;

    key[0] = 0;
    parent[0] = -1; // First node is always root of MST
    struct sequencePair sp;

    for (int count = 0; count < Vf ; count++) {
        // 找最小的key
        int u = minKey(key, mstSet);

        // 最小key被選中 標示為true 未來不再選它
        mstSet[u] = true;
        //放進連結順序
        sp.parent = parent[u];
        sp.child  = u;
        sequencePair[count] = sp;

        // 找下個被連結的vertex中所有edge的權重，記錄在key值與parent值
        for (int v = 0; v < Vf; v++)

            // graph[u][v] is non-zero only for adjacent vertices of m
            // mstSet[v] is false for vertices not yet included in MST
            // Update the key only if graph[u][v] is smaller than key[v]
            if (graph[u][v] != 0 && mstSet[v] == false && graph[u][v] < key[v])
                parent[v] = u, key[v] = graph[u][v];
    }

    //按照連結順序印出MST
    printf("Edge \tWeight\n");
    for(int i = 0 ; i < Vf ; i++){
        if(i>0){
            printf("%d - %d \t%d \n",sequencePair[i].parent,sequencePair[i].child,key[sequencePair[i].child]);
        }
    }
}

int primeMstExecute(){
    int graph[Vf][Vf] = {{0, 2, 0, 6,  0 , 0},
                         {2, 0, 3, 8,  5 , 0},
                         {0, 3, 0, 0,  7 , 0},
                         {6, 8, 0, 0,  9 , 10},
                         {0, 5, 7, 9,  0 , 0},
                         {0, 0, 0, 10, 0 , 0}};

    primMST(graph);

    return 0;
}


#endif //CPRACTICE_PRIME_MST_H
