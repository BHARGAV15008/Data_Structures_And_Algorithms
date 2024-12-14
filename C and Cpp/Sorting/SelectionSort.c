#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

void swap(int *x,int *y){
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void selectionSort(int arr[], int n){
    int i, j, min;
    for (i = 0; i < n - 1; i++){
        min = i;
        for (j = i + 1; j < n; j++){
            if (arr[j] < arr[min])
                min = j;
        }
        swap(&arr[i], &arr[min]);
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
    selectionSort(data, n);
    printf("Sorted array in ascending order:\n");
    display(data, size);
    return 0;
}