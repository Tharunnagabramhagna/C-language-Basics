#include <stdio.h>

// void main()
// {
//     int marks[3];

//     printf("ENTERING MARKS OF SUBJETCS...");
//     printf("\nEnter marks in physics,chemistry and maths = ");
//     // scanf("%d%d%d", &marks[0], &marks[1], &marks[2]);
//     // printf("\nPhy = %d\nChe = %d\nMaths = %d\n", marks[0], marks[1], marks[2]);

//     // Practice Questions
//     /* 1) Write a program to enter price of 3 items and
//     print their final cost with gst. */
//     // Ans)
//     float price[3];

//     printf("\nCOST OF 3 ITEMS....");
//     printf("\nEnter the cost of three items = ");
//     scanf("%f%f%f", &price[0], &price[1], &price[2]);
//     float finalPrice1 = price[0] + (0.18 * price[0]);
//     float finalPrice2 = price[1] + (0.18 * price[1]);
//     float finalPrice3 = price[2] + (0.18 * price[2]);
//     float finalCost = (finalPrice1) + (finalPrice2) + (finalPrice3);
//     printf("Final cost = %.2f\n", finalCost);

//     // Inititalization of Array //
//     int points[] = {30, 40, 50};
//     int meters[4] = {100, 200, 300, 450};

//     // Pointer Arithmetic

//     // 1)
//     int age = 22; // integer is stored in 4 bytes
//     int *ptr = &age;
//     printf("Address of ptr before = %d\n", ptr);
//     ptr++;
//     printf("Address of ptr after increment = %d\n", ptr);
//     ptr--;
//     printf("Address of ptr after decrement = %d\n", ptr);
//     // %u or %d => o/p is same

//     float cost = 100.0; // float is stored in 6 bytes
//     float *ptr2 = &cost;
//     printf("Address of ptr2 before = %d\n", ptr2);
//     ptr2++;
//     printf("Address of ptr2 after increment = %d\n", ptr2);
//     ptr2--;
//     printf("Address of ptr2 after decrement = %d\n", ptr2);

//     char star = '*'; // character is stored in 1 byte
//     char *ptr3 = &star;
//     printf("Address of ptr3 before = %d\n", ptr3);
//     ptr3++;
//     printf("Address of ptr3 after increment = %d\n", ptr3);
//     ptr3--;
//     printf("Address of ptr3 after decrement = %d\n", ptr3);

//     // 2) Difference and comparsion
//     int score = 10;
//     int _score = 11;
//     int *ptr4 = &score;
//     int *_ptr4 = &_score;

//     printf("Address of ptr4 = %u and _ptr4 = %u\n", ptr4, _ptr4);
//     printf("Difference = %u\n", ptr4 - _ptr4);  // o/p => 1 => True
//     _ptr4 = &score;                             // equals both pointers
//     printf("Comparsion = %u\n", ptr4 == _ptr4); // o/p => 1 => True

//     // Array is a pointer
//     // int *ptr = &arr[0] (or) int *ptr = arr;

//     // Tranverse an array
//     int addhar[5];
//     // input
//     int *ptr0 = &addhar[0];

//     for (int i = 0; i < 5; i++)
//     {
//         printf("Enter number in %d index = ", i);
//         scanf("%d", (ptr0 + i));
//     }

//     for (int i = 0; i < 5; i++)
//     {
//         // output
//         printf("Value of %d input = %d\n", i, addhar[i]);
//     }

//     // Multidimensonal Arrays
//     // 2D Arrays
//     int studentMarks[2][3];

//     studentMarks[0][0] = 91;
//     studentMarks[0][1] = 89;
//     studentMarks[0][2] = 87;

//     studentMarks[1][0] = 85;
//     studentMarks[1][1] = 83;
//     studentMarks[1][2] = 81;

//     printf("First Array\n");
//     for (int i = 0, j = 0; j < 3; j++)
//     {
//         printf("Marks of %d index student = %d\n", j, studentMarks[i][j]);
//     }
//     printf("Second Array\n");
//     for (int i = 1, j = 0; j < 3; j++)
//     {
//         printf("Marks of %d index student = %d\n", j, studentMarks[i][j]);
//     }

//     // // Practice Questions

//     // // 1) Write a function to count the number of odd numbers in an array.
//     // // Ans)
//     int n;
//     printf("Enter your number for arrays = ");
//     scanf("%d", &n);
//     int arr[n];
//     for (int i = 0; i < n; i++)
//     {
//         printf("Enter %d index number = ", i);
//         scanf("%d", &arr[i]);
//     }
//     int count = 0;
//     for (int i = 0; i < n; i++)
//     {
//         if (arr[i] % 2 != 0)
//         {
//             count++;
//         }
//     }
//     printf("There are %d odd numbers\n", count);
//     // (or)
//     // int countOdd(int arr[], int n);

//     // int main()
//     // {
//     //     int arr[] = {1, 2, 3, 4, 5, 6};
//     //     printf("%d", countOdd(arr, 6));
//     //     return 0;
//     // }

//     // int countOdd(int arr[], int n)
//     // {
//     //     int count = 0;
//     //     for (int i = 0; i < n; i++)
//     //     {
//     //         if (arr[i] % 2 != 0)
//     //         {
//     //             count++;
//     //         }
//     //     }
//     // }

//     /* 2) int arr[] = {1,2,3,4,5}
//        For the given array, what will the following give?
//        a) *(arr+2)
//        b) *(arr+5)
//     */
//     // Ans)
//     int arr1[] = {1, 2, 3, 4, 5};
//     printf("%d\n", *(arr1 + 2));
//     printf("%d\n", *(arr1 + 5)); // shows address

//     // 3) Write a function to reverse an array.
//     // Ans)
//     int n;
//     // first input
//     printf("Enter the number of arrays = ");
//     scanf("%d", &n);
//     int arr2[n];

//     // second input
//     for (int i = 0; i < n; i++)
//     {
//         printf("Enter %d index element = ", i);
//         scanf("%d", &arr2[i]);
//     }

//     // logic
//     for (int i = 0; i < n / 2; i++)
//     {
//         int firstVal = arr2[i];
//         int secondVal = arr2[n - i - 1];
//         arr2[n - i - 1] = firstVal;
//         arr2[i] = secondVal;
//     }

//     // output
//     printf("\nArray after change :\n");
//     for (int i = 0; i < n; i++)
//     {
//         printf("%d\t", arr2[i]);
//     }
// }

// Array as function Argument

void printNumbers(int arr[], int n);

// int main()
// {
//     int arr[] = {1, 2, 3, 4, 5, 6};
//     printNumbers(arr, 6);
//     return 0;
// }

void printNumbers(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d \t", arr[i]);
    }
    printf("\n");
}
// we can replace arr[] with *arr which gives same output

// Practice Questions (continue..)
// 4) Write a program to store the first n fibonacci numbers.
// Ans)
// void main()
// {
//     int n;
//     printf("Enter number (n>2) = ");
//     scanf("%d", &n);

//     int fib[n];
//     fib[0] = 0;
//     fib[1] = 1;
//     printf("%d\t%d\t", fib[0], fib[1]);

//     for (int i = 2; i <= n; i++)
//     {
//         fib[i] = fib[i - 1] + fib[i - 2];
//         printf("%d\t", fib[i]);
//     }
// }

// 5) Create a 2D array,storing the table of 2 and 3.
// Ans)
void storeTable(int arr[][10], int m, int n, int number);

int main()
{
    int table[2][10];
    storeTable(table, 0, 10, 2);
    storeTable(table, 1, 10, 3);

    for (int i = 0; i < 10; i++)
    {
        printf("%d\t", table[0][i]);
    }
    printf("\n");

    for (int i = 0; i < 10; i++)
    {
        printf("%d\t", table[1][i]);
    }
    printf("\n");

    return 0;
}

void storeTable(int arr[][10], int m, int n, int number)
{
    for (int i = 0; i < n; i++)
    {
        arr[m][i] = number * (i + 1);
    }
}