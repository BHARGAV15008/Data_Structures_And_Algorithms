#include <stdio.h>

int linearSearch(int arr[], int size, int element) {
    int position;
    for (int i = 0; i < size; i++){
        if (element != arr[i])
            continue;
        
        position = i+1;
        break;
    }
    return position;
}

int main (){
    int arr[] = {12, 13, 14, 56, 78, 24, 19};
    int pos, size;
    size = sizeof(arr) / sizeof(arr[0]);

    pos = linearSearch(arr, size, 14);
    printf("Your value at position:  %d", pos);    
    
    return 0;
}