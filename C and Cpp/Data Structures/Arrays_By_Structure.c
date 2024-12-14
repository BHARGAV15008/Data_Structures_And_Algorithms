#include <stdio.h>
#include <stdlib.h>

// Create abstract data type: Arrays;
struct mArray {
    int totalSize;
    int useSize;
    int *ptr;
};

void createArray(struct mArray* arr, int tSize, int uSize) {
    arr->totalSize = tSize;
    arr->useSize = uSize;
    arr->ptr = (int*) malloc(tSize*sizeof(int));
    // (*arr).totalSize = tSize;
    // (*arr).useSize = uSize;
    // (*arr).ptr = (int*) malloc(tSize*sizeof(int));
}

void show(struct mArray* arr) {
    for (int i = 0; i < arr->useSize; i++)
        printf("%d  ", (arr->ptr)[i]);
    printf("\n");
}

// Inserting element at the middle of the array;
void insertAtPosition(struct mArray* arr, int pos, int element){
    if (pos < arr->totalSize){
        for (int i = (arr->useSize)-1; i >= pos; i--)
            arr->ptr[i+1] = arr->ptr[i];
        
        arr->ptr[pos] = element;
        (arr->useSize)++;
    }
    else
        printf("\nYour Array is Full!!!");
}

// Inserting element at the Last of the array;
void insertLast(struct mArray* arr, int element){
    if (arr->useSize != arr->totalSize){        
        arr->ptr[arr->useSize] = element;
        (arr->useSize)++;
    }
    else
        printf("\nYour Array is Full!!!");
}

// Inserting element at the Front of the array;
void insertFront(struct mArray* arr, int element){
    if (arr->useSize != arr->totalSize){
        for (int i = (arr->useSize)-1; i >= 0; i--)
            arr->ptr[i+1] = arr->ptr[i];
        
        arr->ptr[0] = element;
        (arr->useSize)++;
    }
    else
        printf("\nYour Array is Full!!!");
}

// Deleting element from the middle of the array;
void deleteAtPosition(struct mArray* arr, int pos){
    if (pos < arr->useSize){
        for (int i = pos; i < (arr->useSize); i++)
            arr->ptr[i] = arr->ptr[i+1];

        (arr->useSize)--;
    }
    else
        printf("\nYour Array position is Empty!!!");
}

// Deleting element from the Last of the array;
void deleteLast(struct mArray* arr){
    if (0 < arr->useSize){
        (arr->useSize)--;
    }
    else
        printf("\nYour Array is Empty!!!");
}

// Deleting element from the Front of the array;
void deleteFront(struct mArray* arr){
    if (0 < arr->useSize){
        for (int i = 0; i < (arr->useSize); i++)
            arr->ptr[i] = arr->ptr[i+1];

        (arr->useSize)--;
    }
    else
        printf("\nYour Array is Empty!!!");
}

int main (){
    struct mArray marks;
    createArray(&marks, 100, 0);
    insertFront(&marks, 53);
    insertFront(&marks, 47);
    insertFront(&marks, 48);
    insertFront(&marks, 46);
    insertFront(&marks, 44);
    insertLast(&marks, 55);
    insertAtPosition(&marks, 3, 49);
    show(&marks);
    deleteAtPosition(&marks, 4);
    show(&marks);
    deleteFront(&marks);
    show(&marks);
    deleteLast(&marks);
    show(&marks);
    
    return 0;
}