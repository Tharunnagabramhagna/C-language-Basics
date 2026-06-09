#include <stdio.h>

int main()
{
    // Control Instructions
    // control the flow of instructions in a program.
    // a) Sequence controls
    // the things we learnt in variables is sequence controls.
    // in simple words writing code in sequence is called sequence controls.
    // We will know more about this in next files like in loop concepts.

    // Operators //

    // 1) Relational Operators
    int a = 10;
    int b = 10;
    printf("Statement1 = %d\n", a == b);
    // output => 1 = True
    int c = 12;
    int d = 17;
    printf("Statement2 = %d\n", c > d);  // o/p => 0
    printf("Statement3 = %d\n", 5 >= 5); // o/p => 1
    int e = 40;
    int f = 45;
    printf("Statement4 = %d\n", e < f);    // o/p => 1
    printf("Statement5 = %d\n", 60 <= 60); // o/p => 1
    int y = 20;
    int z = 32;
    printf("Statement6 = %d\n", z != y); // o/p => 1

    // 2) Logical Operators
    int s = 4 > 3;
    int S = 5 > 1;
    int t = 12 > 4;
    int T = 12 > 13;
    printf("AND Operation1 = %d\n", s && S); // o/p => 1
    printf("AND Operation2 = %d\n", t && T); // o/p => 0
    int num1 = 10 > 5;
    int num2 = 8 > 12;
    printf("OR Operation1 = %d\n", num1 || num2);         // o/p => 1
    printf("OR Operation2 = %d\n", (2 > 3) || (10 > 20)); // o/p => 0
    printf("NOT Opertion = %d\n", !(1 > 13));             // o/p => 1

    // Practice Question
    // 1) Write a program to check if a number is divisible by 2 or not ?
    // Ans)
    int x;
    printf("\nCALCULATING IF X DIVISIBLE BY 2..");
    printf("\nEnter your number = ");
    scanf("%d", &x);
    printf("%d\n", x % 2 == 0);

    // 2) Write a program to check if a number is odd or even ?
    // Ans)
    int num;
    printf("\nCALCULATING IF A NUM IS EVEN OR ODD..");
    printf("\nEnter your number = ");
    scanf("%d", &num);
    printf("The number is even beacuse %d means true\n", num % 2 == 0);

    // 3) Write a program to get a two digit number?
    // Ans)
    int val1;
    printf("\nGETTING A TWO DIGIT NUMBER");
    printf("\nEnter your number = ");
    scanf("%d", &val1);
    printf("%d\n", val1 > 9 && val1 < 100);

    // 4) Write a program to print the average of 3 numbers ?
    // Ans)
    int val2 = 5;
    int val3 = 3;
    int val4 = 10;
    printf("\nCALCULATING THE AVERAGE OF 3 NUMBERS");
    printf("\nAverage = %d\n", (val2 + val3 + val4) / 3);

    return 0;
}