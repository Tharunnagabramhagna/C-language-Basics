/* Selection Sort */

#include <stdio.h>

void SelectionSort(int arr[], int n) {
    for(int i = 0; i < n-1; i++) {
        int min = i;
        for(int j = i + 1; j < n; j++) {
            if(arr[j] < arr[min])
                min = j;
        }
        if(min != i) {
            int temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
    }
}

void display(int arr[], int n) {
    printf("Elements of the array : ");
    for(int i = 0; i < n; i++)
        printf("%d ",arr[i]);
    printf("\n");
} 

int main() {
    int n = 6;
    int arr[6] = {7,4,10,8,3,1};
    printf("Before Sorting : \n");
    display(arr,n);
    SelectionSort(arr,n);
    printf("After Sorting : \n");
    display(arr,n);
    return 0;
}