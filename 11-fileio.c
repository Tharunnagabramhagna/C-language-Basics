#include <stdio.h>

void main()
{
    // File pointer //
    FILE *fptr;
    fptr = fopen("test.txt", "r");
    if (fptr != NULL)
    {
        printf("Hello World\n");
    }
    else
    {
        printf("file doesn't exist\n");
    }

    // File Opening Modes //
    // 1) "r" => open to read
    // 2) "rb" => open to read in binary
    // 3) "w" => open to write
    // 4) "wb" => open to write in binary
    // 5) "a" => open to append

    FILE *fptr0;
    fptr0 = fopen("Newtest.txt", "r");
    if (fptr0 == NULL)
    {
        printf("Newtest.txt file doesn't exist\n");
    }
    else
    {
        fclose(fptr0);
    }

    // Reading from a file //
    // Ex-1)
    printf("\nPRINTING WHOLE TEXT IN test.txt..\n\n");
    for (int i = 0; i < 1090; i++)
    {
        char ch;
        fscanf(fptr, "%c", &ch);
        printf("%c", ch);
    }
    fclose(fptr);
    // Ex-2)
    FILE *fptr1;
    fptr1 = fopen("test0.txt", "r");
    printf("\n");
    printf("\nPRINTING NUMBERS IN FILE...\n");
    printf("Random numbers = ");
    for (int i = 0; i < 10; i++)
    {
        int var;
        fscanf(fptr1, "%d", &var);
        printf("%d\t", var);
    }
    fclose(fptr1);

    // Writing to a file //
    fptr1 = fopen("test0.txt", "a");
    fprintf(fptr1, "%c", 'M');
    fprintf(fptr1, "%c", 'A');
    fprintf(fptr1, "%c", 'N');
    fprintf(fptr1, "%c", 'G');
    fprintf(fptr1, "%c", 'O');
    fclose(fptr1);

    // Read and write a char //
    FILE *fptr2;
    fptr2 = fopen("test1.txt", "r");
    printf("\n");
    printf("character = %c\n", fgetc(fptr2));
    printf("character = %c\n", fgetc(fptr2));
    printf("character = %c\n", fgetc(fptr2));
    printf("character = %c\n", fgetc(fptr2));
    printf("character = %c\n", fgetc(fptr2));
    fptr2 = fopen("test1.txt", "a");
    fputc('M', fptr2);
    fputc('A', fptr2);
    fputc('N', fptr2);
    fputc('G', fptr2);
    fputc('O', fptr2);
    fclose(fptr2);

    // EOF (End of file) //
    // fgetc returns EOF to show that the file has ended.
    FILE *fptr3;
    fptr3 = fopen("test2.txt", "r");
    char ch;
    ch = fgetc(fptr3);
    while (ch != EOF)
    {
        printf("%c", ch);
        ch = fgetc(fptr3);
    }
    printf("\n");
    fclose(fptr3);

    // Practice Questions //
    /* 1) Make a program to read 5 integers from a file.*/
    // Ans)
    FILE *fptr4;
    fptr4 = fopen("test3.txt", "r");
    for (int i = 0; i < 5; i++)
    {
        int n;
        fscanf(fptr4, "%d", &n);
        printf("Integer = %d\n", n);
    }
    fclose(fptr4);

    // /* 2) Make a program to input student information
    // from a user and enter it to a file.*/
    // // Ans)
    FILE *fptr5;
    fptr5 = fopen("Student.txt", "w");

    char name[100];
    int age;
    float cgpa;
    printf("Enter name,age and cgpa = ");
    scanf("%s%d%f", name, &age, &cgpa);
    fprintf(fptr5, "STUDENT INFO :\n%s\t%d\t%.1f\n", name, age, cgpa);
    fclose(fptr5);

    /* 3) Write a program to write all the odd
    numbers from 1 to n in a file.*/
    // Ans)
    FILE *fptr6;
    fptr6 = fopen("Odd.txt", "w");

    int n;
    printf("Enter number = ");
    scanf("%d", &n);

    for (int i = 0; i <= n; i++)
    {
        if (i % 2 != 0)
        {
            fprintf(fptr6, "%d\t", i);
        }
    }

    /* 4) 2 numbers - a & b,are written in a file. Write
    a program to replace them with their sum. */
    // Ans)
    FILE *fptr7;
    fptr7 = fopen("sum.txt", "r");
    // inputs (should enter in file)
    int a, b;
    fscanf(fptr7, "%d%d", &a, &b);
    // closing
    fclose(fptr7);
    // re-open with write mode
    fptr7 = fopen("sum.txt", "w");
    fprintf(fptr7, "%d", a + b);
    fclose(fptr7);
}