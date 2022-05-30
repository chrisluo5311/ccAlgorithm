//
// Created by chris on 2022/5/23.
//
#include <stdio.h>

void printMaxActivities(int s[], int f[], int n){
    int i, j;

    printf(" Following activities are selected: \n");

    // 第一項永遠都選取
    i = 0;
    printf(" [s位置,s值]: [%d,%d] ", i,s[i]);

    // Consider rest of the activities
    for (j = 1; j < n; j++) {
        // 該次起點大於或等於前面的終點則選取(即印出)
        if (s[j] >= f[i]) {
            printf ("[%d,%d] ", j,s[j]);
            i = j;
        }
    }
}

int activitySelectionExecute(){
    int start[] =  {1, 3, 0, 5, 8, 5};
    int finish[] =  {2, 4, 6, 7, 9, 9};
    int unsorted_finish[] = {7,9,6,9,2,4};
    int n = sizeof(start)/sizeof(start[0]);
    printf("1.未排序的 ActivitySelection: \n");
    selectionSort(unsorted_finish,n);
    printMaxActivities(start, unsorted_finish, n);

    printf("\n2.已排序的 ActivitySelection: \n");
    printMaxActivities(start, finish, n);
    return 0;
}