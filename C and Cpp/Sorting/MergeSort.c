#include <stdio.h>

/*
// Case I:
void merge(int arr[], int left, int mid, int right){ 
    int i, j, k; 
    int n1 = mid - left + 1; 
    int n2 =  right - mid; 
    int L[n1], R[n2];

    for (i = 0; i < n1; i++) 
        L[i] = arr[left + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[mid + 1 + j]; 

    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2){ 
        if (L[i] <= R[j]){ 
            arr[k] = L[i]; 
            i++; 
        } 
        else{ 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    }
    
    while (i < n1) 
        arr[k++] = L[i++];

    while (j < n2) 
        arr[k++] = R[j++];
}

void mergeSort(int arr[], int left, int right){ 
    if (left < right){
        int m = left + (right - left)/2; 
        mergeSort(arr, left, m); 
        mergeSort(arr, m+1, right); 
        merge(arr, left, m, right); 
    } 
} 
*/

void merge (int arr[], int low, int mid, int high) {
    int i, j, k, lArr[20];
    i = low;
    j = mid + 1;
    k = low;
    while (i <= mid && j <= high) {
        if (arr[i] < arr[j])
            lArr[k++] = arr[i++];
        else
            lArr[k++] = arr[j++];
    }

    while (i <= mid)
        lArr[k++] = arr[i++];

    while (j <= high)
        lArr[k++] = arr[j++];
    
    for (int i = low; i <= high; i++)
        arr[i] = lArr[i];
}

void mergeSort(int arr[], int low, int high) {
    int mid;
    if (low < high) {
        mid = (low+high)/2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid+1, high);
        merge(arr, low, mid, high);
    }
}

void display(int A[], int size){ 
    int i; 
    for (i=0; i < size; i++) 
        printf("%d ", A[i]); 
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
    mergeSort(data, 0, size-1);
    printf("Sorted array in ascending order:\n");
    display(data, size); 
    return 0; 
} 