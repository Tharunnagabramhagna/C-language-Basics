// inserting an element in an array
#include <stdio.h>

int main()
{
	int size,i,num,pos;
	printf("Enter the size of array = ");
	scanf("%d",&size);
	int a[size];
	// input a
	for(i = 0; i < size; i++)
	{
		printf("Enter %d index element = ",i);
		scanf("%d",&a[i]);
	}
	// input number and position
	printf("Enter the number and position to insert = ");
	scanf("%d%d",&num,&pos);
	if(pos < 1 || pos > size)
	{
		printf("Invalid position");
		return 0;
	}
	// logic to insert element
	for(i = size; i >= pos; i--)
		a[i] = a[i-1];
	a[pos - 1] = num;
	size++;
	// output
	printf("Displaying array elements : ");
	for(i = 0; i < size; i++)
	{
		printf("%d ",a[i]);
	}

	return 0;
}