#include <stdio.h>
#include <math.h>

void printHello(int count);

// int main()
// {
//     printHello(5);
//     return 0;
// }

// recursive function
void printHello(int count)
{
    if (count == 0)
    {
        return;
    }
    printf("Hello World\n");
    printHello(count - 1);
}

// Practice Questions

// 1) Sum of first n natural numbers.
// Ans)

int sumNumbers(int n);

// int main()
// {
//     printf("\nSUM OF N NATURAL NUMBERS...");
//     printf("\nSum = %d\n", sumNumbers(5));
//     return 0;
// }

int sumNumbers(int n)
{
    if (n == 1)
    {
        return 1;
    }
    int sumBefore = sumNumbers(n - 1); // sum from 1 to n-1
    int sumTotal = sumBefore + n;      // sum from 1 to n
    return sumTotal;
}

// 2) factorial of n number?
// Ans)
int factorial(int n);

// int main()
// {
//     printf("\nFACTORIAL OF N...");
//     printf("\nFactorial of Number = %d\n", factorial(6));
//     return 0;
// }

int factorial(int n)
{
    if (n == 1)
    {
        return 1;
    }
    int factorialBefore = factorial((n - 1));
    int factorialTotal = factorialBefore * n;
    return factorialTotal;
}

// 3) Write a function to convert celsius to fahrenheit.
// Ans)

float tempConvert(float celsius);

// int main()
// {
//     printf("CONVERTING CELSIUS TO FAHRENHEIT...");
//     printf("\nF = %f\n", tempConvert(32));
//     return 0;
// }

float tempConvert(float celsius)
{
    float firstConvert = (celsius * (9.0 / 5.0)) + 32;
    return firstConvert;
}

// 4) Write a function Percentage of a student from Marks in Science,Math and Sanskrit.
// Ans)
int calculPercentage(int science, int math, int sanskrit);

// int main()
// {
//     int sc, math, sans;
//     printf("\nEnter your marks = ");
//     scanf("%d,%d,%d", &sc, &math, &sans);

//     printf("Your Percentage is %d\n", calculPercentage(sc, math, sans));
// }
int calculPercentage(int science, int math, int sanskrit)
{
    return ((science + math + sanskrit) / 3);
}

// 5) Write a function to print n terms of the fibonacci sequence.
// Ans)
// fib(0) = 0, fib(1) = 1, fib(2) = 1, fib(3) = 2,etc..
// sequence => 0,1,1,2,3,5,8,13,21
// formula => fib(n) = fib(n-1) + fib(n-2)

int fib(int n);

// int main()
// {
//     int n;
//     printf("\nEnter your number = ");
//     scanf("%d", &n);
//     printf("Fibonacci of %d = %d\n", n, fib(n));

//     return 0;
// }

int fib(int n)
{
    if (n == 0)
    {
        return 0;
    }
    if (n == 1)
    {
        return 1;
    }

    int fibN1 = fib(n - 1);
    int fibN2 = fib(n - 2);
    int fibN = fibN1 + fibN2;
    return fibN;
}