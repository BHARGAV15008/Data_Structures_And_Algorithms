#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 20

// Array is called ADT data structure means Abstract Data Type;
// Array takes continues location in memory;
// Array allowed to random access data by using index value;

// Inserting element at the end of the arrays;
void insertAtLast(int arr[], int *size, int element) {
    if (*size < MAX_SIZE) {
        arr[*size] = element;
        (*size)++;
    } else {
        printf("Array is full. Cannot insert.\n");
    }
}

// Deleting last elements of the arrays;
void deleteAtLast(int arr[], int *size) {
    if (*size > 0) {
        (*size)--;
    } else {
        printf("Array is empty. Cannot delete.\n");
    }
}

// Inserting elements at middle of the arrays;
void insertAtIndex(int arr[], int *size, int index, int element) {
    if (*size < MAX_SIZE && index >= 0 && index <= *size) {
        for (int i = *size; i > index; i--)
            arr[i] = arr[i - 1];
            
        arr[index] = element;
        (*size)++;
    } else {
        printf("Invalid index or array is full. Cannot insert.\n");
    }
}

// Deleting elements from the middle of the arrays;
void deleteAtIndex(int arr[], int *size, int index) {
    if (*size > 0 && index >= 0 && index < *size) {
        for (int i = index; i < *size - 1; i++)
            arr[i] = arr[i + 1];
            
        (*size)--;
    } else {
        printf("Invalid index or array is empty. Cannot delete.\n");
    }
}

// Traversing elements from the arrays;
void traversal(int arr[], int size) {
    printf("Array elements: ");
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    
    printf("\n");
}

int main() {
    int arr[MAX_SIZE];
    int size = 0;
    int choice, element, index;

    do {
        printf("\n----- Array Operations Menu -----\n");
        printf("1. Insert Last Element\n");
        printf("2. Delete Last Element\n");
        printf("3. Insert Element at Index\n");
        printf("4. Delete Element at Index\n");
        printf("5. Traverse Array\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        system("cls");

        switch (choice) {
            case 1:
                printf("Enter the element to insert: ");
                scanf("%d", &element);
                insertAtLast(arr, &size, element);
                break;
            case 2:
                deleteAtLast(arr, &size);
                break;
            case 3:
                printf("Enter the index where to insert: ");
                scanf("%d", &index);
                printf("Enter the element to insert: ");
                scanf("%d", &element);
                insertAtIndex(arr, &size, index, element);
                break;
            case 4:
                printf("Enter the index to delete: ");
                scanf("%d", &index);
                deleteAtIndex(arr, &size, index);
                break;
            case 5:
                traversal(arr, size);
                break;
            case 6:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}
