//
// Created by chris on 2022/5/1.
//
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void printArray(int A[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}

void printBoolArray(bool A[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%s ", A[i]?"true":"false");
    printf("\n");
}

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}