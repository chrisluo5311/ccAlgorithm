//
// Created by chris on 2022/4/30.
//
#include <stdio.h>
#include <stdlib.h>

void merge(int arr[], int l, int m, int r){
    int leftSize  = m - l + 1;
    int rightSize = r - m;

    int left_temp_arr[leftSize];
    int right_temp_arr[rightSize];

    //拆開陣列複製到temp
    for(int i=0;i<leftSize;i++)
        left_temp_arr[i] = arr[i+l];
    for(int j=0;j<rightSize;j++)
        right_temp_arr[j] = arr[m+1+j];

    //左右兩邊陣列開始比大小 但指針不超過各陣列長度
    int leftIndex = 0;
    int rightIndex = 0;
    int originalIndex = l;//原陣列起始指針 為了重構原陣列用
    while(leftIndex < leftSize && rightIndex < rightSize){
        if(left_temp_arr[leftIndex] <= right_temp_arr[rightIndex]){
            arr[originalIndex] = left_temp_arr[leftIndex];
            leftIndex++;
        } else{
            arr[originalIndex] = right_temp_arr[rightIndex];
            rightIndex++;
        }
        originalIndex++;
    }

    //處理一邊加完 一邊還有剩餘的情況
    while(leftIndex < leftSize){
        arr[originalIndex] = left_temp_arr[leftIndex];
        leftIndex++;
        originalIndex++;
    }
    while(rightIndex < rightSize){
        arr[originalIndex] = right_temp_arr[rightIndex];
        rightIndex++;
        originalIndex++;
    }
}

void mergeSort(int arr[], int l, int r){
    if(l<r){
        int middle = l + (r-l)/2;
        mergeSort(arr,l,middle);
        mergeSort(arr,middle+1,r);
        merge(arr,l,middle,r);
    }
}


/**
 * Time Complexity: Sorting arrays on different machines.
 * Merge Sort is a recursive algorithm and time complexity can be expressed as following recurrence relation.
 * T(n) = 2T(n/2) + θ(n)
 * Time complexity of Merge Sort is  θ(nLogn) in all 3 cases (worst, average and best)
 * as merge sort always divides the array into two halves and takes linear time to merge two halves.
 * */
int mergeSortExecute()
{
    printf("====Merge Sort starts==== \n");
    int arr[] = { 12, 11, 13, 5, 6, 7 };
//    int arr[] = { 3,1,5,2,4 };
//    int arr[] = { 3,2,1};
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    printf("Given array is \n");
    printArray(arr, arr_size);

    mergeSort(arr, 0, arr_size - 1);

    printf("\nSorted array is \n");
    printArray(arr, arr_size);
    return 0;
}
