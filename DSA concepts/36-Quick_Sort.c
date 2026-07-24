/* Quick Sort */

#include <stdio.h>

int partition(int arr[], int st, int end) {
    int pivot = arr[st],temp;
    int i = st + 1, j = end;
    while(i <= j) {
        while(i <= end && arr[i] <= pivot)
            i++;
        while(arr[j] > pivot)
            j--;
        if(i < j) {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    temp = arr[j];
    arr[j] = arr[st];
    arr[st] = temp;
    return j;
}

void QuickSort(int arr[], int st, int end) {
    if(st < end) {
        int pivotIdx = partition(arr,st,end);
        QuickSort(arr,st,pivotIdx-1); // Left half
        QuickSort(arr,pivotIdx+1,end); // Right half
    }
}

void display(int arr[], int n) {
    printf("Elements of the array : ");
    for(int i = 0; i < n; i++)
        printf("%d ",arr[i]);
    printf("\n");
}

int main() {
    int n = 9;
    int arr[9] = {7,6,10,5,9,2,1,15,7};
    printf("Before Sorting : \n");
    display(arr,n);
    
    QuickSort(arr,0,n-1);
    
    printf("After Sorting : \n");
    display(arr,n);
    
    return 0;
}