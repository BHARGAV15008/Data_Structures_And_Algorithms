#include <stdio.h>

void display(int arr[], int n){
    printf("Printing the sorted array:\n");
    for (int i = 0; i < n; i++)
        printf("%d  ", arr[i]);
}

void bubbleSort(int arr[], int n) {
    int tmp;
    for (int i = 0; i < n-1; i++) {  // For Number of Passes;
        for (int j = 0; j < n - i - 1; j++) {  // For Comparing Every two consecutive placed value;
            if (arr[j] > arr[j + 1]) {
                tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }
}

void bubbleSortAdaptive(int arr[], int n) {
    int tmp, isSorted = 0;
    for (int i = 0; i < n-1; i++) {  // For Number of Passes;
        isSorted = 1;  // Making code Adaptive;
        for (int j = 0; j < n - i - 1; j++) {  // For Comparing Every two consecutive placed value;
            if (arr[j] > arr[j + 1]) {
                tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
                isSorted = 0;
            }
        }
        if (isSorted)
            return;
    }
}

int main() {
    int n, swap;
    printf("Enter number of elements in the array:\n");
    scanf("%d", &n); 
    int arr[n];
    printf("Enter your integers: \n");
    for (int i = 0; i < n; i++)
      scanf("%d", &arr[i]);

    bubbleSort(arr, n);
    display(arr, n);  
    return 0;
}