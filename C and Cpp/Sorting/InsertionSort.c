#include <stdio.h>

void display(int array[], int size) {
    for (int i = 0; i < size; i++) {
      printf("%d ", array[i]);
    }
    printf("\n");
}

void insertionSort(int array[], int size) {
    int key, j;
    for (int step = 1; step < size; step++) {
        key = array[step];
        j = step - 1;

        while (key < array[j] && j >= 0) {
            array[j + 1] = array[j];
            --j;
        }
        array[j + 1] = key;
    }
}

int main() {
    int n;
    printf("Enter the size of element:\t");
    scanf("%d", &n);
    int data[n];

    printf("Enter your elements here: \n");
    for(int i = 0; i < n; i++)
        scanf("%d", &data[i]);
        
    int size = sizeof(data) / sizeof(data[0]);
    insertionSort(data, size);
    printf("Sorted array in ascending order:\n");
    display(data, size);
}