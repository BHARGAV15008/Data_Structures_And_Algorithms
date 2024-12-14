#include <stdio.h>

void heapify(int* arr, int n, int i){
    int largest = i;
    int left = 2 * i + 1;
    int right  = 2 * i + 2;
 
    if (left < n && arr[left] > arr[largest])
        largest = left;
 
    if (right < n && arr[right] > arr[largest])
        largest = right;
 
    if (largest != i){
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
 
        heapify(arr, n, largest);
    }
}

void heapSort(int* arr, int n){
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i >= 0; i--){
        int temp = arr[i];
        arr[i] = arr[0];
        arr[0] = temp;
        heapify(arr, i, 0);
    }
}

void display(int a[],const int size){
    int i;
    for(i=0; i<size; i++)
        printf("%d ",a[i]);
    printf("\n");
}

int main(){
    int n;
    printf("Enter the size of element:\t");
    scanf("%d", &n);
    int data[n];

    printf("Enter your elements here: \n");
    for(int i = 0; i < n; i++)
        scanf("%d", &data[i]);
        
    int size = sizeof(data) / sizeof(data[0]);
    heapSort(data, size);
    printf("Sorted array in ascending order:\n");
    display(data, size);
    return 0;
}