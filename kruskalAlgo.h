//
// Created by chris on 2022/5/29.
//

#ifndef CPRACTICE_KRUSKALALGO_H
#define CPRACTICE_KRUSKALALGO_H

#include <stdio.h>

#define MAX 30

typedef struct edge {
    int u, v, weight;
} edge;

typedef struct edge_list {
    edge data[MAX];
    int n;
} edge_list;

edge_list elist;

int Graph[MAX][MAX], n;
edge_list spanlist;

void kruskalAlgo();
int kfind(int belongs[], int vertexno);
void applyUnion(int belongs[], int c1, int c2);
void sortk();
void printk();

// Applying Krushkal Algo
void kruskalAlgo() {
    int belongs[MAX], i, j, cno1, cno2;
    elist.n = 0;

    for (i = 1; i < n; i++){
        for (j = 0; j < i; j++) {
            if (Graph[i][j] != 0) {
                elist.data[elist.n].u = i;
                elist.data[elist.n].v = j;
                elist.data[elist.n].weight = Graph[i][j];
                elist.n++;
            }
        }
    }

    //根據weight來進行排序
    sortk();

    for (i = 0; i < n; i++)
        belongs[i] = i;

    spanlist.n = 0;

    printf("elist n: %d\n",elist.n);

    for (i = 0; i < elist.n; i++) {
        printf("\nelist u: %d ,v: %d ,weight: %d\n",elist.data[i].u,elist.data[i].v,elist.data[i].weight);
        cno1 = kfind(belongs, elist.data[i].u);
        cno2 = kfind(belongs, elist.data[i].v);
        printf("belongs cno1: %d ,con2: %d\n",cno1,cno2);

        if (cno1 != cno2) {
            spanlist.data[spanlist.n] = elist.data[i];
            spanlist.n = spanlist.n + 1;
            applyUnion(belongs, cno1, cno2);
        }
    }
}

int kfind(int belongs[], int vertexno) {
    return (belongs[vertexno]);
}

void applyUnion(int belongs[], int c1, int c2) {
    int i;
    printf("applyUnion  n: %d\n",n);
    printArray(belongs,n);
    for (i = 0; i < n; i++)
        if (belongs[i] == c2)
            belongs[i] = c1;
    printArray(belongs,n);
}

// Sorting algo
void sortk() {
    int i, j;
    edge temp;

    for (i = 1; i < elist.n; i++)
        for (j = 0; j < elist.n - 1; j++)
            if (elist.data[j].weight > elist.data[j + 1].weight) {
                temp = elist.data[j];
                elist.data[j] = elist.data[j + 1];
                elist.data[j + 1] = temp;
            }
}

// Printing the result
void printk() {
    int i, cost = 0;

    for (i = 0; i < spanlist.n; i++) {
        printf("\n%d - %d : %d", spanlist.data[i].u, spanlist.data[i].v, spanlist.data[i].weight);
        cost = cost + spanlist.data[i].weight;
    }

    printf("\nSpanning tree cost: %d", cost);
}

int kruskalExecute() {
    int i, j, total_cost;

    n = 6;

    Graph[0][0] = 0;
    Graph[0][1] = 4;
    Graph[0][2] = 4;
    Graph[0][3] = 0;
    Graph[0][4] = 0;
    Graph[0][5] = 0;

    Graph[1][0] = 4;
    Graph[1][1] = 0;
    Graph[1][2] = 2;
    Graph[1][3] = 0;
    Graph[1][4] = 0;
    Graph[1][5] = 0;

    Graph[2][0] = 4;
    Graph[2][1] = 2;
    Graph[2][2] = 0;
    Graph[2][3] = 3;
    Graph[2][4] = 4;
    Graph[2][5] = 0;

    Graph[3][0] = 0;
    Graph[3][1] = 0;
    Graph[3][2] = 3;
    Graph[3][3] = 0;
    Graph[3][4] = 3;
    Graph[3][5] = 0;

    Graph[4][0] = 0;
    Graph[4][1] = 0;
    Graph[4][2] = 4;
    Graph[4][3] = 3;
    Graph[4][4] = 0;
    Graph[4][5] = 3;

    Graph[5][0] = 0;
    Graph[5][1] = 0;
    Graph[5][2] = 2;
    Graph[5][3] = 0;
    Graph[5][4] = 3;
    Graph[5][5] = 0;

    kruskalAlgo();
    printk();
}


#endif //CPRACTICE_KRUSKALALGO_H
