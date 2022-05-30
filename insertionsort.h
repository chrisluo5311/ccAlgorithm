//
// Created by chris on 2022/5/1.
//
#include <math.h>
#include <stdio.h>

void insertionSort(int arr[], int n)
{
    for(int i = 1; i < n ; i++){
        int j = i-1;//另一個指針指向前面一項 比對大小
        int current_value = arr[i];

        while(j >=0 && arr[j]>current_value){
            //前面只要大於當前值的都往後移
            arr[j+1] = arr[j];
            j = j-1;//到0後j會變-1 後面使用要+1
        }
        //往後移動後 最前方的位置擺放current_value
        arr[j+1] = current_value;
    }
}


/**
 * 類似整理手上的撲克牌: 小的往前擺、大的往後
 * Time Complexity: O(n^2)
 * Insertion sort is used when number of elements is small.
 * It can also be useful when input array is almost sorted, only few elements are misplaced in complete big array.
 * */
int insertionSortExecute(){
    printf("====Insertion sort starts==== \n");
    int arr[] = { 12, 11, 13, 5, 6 };
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Given array is \n");
    printArray(arr, n);

    insertionSort(arr, n);

    printf("\nSorted array is \n");
    printArray(arr, n);

    return 0;
}