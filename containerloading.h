//
// Created by chris on 2022/5/29.
//

#ifndef CPRACTICE_CONTAINERLOADING_H
#define CPRACTICE_CONTAINERLOADING_H

void selectionSortByWeight(int arr[],int n){
    int i, j, max_idx;
    for (i = 0; i < n-1; i++){
        max_idx = i;
        for (j = i+1; j < n; j++){
            if (arr[j] > arr[max_idx])
                max_idx = j;
        }
        swap(&arr[max_idx], &arr[i]);
    }
}

int containerGreedyAlgo(int containerWeight[], int size, int capacity, int numberOfContainer){
    //sort by weight
    selectionSortByWeight(containerWeight, size);
    //print after sorting array: 200 150 100 90 80 50 50 20
    printArray(containerWeight,size);

    //initialize an empty flag represents container being put
    int flag[numberOfContainer];
    for(int i = 0; i<numberOfContainer;i++){
        flag[i] = 0;
    }

    //put container
    for(int j = 0 ; j < numberOfContainer ; j++){
        if(containerWeight[j] <= capacity){
            flag[j] = 1;
            capacity -= containerWeight[j];
        }
    }

    //print the chosen containers
    for(int l = 0; l < numberOfContainer ; l++){
        if(flag[l] == 1){
            printf("第%d號集裝箱有被裝載\t",l+1);
            printf("重量為%d\n",containerWeight[l]);
        }
    }

}

int containerLoadingExecute(){
    int capacity = 400;
    //numbers of container
    int num = 8;
    int containerWeight[] = {100,200,50,150,90,50,20,80};
    int n = sizeof(containerWeight) / sizeof(containerWeight[0]);
    containerGreedyAlgo(containerWeight,n,capacity,num);
    return 0;
}

#endif //CPRACTICE_CONTAINERLOADING_H
