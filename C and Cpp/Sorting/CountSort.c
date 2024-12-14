#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// FInding Maximum elements of array;
int maximum (int arr[], int size) {
    int max = INT_MIN;
    for (int i = 0; i < size; i++)
        if (max < arr[i])
            max = arr[i];
    
    return max;
}

void countSort (int arr[], int size) {
    int i ,j, max;
    max = maximum (arr, size);
    int *count  = (int *) malloc(max+1 * sizeof(int));  // create counting arra;

    for (i = 0; i < max+1; i++)
        count[i] = 0;
    
    for (i = 0; i < size; i++)
        count[arr[i]] = count[arr[i]] + 1;
    
    i = 0;  // Counter for counting array;
    j = 0;  // Counter for given array;
    while (j <= max) {
        if (count[i] > 0){
            arr[j++] = i;
            count[i] = count[i] - 1;
        } 
        else
            i++;

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

    countSort(data, n);
    printf("Sorted array in ascending order:\n");
    display(data, n);
    
    return 0;
}