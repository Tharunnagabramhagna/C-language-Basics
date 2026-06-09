// Deleting an element in an array
#include <stdio.h>

int main()
{
	int size,i,num,pos;
	// input size
	printf("Enter the size of array = ");
	scanf("%d",&size);
	int arr[size];
	// input arr
	for(i = 0; i < size; i++)
	{
		printf("Enter %d index element = ",i);
		scanf("%d",&arr[i]);
	}
	// input number and position
	printf("Enter number and position to delete = ");
	scanf("%d%d",&num,&pos);
	if(pos < 1 || pos > size+1)
	{
		printf("Invalid position");
		return 0;
	}
	// logic to delete
	for(i = pos - 1; i < size - 1; i++)
		arr[i] = arr[i+1];
	size--;
	// output
	printf("Displaying the array : ");
	for(i = 0; i < size; i++)
		printf("%d ",arr[i]);

	return 0;
}