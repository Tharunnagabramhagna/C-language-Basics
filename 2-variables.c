#include <stdio.h>
#include <math.h>
#define PI 3.14

int main()
{
    // VARIABLES AND DATA TYPES
    int age = 23;
    printf("My age is %d\n", age);
    printf("The value of pi is %.2f\n", PI);
    char Star = '*';
    printf("We represent a Star with the symbol %c\n", Star);
    // Input concept
    printf("Enter age = ");
    scanf("%d", &age);
    printf("Age is updated to %d\n", age);

    // Calculation between of two numbers
    int a, b;
    printf("Enter 'a' value = ");
    scanf("%d", &a);

    printf("\nEnter 'b' value = ");
    scanf("%d", &b);

    int sum = a + b;
    printf("Sum = %d\n", sum);
    int sub = a - b;
    printf("Subtraction = %d\n", sub);
    int multi = a * b;
    printf("Multiplication = %d\n", multi);

    // Practice questions

    // 1) Write a program to calculate the area of a square (side is given) ?

    // Ans)
    int side;
    printf("\nCALCULATING AREA OF SQUARE...");
    printf("\nEnter value of side = ");
    scanf("%d", &side);
    printf("Area = %d\n", side * side);

    // 2) Write a program to calculate the area of a circle ?

    // Ans)
    int r;
    printf("\nCALCULATING AREA OF CIRCLE...");
    printf("\nEnter the radius = ");
    scanf("%d", &r);
    printf("Area = %.2f\n", PI * r * r);

    // Arithmetic Operators

    int A = 22;
    int B = A;
    int d = 1, w;

    printf("B value = %d\n", B);
    printf("d value = %d\n", d);

    int newCar = 10;
    int years = 5;
    int oldCar = newCar + years;

    printf("I had my old car for %d long years.\n", oldCar);

    int f, u, l;
    f = u = l = 1;

    int x, y = A * B;
    printf("y value = %d\n", y);

    int power = pow(a, b);
    printf("power = %d\n", power);

    // Modular Operator

    int mod = 12 % 10;
    printf("modular = %d\n", mod);

    printf("%.1f\n", 2.0 * 2);

    // for approximate answer
    printf("%d\n", 2 / 3);
    // for perfect answer
    printf("%f\n", 2.0 / 3.0);

    // Size-of Operator
    int value = 10;
    printf("Size of value is %d bytes\n", sizeof(value));

    // Conersion of double to int
    double m = (int)1.999999;
    printf("M value = %d\n", m);

    // Operator precedence
    int cal = 2 + 3 * 60;
    printf("Answer = %d\n", cal);

    // Associativity

    int ans = ((4 * 2) / (2 * 2)) / (2 * 1);
    printf("Final output = %d\n", ans);

    // Practice Question
    // a) 5*2 - 2*3
    printf("a)answer = %d\n", 5 * 2 - 2 * 3);

    // b) 5*2 / 2*3
    printf("b)answer = %d\n", 5 * 2 / 2 * 3);
    // Explanation :-
    // 5*(2/2)*3
    // 5*1*3 = 15

    // c) 5*(2/2)*3
    printf("c)answer = %d\n", 5 * (2 / 2) * 3);

    // d) 5+2 / 2*3
    printf("d)answer = %d\n", 5 + 2 / 2 * 3);
    // Explanation :-
    // 5+((2/2)*3)
    // 5+(1*3)
    // 5+3 = 8

    return 0;
}