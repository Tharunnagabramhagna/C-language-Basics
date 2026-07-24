/* Merge Sort */

#include <stdio.h>

void merge(int arr[], int st, int mid, int end) {
	int n1 = mid - st + 1;
	int n2 = end - mid;
	
	int L[n1], R[n2];

    for(int i = 0; i < n1; i++) // Left half
        L[i] = arr[st+i];
    
    for(int i = 0; i < n2; i++) // Right Half
        R[i] = arr[mid+1+i];
        
    int i = 0, j = 0, k = st;
    
    while(i < n1 && j < n2) { // Sort the halfs
        if(L[i] < R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }
    
    // Sort the left overs
    while(i < n1)
        arr[k++] = L[i++];
    while(j < n2)
        arr[k++] = R[j++];
}

void mergeSort(int arr[],int st, int end) {
	// Base Case
	if(st >= end)
		return;

	int mid = st + (end - st) / 2;

	mergeSort(arr,st,mid); // Left Half

	mergeSort(arr,mid+1,end); // Right Half

	merge(arr,st,mid,end);
}

void display(int arr[], int n) {
    for(int i = 0; i < n; i++)
        printf("%d ",arr[i]);
    printf("\n");
}

int main() {
    int n = 5;
    int arr[5] = {34,12,18,90,48};
    mergeSort(arr,0,n-1);
    printf("Elements of the Sorted Array : ");
    display(arr,n);
    return 0;
}