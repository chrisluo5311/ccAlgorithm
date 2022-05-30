//
// Created by chris on 2022/4/30.
//
#include <stdio.h>
struct pair {
    int min;
    int max;
};

//Time Complexity: O(n) (Simple Linear Search)
struct pair getMinMax(int arr[], int n)
{
    struct pair minmax;
    int i;
    //1個元素
    if (n == 1) {
        minmax.max = arr[0];
        minmax.min = arr[0];
        return minmax;
    }
    //兩個(含)以上 初始化最大值最小值
    if (arr[0] > arr[1]){
        minmax.max = arr[0];
        minmax.min = arr[1];
    } else {
        minmax.max = arr[1];
        minmax.min = arr[0];
    }
    //兩個以上
    for (i = 2; i<n; i++) {
        if (arr[i] >  minmax.max)
            minmax.max = arr[i];
        else if (arr[i] <  minmax.min)
            minmax.min = arr[i];
    }
    return minmax;
}

//Time Complexity: O(n)
struct pair getMinMaxWithRecursive(int arr[], int low, int high) {
    struct pair minmax, mmLeft, mmRight;
    int mid;

    // 1元素
    if (low == high) {
        minmax.max = arr[low];
        minmax.min = arr[low];
        return minmax;
    }

    //2元素
    if (high == low + 1) {
        if (arr[low] > arr[high]) {
            minmax.max = arr[low];
            minmax.min = arr[high];
        } else {
            minmax.max = arr[high];
            minmax.min = arr[low];
        }
        return minmax;
    }

    /* If there are more than 2 elements */
    mid = (low + high)/2;
    mmLeft = getMinMaxWithRecursive(arr, low, mid);
    mmRight = getMinMaxWithRecursive(arr, mid + 1, high);

    /* compare minimums of two parts*/
    if (mmLeft.min < mmRight.min)
        minmax.min = mmLeft.min;
    else
        minmax.min = mmRight.min;

    /* compare maximums of two parts*/
    if (mmLeft.max > mmRight.max)
        minmax.max = mmLeft.max;
    else
        minmax.max = mmRight.max;

    return minmax;
}

int maxMinExecute(){
    printf("====Max Min algo starts====\n");
//    int arr[] = {0,1,2,3,4,5,6,7,8};
    int arr[] = {1000, 11, 445, 1, 330, 3000};
    int n = sizeof(arr)/sizeof(*arr);
//    struct pair maxMin = getMinMax(arr, n);
    struct pair maxMin = getMinMaxWithRecursive(arr,0,n-1);
    printf("arr Max:%d\n",maxMin.max);
    printf("arr Min:%d\n",maxMin.min);
    printf("===Max Min algo ends===\n");
    return 0;
}
