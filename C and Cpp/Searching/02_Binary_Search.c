#include <stdio.h>

int binarySearch(int arr[], int init, int size, int element) {
    int position = 0;
    int mid = (init + size)/2;
    position = mid + 1;
    
    if (element < arr[mid])
        binarySearch(arr, init, mid - 1, element);
    else if (element > arr[mid])
        binarySearch(arr, mid + 1, size, element);
    else 
        return position;
}

int main (){
    int arr[] = {12, 13, 14, 56, 78, 24, 19};
    int pos, size;
    size = sizeof(arr) / sizeof(arr[0]);

    pos = binarySearch(arr, 0, size, 14);
    printf("Your value at position:  %d", pos);
    
    return 0;
}