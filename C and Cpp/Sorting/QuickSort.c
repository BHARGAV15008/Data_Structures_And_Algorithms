#include <stdio.h>

void swap (int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int quickPartition (int arr[], int low, int high) {
    int pivot = arr[low];
    int i = low+1, j = high;

    do {
        while (arr[i] <= pivot)
            i++;

        while (arr[j] > pivot)
            j--;
        
        if (i < j)
            swap(&arr[i], &arr[j]);

    } while (i < j);
    swap (&arr[low], &arr[j]);
    return j;
}

void quichSort (int arr[], int low, int high) {
    int partIndex; // get partition index means pivot position;
    if (low < high){
        partIndex = quickPartition (arr, low, high);
        quichSort (arr, low, partIndex-1);   // sort left sub array;
        quichSort (arr, partIndex+1, high);  // sort right sub array;
    }
}

void display(int array[], int size) {
    for (int i = 0; i < size; i++) {
      printf("%d ", array[i]);
    }
    printf("\n");
}

int main (){
    int n;
    printf("Enter the size of element:\t");
    scanf("%d", &n);
    int data[n];

    printf("Enter your elements here: \n");
    for(int i = 0; i < n; i++)
        scanf("%d", &data[i]);
    

    quichSort(data, 0, n-1);
    printf("Sorted array in ascending order:\n");
    display(data, n);
    
    return 0;
}