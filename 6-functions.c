#include <stdio.h>
#include <math.h>

// Function Prototype
void printHello();

// int main()
// {
//     printHello(); // Calling a function
//     printHello();
//     printHello();
//     return 0;
// }

// Function definition
void printHello()
{
    printf("Hello!\n");
    printf("My name is Tharun!\n");
}

// Practice Question

/* 1) Write two functions - one to print "Hello"
& second to print "good bye". */
// Ans)
void printHello1();
void sayBye();

// void main()
// {
//     printHello1();
//     sayBye();
// }

void printHello1()
{
    printf("Hello\n");
}

void sayBye()
{
    printf("good bye\n");
}

/* 2) Write a function that prints "Namaste" if user
is Indian and "Bonjour" if the user is French. */
// Ans)
void namaste();
void bonjour();

// int main()
// {
//     printf("\nEnter 'f' for french and 'i' for indian : ");
//     char ch;
//     scanf("%c", &ch);

//     if (ch == 'i')
//     {
//         namaste();
//     }
//     else if (ch == 'f')
//     {
//         bonjour();
//     }
//     else
//     {
//         printf("Sorry I'm unable to understand!");
//     }

//     return 0;
// }

void namaste()
{
    printf("Namaste");
}

void bonjour()
{
    printf("Bonjour");
}

// combine two functions
void printHello2();
void sayBye1();

// void main()
// {
//     printHello2(); // It will call both functions now
// }

void printHello2()
{
    printf("Hello\n");
    sayBye1();
}

void sayBye1()
{
    printf("good bye\n");
}

// Sum of two numbers
int sum(int a, int b);

// int main()
// {
//     int a, b;
//     printf("Enter a value = ");
//     scanf("%d", &a);
//     printf("Enter b value = ");
//     scanf("%d", &b);

//     int s = sum(a, b);
//     printf("Sum is %d\n", s);

//     return 0;
// }

int sum(int a, int b)
{
    return a + b;
}

// Multiplication Table
int printTable(int n); // parameter is "int n"

// int main()
// {
//     int n;
//     printf("Enter your number = ");
//     scanf("%d", &n);

//     printTable(n); // argument (or) actual parameter

//     return 0;
// }

int printTable(int n)
{
    for (int i = 1; i <= 10; i++)
    {
        printf("%d\n", n * i);
    }
}

// Calculate price with GST
int calculatePrice(float value);

// int main()
// {
//     float value = 120.00;
//     printf("The value = %.2f\n", value);

//     /* Changes to parameters in function don't
//     change the values in calling function. */
//     /* Because a copy of argument is passed to the function */

//     calculatePrice(value);

//     return 0;
// }

int calculatePrice(float value)
{
    value += (0.18 * value);
    printf("The price = %.2f\n", value);
}

// Practice Question

/* 3) Use library functions to calculate the square of a
number given by user.*/
// Ans)
// int main()
// {
//     int n;
//     printf("Enter your number = ");
//     scanf("%d", &n);

//     printf("\nSquare of your number = %.0f\n", pow(n, 2));
//     return 0;
// }

/* 4) Write functions to calculate area of a square,a circle
and a rectangle. */
// Ans)
int squareArea(int a);
int circleArea(int r);
int rectangleArea(int l, int b);

int main()
{
    int a;
    printf("\nEnter your side = ");
    scanf("%d", &a);
    squareArea(a);

    int r;
    printf("\nEnter your radius = ");
    scanf("%d", &r);
    circleArea(r);

    int l, b;
    printf("\nEnter your length : ");
    scanf("%d", &l);
    printf("\nEnter your breadth : ");
    scanf("%d", &b);
    rectangleArea(l, b);

    return 0;
}

int squareArea(int a)
{
    printf("Area of square = %d\n", a * a);
}

int circleArea(int r)
{
    printf("Area of circle = %.2f\n", 3.14 * r * r);
}

int rectangleArea(int l, int b)
{
    printf("Area of rectangle = %d\n", l * b);
}