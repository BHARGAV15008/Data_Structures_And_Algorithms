// FInding maximum and minimum elements from array using divide and conquer;

#include <stdio.h>

void DACMaxMin(int arr[], int low, int high, int *max, int *min) {
    int mid;
    if (low == high)
        *max = *min = arr[low];
    else if (low == high-1) {
        if (arr[low] > arr[high]){
            *min = arr[high];
            *max = arr[low];
        } 
        else {
            *max = arr[high];
            *min = arr[low];
        }
    } 
    else {
        mid = (low + high) / 2;
        DACMaxMin (arr, low, mid, max, min);
        DACMaxMin (arr, mid+1, high, max, min);
    }

    if (*min > arr[mid])
        *min = arr[mid];

    if (*max < arr[mid + 1])
        *max = arr[mid + 1];
}

int main (){
    int max, min;
    max = min = 0;
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    DACMaxMin(arr, 0, 10, &max, &min);
    printf("Maximum:  %d         Minimum:  %d", max, min);
    
    return 0;
}