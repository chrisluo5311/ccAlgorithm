//
// Created by chris on 2022/5/1.
//
int partition(int array[], int low, int high) {

    //rightest_pivot element to be pivot
    int rightest_pivot = array[high];

    int leftIndex = low;

    for(int j = low ; j < high ; j++){
        if(array[j] <= rightest_pivot){
            //因為小於pivot的值要往左邊擺 要跟第一個換
            swap(&array[j],&array[leftIndex]);
            leftIndex++;
        }
    }
    swap(&array[high],&array[leftIndex]);
    return leftIndex;
}

void quickSort(int array[], int low, int high) {
    if (low < high) {
        int pi = partition(array, low, high);
        quickSort(array, low, pi - 1);
        quickSort(array, pi + 1, high);
    }
}

void quick_r(int arr[],int low,int high){
    int pi = rand()%(high - low) + low;
    printf("Random pivot number:%d\n",pi);
    swap(&arr[pi],&arr[high]);
}
/**
 * Using random pivoting we improve the expected or average time complexity to O (N log N).
 * The Worst-Case complexity is still O ( N^2 ).
 * */
void quickSortWithRandomPivot(int array[], int low, int high) {
    if (low < high) {
        int pi;
        if(high - low > 5)
            quick_r(array, low, high);
        printf("After random array:\n");
        printArray(array,high+1);
        pi = partition(array, low, high);
        quickSort(array, low, pi - 1);
        quickSort(array, pi + 1, high);
    }
}


void quickSortIterative(int arr[], int l, int h)
{
    // Create an auxiliary stack
    int stack[h - l + 1];

    // initialize top of stack
    int top = -1;

    // push initial values of l and h to stack
    stack[++top] = l;
    stack[++top] = h;

    // Keep popping from stack while is not empty
    while (top >= 0) {
        // Pop h and l
        h = stack[top--];
        l = stack[top--];

        // Set pivot element at its correct position
        // in sorted array
        int pivot = partition(arr, l, h);

        // If there are elements on left side of pivot,
        // then push left side to stack
        if (pivot - 1 > l) {
            stack[++top] = l;
            stack[++top] = pivot - 1;
        }

        // If there are elements on right side of pivot,
        // then push right side to stack
        if (pivot + 1 < h) {
            stack[++top] = pivot + 1;
            stack[++top] = h;
        }
    }
}

int quickSortExecute() {
    printf("=====QuickSort Started====\n");
    int data[] = {8, 7, 2, 1, 0, 9, 6};

    int n = sizeof(data) / sizeof(data[0]);

    printf("Unsorted Array\n");
    printArray(data, n);

    // perform quicksort on data
//    quickSort(data, 0, n - 1);
//    quickSortIterative(data, 0, n - 1);
    quickSortWithRandomPivot(data,0,n-1);

    printf("Sorted array in ascending order: \n");
    printArray(data, n);
}