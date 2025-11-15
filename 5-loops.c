#include <stdio.h>

int main()
{
    // for loop //
    printf("0 to 10 values of i\n");
    for (int i = 0; i <= 10; i++)
    {
        printf("i = %d \n", i);
    }

    printf("10 to 1 values of i\n");
    for (int i = 10; i >= 1; i--)
    {
        printf("i = %d \n", i);
    }

    printf("LOOPING IN FLOAT..");
    for (float i = 1.0; i <= 5.0; i++)
    {
        printf("\nfloat val = %.2f \n", i);
    }

    printf("LOOPING FOR LETTERS..");
    for (char ch = 'a'; ch <= 'z'; ch++)
    {
        printf("\nLetter = %c \n", ch);
    }

    // increment and decrement operator

    // pre increment
    int x = 1;
    printf("x = %d \n", x++); // use, then increase
    printf("x = %d \n", x);

    printf("x = %d \n", x--);
    printf("x = %d \n", x);

    // post increment
    int j = 1;
    printf("j = %d \n", ++j); // increase, then use
    printf("j = %d \n", --j);

    // while loop //
    int i = 1;
    while (i <= 5)
    {
        printf("Hello world\n");
        i++;
    }

    // Practice Question

    // 1) Print the numbers from 0 to n, if n is given by user (n = 4) ?
    int n;
    printf("Enter your number = ");
    scanf("%d", &n);

    // for (int i = 0; i <= n; i++)
    // {
    //     printf("%d \n", i);
    // }

    // (or)

    int num = 0;
    while (num <= n)
    {
        printf("%d \n", num);
        num++;
    }

    // do while loop //
    // 1)
    int num1 = 1;
    do
    {
        printf("number1 = %d\n", num1);
        num1++;
    } while (num1 <= 5);
    // 2)
    int num2 = 5;
    do
    {
        printf("number2 = %d\n", num2);
        num2--;
    } while (num2 >= 1);

    // Practice Questions

    // 1) a)Print the sum of First n natural numbers(n=4).
    //    b)Also,print them in reverse.

    // Ans)
    // a)
    int sum = 0;
    int userInput;
    printf("\nSUM OF N NATURAL NUMBERS");
    printf("\nEnter your input = ");
    scanf("%d", &userInput);

    for (int d = 1; d <= userInput; d++)
    {
        sum += d;
    }
    printf("Sum = %d\n", sum);
    // // b)
    int sum1 = 0;
    int userInput1;
    printf("\nSUM OF N NATURAL NUMBERS IN REVERSE");
    printf("\nEnter your input = ");
    scanf("%d", &userInput1);

    for (int d = userInput1; d >= 1; d--)
    {
        sum1 += d;
        printf("%d \n", d);
    }
    printf("Sum in reverse = %d\n", sum1);

    // Mixed both codes from above
    for (int i = 1, j = userInput1; i <= userInput && j >= 1; i++, j--)
    {
        sum += i;
        sum1 += j;
        printf("%d\n", j);
    }
    printf("Sum = %d \n", sum);
    printf("Sum1 = %d\n", sum1);

    // 2) Print the table of a number input by the user.(n=2)

    // Ans)
    int number;

    printf("MULTIPLICATION TABLE...");
    printf("\nEnter your number = ");
    scanf("%d", &number);

    for (int i = 1; i <= 10; i++)
    {
        printf("%d x %d = %d\n", number, i, number * i);
    }

    // Break Statement //
    for (int i = 1; i <= 5; i++)
    {
        if (i == 4)
        {
            break;
        }
        printf("%d\n", i);
    }
    printf("End");

    // Practice question
    /* 1) Keep taking numbers as input from user
    until user enters an odd number. */
    // Ans)
    printf("\nTASK : ENTER A ODD NUMBER...");
    int userInput2;
    do
    {
        printf("\nEnter your number = ");
        scanf("%d", &userInput2);
        printf("%d\n", userInput2);

        if (userInput2 % 2 != 0)
        {
            break;
        }

    } while (1);
    printf("GAME OVER");

    /* 2) Keep taking numbers as input from user until
    user enters a number which is multiple of 7. */
    // Ans)
    printf("\nTASK : ENTER A MULTIPLE OF 7");
    int userInput3;
    do
    {
        printf("\nEnter your number = ");
        scanf("%d", &userInput3);
        printf("%d\n", userInput3);

        if (userInput3 % 7 == 0)
        {

            break;
        }

    } while (1);
    printf("You guessed it right");
    printf("\nThanks for playing\n");

    // Continue Statement //
    for (int i = 1; i <= 5; i++)
    {
        if (i == 2)
        {
            continue; // 2 is not printed
        }
        printf("%d\n", i);
    }

    // Practice Questions

    // 3) Print all numbers 1 to 10 expect for 6.
    // Ans)
    for (int i = 1; i <= 10; i++)
    {
        if (i == 6)
        {
            continue;
        }
        printf(" i = %d\n", i);
    }

    // 4) Print all the odd numbers from 5 to 50.
    // Ans)
    for (int i = 5; i <= 50; i++)
    {
        if (i % 2 == 0)
        {
            continue;
        }
        printf("odd numbers from 5 to 50 = %d\n", i);
    }

    // 5) Print the factorial of a number n.
    // Ans)
    int factorial = 1;
    int input;
    printf("\nFACTORIAL OF A NUMBER...");
    printf("\nEnter your number = ");
    scanf("%d", &input);

    for (int i = 1; i <= input; i++)
    {
        factorial *= i;
    }
    printf("Factorial of your number = %d\n", factorial);

    // 6) Print reverse of the table for a number n.
    // Ans)
    int number2;
    printf("MULTIPLICATION TABLE IN REVERSE...");
    printf("\nEnter your number = ");
    scanf("%d", &number2);

    for (int i = 10; i >= 1; i--)
    {
        printf(" Reverse Table = %d\n", number * i);
    }

    /* 7) Calculate the sum of all numbers between
    5 and 50 (including 5 and 50).  */
    // Ans)
    int SUM = 0;
    printf("SUM FROM 5 TO 50...");

    for (int i = 5; i <= 50; i++)
    {
        SUM += i;
    }
    printf("\nSum is %d\n", SUM);

    return 0;
}