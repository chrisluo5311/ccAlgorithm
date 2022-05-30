//
// Created by chris on 2022/4/30.
//
int binarySearch1(int arr[], int l, int r, int x)
{
    if (r >= l) {
        int mid = l + (r - l) / 2;
        if (arr[mid] == x)
            return mid;
        if (arr[mid] > x)
            return binarySearch1(arr, l, mid - 1, x);
        return binarySearch1(arr, mid + 1, r, x);
    }
    return -1;
}

int binarySearch2(int arr[],int l,int r,int target){

    if(l<=r){
        int middle =  l + (r - l) / 2;
        if(arr[middle]==target)
            return middle;
        if(arr[middle]<target)
            return binarySearch2(arr,middle+1,r,target);
        return binarySearch2(arr,l,middle-1,target);
    }
    //代表陣列長度為0
    return -1;
}

int binarySearchIterative(int arr[],int l,int r,int target){
    while(l<=r){
        int middle =  l + (r - l) / 2;
        if(arr[middle]==target)
            return middle;
        if(arr[middle]<target)
            l = middle + 1;
        if(arr[middle]>target)
            r = middle - 1;
    }
    return -1;
}

int binarySearchIterativeWithFewerCompare(int arr[],int l,int r,int target){
    int middle;
    while(l<r-1){
        middle =  l + (r - l) / 2;
        if(arr[middle]<=target){
            l = middle;
        } else {
            r = middle;
        }
    }
    //剩下最後兩個(最大兩個或最小兩個)
    if(arr[l]==target)
        return l;
    if(arr[r]==target)
        return r;
    return -1;
}

void binaryExecute(){
    int arr[] = { 6,11,25, 33, 45, 100, 410 };
    int arrLength = sizeof(arr)/sizeof(*arr);
    int target = 33;
//    int result = binarySearch1(arr,0,arrLength-1,target);
//    int result = binarySearch2(arr,0,arrLength-1,target);
//    int result = binarySearchIterative(arr,0,arrLength-1,target);
//    int result = binarySearchIterativeWithFewerCompare(arr,0,arrLength-1,target);
//    (result==-1) ? printf("Not found target:%d\n",result) : printf("Target found at:%d\n",result);
}