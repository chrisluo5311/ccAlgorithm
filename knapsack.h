//
// Created by chris on 2022/5/23.
//
struct goods {
    int value, weight;
};

void selectionSortByValWeightRatio(struct goods arr[], int n){
    int i, j, max_idx;
    for (i = 0; i < n-1; i++){
        max_idx = i;
        for (j = i+1; j < n; j++){
            double prev_val = (double)arr[max_idx].value / (double)arr[max_idx].weight;
            double next_val = (double)arr[j].value / (double)arr[j].weight;
            if (next_val > prev_val)
                max_idx = j;
        }
        swap(&arr[max_idx], &arr[i]);
    }
}

double fractionalKnapsack(int w, struct goods arr[], int n){
    selectionSortByValWeightRatio(arr,n);
    double finalValue = 0.0;
    for(int i = 0; i < n ; i++){
        if(arr[i].weight <= w){
            w -= arr[i].weight;
            finalValue += arr[i].value;
        } else {
            //超過限制以unit profit乘上剩餘總重量放入
            finalValue += arr[i].value * ((double)w / (double)arr[i].weight );
            break;
        }
    }
    return finalValue;
}


int knapsackExecute(){
    int w = 50;
    struct goods goods[] = {{ 60, 10 }, { 100, 20 }, { 120, 30 } };
    int n = sizeof(goods) / sizeof(goods[0]);
    double finalValue = fractionalKnapsack(w,goods,n);
    printf("Maximum value we can obtain: %f",finalValue);
    return 0;
}