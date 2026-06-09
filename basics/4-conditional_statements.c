#include <stdio.h>
#include <math.h>

int main()
{
    // 1) if-else statements
    int age;
    printf("Enter age = ");
    scanf("%d", &age);

    if (age >= 18)
    {
        printf("You are eligible for driving license\n");
        printf("You can vote\n");
    }
    else
    {
        printf("You are not eligible for driving license\n");
    }
    // 2) elseif statements
    int grade;
    printf("Enter your Grade = ");
    scanf("%d", &grade);

    if (grade >= 90)
    {
        printf("Grade : A\n");
    }
    else if (grade >= 80)
    {
        printf("Grade : B\n");
    }
    else
    {
        printf("Grade : C or D\n");
    }

    // Conditional (or) ternary Operators
    int score = 90;
    score >= 80 ? printf("You won the match") : printf("Better luck next time");

    // Switch operator
    int day;
    printf("\nEnter day(1-7) : "); // 1-mon,2-tues,3-wed,4-thurs
    scanf("%d", &day);

    switch (day)
    {
    case 1:
        printf("Monday\n");
        break;
    case 2:
        printf("Tuesday\n");
        break;
    case 3:
        printf("Wednesday\n");
        break;
    case 4:
        printf("Thursday\n");
        break;
    case 5:
        printf("Friday\n");
        break;
    case 6:
        printf("Saturday\n");
        break;
    case 7:
        printf("Sunday\n");
        break;
    default:
        printf("It's not a valid number!\n");
    }

    // Nested statements
    int number;
    printf("Enter your number = ");
    scanf("%d", &number);

    if (number >= 0)
    {
        printf("Positive\n");
        if (number % 2 == 0)
        {
            printf("Even\n");
        }
        else
        {
            printf("Odd\n");
        }
    }
    else
    {
        printf("Negative\n");
    }

    // Practice Question
    // 1) Write a program to check if a student pass or fail ?
    // marks > 30 => PASS
    // marks <= 30 => FAIL

    // Ans)
    int marks;
    printf("CHECKING STUDENTS MARKS..");
    printf("\nEnter your marks(0-100): ");
    scanf("%d", &marks);

    if (marks > 30 && marks <= 100)
    {
        printf("PASS \n");
    }
    else if (marks <= 30)
    {
        printf("FAIL \n");
    }
    else
    {
        printf("Invalid marks\n");
    }

    // 2) Write a program to give grades to a student
    // marks < 30 is C
    // 30 <= marks < 70 is B
    // 70 <= marks < 90 is A
    // 90 <= marks <= 100 is A+
    int marksGrade;
    printf("\nCALCULATING GRADES OF STUDENT");
    printf("\nEnter your marks(0-100): ");
    scanf("%d", &marksGrade);

    if (100 >= marksGrade && 90 <= marksGrade)
    {
        printf("Grade : A+");
    }
    else if (70 <= marksGrade && 90 > marksGrade)
    {
        printf("Grade : A");
    }
    else if (30 <= marksGrade && 70 > marksGrade)
    {
        printf("Grade : B");
    }
    else
    {
        printf("Grade : C");
    }

    // 3) Write a program to find if a character entered by user is upper case or not ?

    // Ans)
    char userText;
    printf("\nFINDING CHARACTER TYPE..");
    printf("\nEnter your character = ");
    scanf("%c", &userText);

    if (userText >= 'A' && userText <= 'Z')
    {
        printf("This is a uppercase letter");
    }
    else if (userText >= 'a' && userText <= 'z')
    {
        printf("This is a lowercase letter");
    }
    else
    {
        printf("It's not a English letter");
    }

    // 4) Write a program to cheack if the given number is a natural number.

    // Ans)
    int naturalNum;
    printf("FINDING A NATURAL NUMBER..");
    printf("\nEnter your number = ");

    // Try to read a number
    if (scanf("%d", &naturalNum) != 1)
    {
        // If it fails (like when user types letters)
        printf("Invalid input! Please enter numbers only.\n");
        return 1; // stop program
    }

    if (naturalNum >= 1)
    {
        printf("It's a Natural number\n");
    }
    else if (naturalNum >= 0)
    {
        printf("It's a whole number\n");
    }
    else if (naturalNum < 0)
    {
        printf("It's a negative number\n");
    }

    // 4) Write a program to check if a given number is Armstrong number or not ?

    // Ex :- 153 => (1)pow3 + (5)pow3 + (3)pow3 = 1 + 125 + 27 = 153

    // Ans)
    int Angnumber, original, digit1, digit2, digit3, sum;

    printf("Enter a 3-digit number: ");
    scanf("%d", &Angnumber);

    original = Angnumber;

    digit1 = Angnumber % 10; // last digit
    Angnumber = Angnumber / 10;

    digit2 = Angnumber % 10; // middle digit
    Angnumber = Angnumber / 10;

    digit3 = Angnumber % 10; // first digit

    // Step 3: Cube and add
    sum = pow(digit1, 3) + pow(digit2, 3) + pow(digit3, 3);

    // Step 4: Check
    if (sum == original)
    {
        printf("%d is an Armstrong number \n", original);
    }
    else
    {
        printf("%d is NOT an Armstrong number \n", original);
    }

    return 0;
}