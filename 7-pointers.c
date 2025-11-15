#include <stdio.h>

// void main()
// {
//     // Ex-1
//     int age = 19;
//     printf("Old variable is %d\n", age);
//     int *ptr = &age; // int *<pointer variable> = &<address of age>
//     int Age = *ptr;  // stored in new variable
//     printf("New variable is %d\n", Age);
//     // Addresses
//     printf("Address of age = %p\n", &age);
//     printf("Address of age(in numbers) = %u\n", &age); // %u converts into hexa decimal form
//     printf("ptr = %p\n", ptr);
//     printf("Address of pointer = %p\n", &ptr);
//     // Values
//     printf("age value = %d\n", age);
//     printf("Value of ptr = %d\n", *ptr);
//     printf("Values of &age = %d\n", *(&age));

//     // Ex-2
//     float price = 98.69;
//     float *ptr2 = &price;
//     float **pptr = &ptr2;
//     printf("ptr2 address = %u\n", &(*ptr2));
//     printf("pptr address = %u\n", &(**pptr));
//     printf("ptr2 value = %.2f\n", *ptr2);
//     printf("pptr value = %.2f\n", **pptr);

//     // Practice Questions

//     // 1) Find output of a code written below?
//     // Ans)
//     int *ptr1;
//     int x;
//     ptr1 = &x;
//     *ptr1 = 0;

//     printf("x = %d\n", x);        // o/p => 0
//     printf("*ptr = %d\n", *ptr1); // o/p => 0

//     *ptr1 += 5;
//     printf("x value now is %d\n", x); // o/p => 5
//     printf("*ptr = %d\n", *ptr1);     // o/p => 5

//     (*ptr1)++;
//     printf("x value again becomes %d\n", x); // o/p => 6
//     printf("*ptr = %d\n", *ptr1);            // o/p => 6

//     // 2) Print the value of 'i' from its pointer to pointer.
//     // Ans)
//     int i = 2;
//     int *ptr3 = &i;
//     int **pptr2 = &ptr3;

//     printf("Value of pptr2 = %d\n", **pptr2);
// }

// Function call //

// 1) Call by Value
void square(int n);

// int main()
// {
//     int num = 4;
//     square(num);
//     printf("number = %d\n", num);
// } // no change of values in main function

void square(int n)
{
    n = n * n;
    printf("Square = %d\n", n);
}

// 2) Call by Reference
// taking address of variables as argument
void cube(int n);
void Cube(int *n);

// int main()
// {
//     int num = 2;
//     cube(num);
//     printf("num before change = %d\n", num);

//     Cube(&num);
//     printf("num after change = %d\n", num);
//     /* As it stores address it notices the changes
//     in Cube function but it is not the case in cube function */
// }

void cube(int n)
{
    n = n * n * n;
    printf("Cube = %d\n", n);
}

void Cube(int *n)
{
    *n = (*n) * (*n) * (*n);
    printf("Cube = %d\n", *n);
}

// // Practice Questions

// // 3) Swap two numbers a and b using pointers.
// Ans)
void swap(int a, int b);
void _swap(int *a, int *b);

// void main()
// {
//     int x = 5, y = 3;
//     swap(x, y);
//     printf("\nx value = %d and y value = %d", x, y);
//     _swap(&x, &y);
//     printf("\nx value = %d and y value = %d", x, y);
//     // being changes in main function too
// }
// x,y are a,b before change

void swap(int a, int b)
{
    int c = b;
    b = a;
    a = c;
    printf("\na value = %d and b value = %d", a, b);
}

void _swap(int *a, int *b)
{
    int c = *b;
    *b = *a;
    *a = c;
    printf("\na value = %d and b value = %d", *a, *b);
}

// 4) Will the address output be same?
// Ans)
void printAddress(int n);

// void main()
// {
//     int n = 3;
//     printf("main n address = %p\n", &n);
//     printAddress(n);
// }

void printAddress(int n)
{
    printf("other n address = %p\n", &n);
}

/* 5) Write a function to calculate sum,product,average of 2 numbers.
Print them in the main function. */
// Ans)
void doWork(int a, int b, int *sum, int *prod, int *avg);

// int main()
// {
//     int a = 3;
//     int b = 11;
//     int sum, prod, avg;
//     doWork(a, b, &sum, &prod, &avg);

//     printf("Sum = %d\nproduct = %d\naverage = %d\n", sum, prod, avg);

//     return 0;
// }

void doWork(int a, int b, int *sum, int *prod, int *avg)
{
    *sum = a + b;
    *prod = a * b;
    *avg = (a + b) / 2;
}