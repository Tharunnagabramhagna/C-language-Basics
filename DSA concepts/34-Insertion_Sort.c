/* Insertion Sort */

#include <stdio.h>

void insertionSort(int arr[], int n) {
    for(int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i-1;
        // compare with all the before el's
        while(j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

void display(int arr[], int n) {
    for(int i = 0; i < n; i++)
        printf("%d ",arr[i]);
    printf("\n");
}

int main() {
    int n = 5;
    int arr[5] = {20,34,19,17,1};
    
    insertionSort(arr,n);
    
    printf("Elements of the Sorted Array : ");
    display(arr,n);
    
    return 0;
}