//
// Created by chris on 2022/5/23.
//

#ifndef CPRACTICE_JOBSEQUENCE_DISJOINTSET_H
#define CPRACTICE_JOBSEQUENCE_DISJOINTSET_H


int find(int dSet[],int s){
    if(s == dSet[s])
        return s;
    return find(dSet,dSet[s]);
}

int dsMerge(int dSet[],int u,int v){
    dSet[v] = u;
}


int findMaxDeadline(Job arr[], int n) {
    int ans = INT_MIN;
    for (int i = 0; i < n; i++)
        if(ans > arr[i].dead){
            ans = ans;
        } else {
            ans = arr[i].dead;
        }
    return ans;
}

int printJobScheduling_ds(Job arr[],int n) {
    qsort(arr, n, sizeof(Job), compare);

    char result[n];
    int total = 0;
    int maxDeadline = findMaxDeadline(arr, n);
    //create disjoint set
    int parent[maxDeadline+1];
    for (int i = 0; i <= maxDeadline; i++)
        parent[i] = i;

    //loop arr
    for(int i = 0; i < n;i++){
        int availableSlot = find(parent, arr[i].dead);

        if(availableSlot > 0){
            dsMerge(parent, find(parent, availableSlot - 1), availableSlot);
            result[i] = arr[i].id;
            total += arr[i].profit;
        } else {
            result[i] = ' ';
        }
    }
    for (int i = 0; i < n; i++)
        if (result[i]!= ' ')
            printf("%c ", result[i]);
    return total;
}

int jsDisjointSetExecute() {
    Job arr[] = { { 'a', 2, 100 },
                  { 'b', 1, 19 },
                  { 'c', 2, 27 },
                  { 'd', 1, 25 },
                  { 'e', 3, 15 } };
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Following is maximum profit sequence of jobs \n");
    int totalProfit = printJobScheduling_ds(arr,n);
    printf("\n%d",totalProfit);
    return 0;
}

#endif //CPRACTICE_JOBSEQUENCE_DISJOINTSET_H
