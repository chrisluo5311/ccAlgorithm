//
// Created by chris on 2022/5/30.
//

#ifndef CPRACTICE_OPTIMALSTORAGEONTAPE_H
#define CPRACTICE_OPTIMALSTORAGEONTAPE_H

int storageCompare(const void* a, const void* b){
    return ( *(int*)a - *(int*)b );
}

double optimalStorageOnTape(int arr[],int n){
    qsort(arr,n,sizeof(int),storageCompare);

    printf("storage 排序:\n");
    for(int i=0; i<n;i++){
        printf("%d ",arr[i]);
    }

    double mrt = 0;
    for(int j=0;j<n;j++){
        int sum = 0;
        for(int k = 0; k<=j;k++){
            sum += arr[k];
        }
        mrt += sum;
    }
    mrt /= n;
    printf("\nMean Retrieval Time: %f\n",mrt);
    return mrt;
}

int storageExecute(){
    int arr[] = {12,5,8,32,7,5,18,26,4,3,11,10,6};
    int n = sizeof(arr) / sizeof(arr[0]);
    optimalStorageOnTape(arr,n);
    return 0;
}


#endif //CPRACTICE_OPTIMALSTORAGEONTAPE_H
