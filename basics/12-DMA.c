// DMA => Dynamic Memory Allocation
#include <stdio.h>
#include <stdlib.h>

void main()
{
    // Functions of DMA //

    // 1) malloc()
    int *ptr;
    ptr = (int *)malloc(5 * sizeof(int)); // 20 bytes memory

    ptr[0] = 2;
    ptr[1] = 4;
    ptr[2] = 6;
    ptr[3] = 8;
    ptr[4] = 10;

    printf("EVEN NUMBERS FROM 1 TO 10..\n");
    for (int i = 0; i < 5; i++)
    {
        printf("%d\n", ptr[i]);
    }

    // 2) calloc()
    float *cptr;
    cptr = (float *)calloc(5, sizeof(float));
    printf("PRINTING NULL VALUES..\n");
    for (int i = 0; i < 5; i++)
    {
        printf("%f\n", cptr[i]);
    }
    /* Here,malloc may return garbage values if we provide no data
    but calloc always return NULL values if we provide no data. */

    // 3) free()
    free(cptr);
    cptr = (float *)calloc(2, sizeof(float));
    printf("CHANGE IN CPTR BY FREE()..\n");
    cptr[0] = 10;
    cptr[1] = 20;
    for (int i = 0; i < 2; i++)
    {
        printf("%.2f\n", cptr[i]);
    }

    // Practice Questions //
    /* 1) Write a program to allocate memory to store 5 prices.*/
    // Ans)
    float *ptrPrice;
    ptrPrice = (float *)malloc(5 * sizeof(float));

    ptrPrice[0] = 120;
    ptrPrice[1] = 79;
    ptrPrice[2] = 49.97;
    ptrPrice[3] = 89.97;
    ptrPrice[4] = 56.98;

    for (int i = 0; i < 5; i++)
    {
        printf("Price[%d] = %.2f\n", i, ptrPrice[i]);
    }

    /* 2) Write a program to allocate memory of size n,
    where n is entered by the user. */
    // Ans)
    int *cptr1;
    int n;
    printf("ENter n = ");
    scanf("%d", &n);

    cptr1 = (int *)calloc(5, sizeof(int));

    for (int i = 0; i < n; i++)
    {
        printf("%d\n", cptr1[i]);
    }

    /* 3) Allocate memory for 5 numbers.Then dynamically
    increase it to 8 numbers. */
    // Ans)
    // includes realloc() function
    int *ptrn;
    ptrn = (int *)calloc(5, sizeof(int));

    printf("Enter five numbers : ");
    for (int i = 0; i < 5; i++)
    {
        scanf("%d", &ptrn[i]);
    }

    printf("\nAFTER REALLOCATING..\n");
    ptrn = (int *)realloc(ptrn, 8);
    printf("Enter eight numbers : ");
    for (int i = 0; i < 8; i++)
    {
        scanf("%d", &ptrn[i]);
    }

    // output
    printf("PRINTING 8 NUMBERS :\n");
    for (int i = 0; i < 8; i++)
    {
        printf("number[%d] = %d\n", i, ptrn[i]);
    }

    /* 4) Create an array of size 5(using calloc) and enter
    it's values from the user. */
    // Ans)
    int *ptra;
    ptra = (int *)calloc(5, sizeof(int));

    // input
    printf("Enter numbers (5) : ");
    for (int i = 0; i < 5; i++)
    {
        scanf("%d", &ptra[i]);
    }

    // output
    for (int i = 0; i < 5; i++)
    {
        printf("Number %d is %d\n", i, ptra[i]);
    }

    /* 5) Allocate memory to store first 5 odd numbers,then
    reallocate it to store first 6 even number. */
    // Ans)
    int *ptrOdd;
    ptrOdd = (int *)calloc(5, sizeof(int));

    // input-1)
    ptrOdd[0] = 1;
    ptrOdd[1] = 3;
    ptrOdd[2] = 5;
    ptrOdd[3] = 7;
    ptrOdd[4] = 9;

    // output-1)
    printf("\nTHE FINAL DATA :\n");
    printf("Numbers = ");
    for (int i = 0; i < 5; i++)
    {
        printf("%d\t", ptrOdd[i]);
    }

    // reallocting
    ptrOdd = (int *)realloc(ptrOdd, 6);

    // input-2)
    ptrOdd[0] = 2;
    ptrOdd[1] = 4;
    ptrOdd[2] = 6;
    ptrOdd[3] = 8;
    ptrOdd[4] = 10;
    ptrOdd[5] = 12;

    // output - 2)
    for (int i = 0; i < 6; i++)
    {
        printf("%d\t", ptrOdd[i]);
    }
    free(ptrOdd);
}