#include <stdio.h>
#include <math.h>

void main()
{
    // 1) Write a C program two add two float numbers?
    // Ans)
    float x, y, Sum;
    printf("\nADDING TWO FLOAT NUMBERS...");
    printf("\nEnter x and y values = ");
    scanf("%f,%f", &x, &y);
    Sum = x + y;
    printf("Sum = %.1f\n", Sum);

    /* 2) Write a C program of taking 3 inputs of Grade,Average and Age also
    display as below. */
    // Ans)
    char grade;
    float avg;
    int age;
    printf("\nEnter your Grade,Average and age = ");
    scanf("%c%f%d", &grade, &avg, &age);
    printf("Grade = %c\nAvg = %.2f\nAge = %d\n", grade, avg, age);

    /* 3) The base of a triangle is 15cm and the height is 8cm.
    Write a C program to find the area of the triangle. */
    // Ans)
    int br, h;
    printf("Enter Base and Height = ");
    scanf("%d%d", &br, &h);
    int Area = (br * h) / 2;
    printf("Area of Triangle = %d", Area);

    /* 4) Write a C program to swap given two numbers. */
    // Ans)
    int A, B, C;
    printf("Enter A and B values : ");
    scanf("%d%d", &A, &B);
    C = A;
    A = B;
    B = C;
    printf("A and B values now are %d and %d", A, B);

    // 5) Write a C program to find the root of a quadratic equation.
    // Ans)
    int a,b,c;
    float discri,realPart,imgPart;
    
    // Input
    printf("Enter a,b and c values : ");
    scanf("%d%d%d",&a,&b,&c);
    
    discri = (b*b) - (4*a*c);
    
    // output
    if(discri > 0) {
        float root1 = (-b + sqrt(discri)) / (2*a);
        float root2 = (-b - sqrt(discri)) / (2*a);
        
        printf("Roots are real and different\n");
        printf("Root1 = %.2f\n",root1);
        printf("Root2 = %.2f\n",root2);
    } else if (discri == 0) {
        float root = -b / (2*a);
        
        printf("Roots are real and equal\n");
        printf("Root = %.2f\n",root);
    } else {
        realPart = -b / (2*a);
        imgPart = (sqrt(-discri)) / (2*a);
        
        printf("Roots are complex and imaginary\n");
        printf("Root1 = %.2f + %.2fi\n",realPart,imgPart);
        printf("Root2 = %.2f - %.2fi\n",realPart,imgPart);
    } 

    // 6) Write a C program to show pyramid stars table.
    // Ans)
    int i, j, space, rows;

    printf("Enter the number of rows = ");
    scanf("%d", &rows);

    for (i = 1; i <= rows; i++)
    {
        for (space = 1; space <= rows - i; space++)
        {
            printf(" ");
        }
        for (j = 1; j <= 2 * i - 1; j++)
        {
            printf("*");
        }
        printf("\n");
    }
}