#include <stdio.h>
#include <string.h>
// In strings => '\0' means null character

int main()
{
    // Initialing Strings
    char name1[] = {'t', 'h', 'a', 'r', 'u', 'n', '\0'};
    char name2[] = "\ndhanush\n";
    char marks[] = "marks of a student\n";
    printf(name1);
    printf(name2);
    printf(marks);

    // Entering name as input and printing output
    char name[50];
    printf("Enter your name = ");
    scanf("%s", name);
    printf("Your name is %s\n", name);

    // String format specifier
    char studentName[] = "Arjun Kapoor";
    printf("%s", studentName);
    char familyMember[40];
    printf("\nEnter a family member name = ");
    scanf("%s", familyMember);
    printf("New family member is %s", familyMember);

    // // String Functions
    // char str[100];
    // printf("\nEnter your text = ");
    // gets(str);              // this is unsafe
    // fgets(str, 100, stdin); // this is safe
    // puts(str);              // gets \n automatically

    // string using pointers
    char *canChange = "Hello World";
    puts(canChange);
    canChange = "Hello";
    puts(canChange);

    // Standard Libary Functions
    // 1) strLength (exclude '\0')
    char car[] = "buggati";
    int length = strlen(car);
    printf("Length of car is %d", length);
    // 2) strCopy
    char oldCar[] = "\ndiesel";
    char newCar[] = "\nbattery";
    strcpy(newCar, oldCar);
    puts(newCar);
    // 3) strCrastinate
    char bike1[100] = "bikes have strong engine ";
    char bike2[] = "with full speed";
    strcat(bike1, bike2);
    puts(bike1);
    // 4) strCompare
    // Ex-1)
    char firstStr[] = "Pineapple";
    char secondStr[] = "Banana";
    printf("Diff1 = %d\n", strcmp(firstStr, secondStr));
    // Ex-2)
    char strFirst[] = "HHHA";
    char strSecond[] = "HHHB";
    printf("Diff2 = %d\n", strcmp(strFirst, strSecond));
    // Ex-3)
    char str1[] = "AAA";
    char str2[] = "AAA";
    printf("Diff3 = %d\n", strcmp(str1, str2));
    // 5) strChar
    char *pointer = "Tharun";
    char ch = 'a';

    char *result = strchr(pointer, ch);

    if (result != NULL)
    {
        printf("Character '%c' is found at index : %ld\n", ch, (result - pointer));
    }
    else
    {
        printf("Character '%c' is not found", ch);
    }

    return 0;
}

// Practice Questions
/* 1) Create a String firstName and lastName to store details of
user and print all characters using a loop.*/
// Ans)
void printName(char arr[]);

// int main()
// {
//     char firstName[40];
//     char lastName[40];
//     printf("\nEnter first and last names = ");
//     scanf("%s%s", firstName, lastName);

//     printName(firstName);
//     printName(lastName);

//     return 0;
// }

void printName(char arr[])
{
    for (int i = 0; arr[i] != '\0'; i++)
    {
        printf("%c", arr[i]);
    }
    printf("\n");
}

/* 2) Make a program that input user's name and
print it's length.*/
// Ans)
void printString(char arr[]);
int countLength(char arr[]);

// int main()
// {
//     char name[100];
//     printf("Enter your name = ");
//     fgets(name, 100, stdin);
//     printf("Name length is %d", countLength(name));

//     return 0;
// }

int countLength(char arr[])
{
    int count = 0;
    for (int i = 0; arr[i] != '\0'; i++)
    {
        count++;
    }
    return count - 1;
}

void printString(char arr[])
{
    for (int i = 0; arr[i] != '\0'; i++)
    {
        printf("%s", arr[i]);
    }
    printf("\n");
}

// 3) Take a string input from the user using %c.
// Ans)

// void main()
// {
//     char str[100];
//     char ch;
//     int i = 0;
//     printf("Enter your text = ");

//     while (ch != '\n')
//     {
//         scanf("%c", &ch);
//         str[i] = ch;
//         i++;
//     }
//     str[i] = '\0';
//     printf("Your text is ");
//     puts(str);
// }

/* 4) Find a salted form of a password entered by user
if the salt is "123" and added at the end. */
// Ans)
void salting(char password[]);

// void main()
// {
//     char password[100];
//     printf("\nEnter your password = ");
//     scanf("%s", password);
//     printf("New password is ");
//     salting(password);
// }

void salting(char password[])
{
    char salting[] = "123";
    char newPass[100];
    strcpy(newPass, password); // newPass = "text"
    strcat(newPass, salting);  // newPass = "text" + "123"
    puts(newPass);
}

/* 5) Write a function named slice,which takes a string
and returns a sliced string from index n to m.*/
// Ans)
void slice(char arr[], int n, int m);

// void main()
// {
//     char str[100];
//     printf("Enter a word = ");
//     scanf("%s", str);
//     printf("Slice word is ");
//     slice(str, 3, 6);
// }

void slice(char arr[], int n, int m)
{
    char newArr[100];
    int j = 0;
    for (int i = n; i <= m; i++, j++)
    {
        newArr[j] = arr[i];
    }
    newArr[j] = '\0';
    puts(newArr);
}

/* 6) Write a function to count the
occurence of vowels in a string. */
// Ans)
int countVowels(char str[]);

// void main()
// {
//     char str[100];
//     printf("Enter your text = ");
//     scanf("%s", str);
//     printf("Number of vowels = %d", countVowels(str));
// }

int countVowels(char str[])
{
    int count = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u')
        {
            count++;
        }
    }
    return count;
}

/* 7) Check if a given character is present in a string or not. */
// Ans)
// void main()
// {
//     char *str;
//     printf("Enter your text = ");
//     scanf("%s", str);
//     char ch = 'a';

//     char *result = strchr(str, ch);

//     if (result != NULL)
//     {
//         printf("yes\n");
//         printf("Character '%c' is present\n", ch);
//     }
//     else
//     {
//         printf("no\n");
//         printf("Character '%c' is not present\n", ch);
//     }
// }