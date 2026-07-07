#include <stdio.h>
#define MAX 50

void readPoly(int coeff[], int expo[], int *n) {
    printf("Enter number of terms: ");
    scanf("%d", n);

    printf("Enter coefficient and exponent (in descending order):\n");
    for(int i = 0; i < *n; i++) {
        scanf("%d %d", &coeff[i], &expo[i]);
    }
}

void displayPoly(int coeff[], int expo[], int n) {
    for(int i = 0; i < n; i++) {
        printf("%dx^%d", coeff[i], expo[i]);
        if(i != n-1)
            printf(" + ");
    }
    printf("\n");
}

void displayPolySub(int coeff[], int expo[], int n) {
    for(int i = 0; i < n; i++) {
        printf("%dx^%d", coeff[i], expo[i]);
        if(i != n-1)
            printf(" ");
    }
    printf("\n");
}

int addPoly(int c1[], int e1[], int n1,
            int c2[], int e2[], int n2,
            int c3[], int e3[]) {

    int i = 0, j = 0, k = 0;

    while(i < n1 && j < n2) {
        if(e1[i] > e2[j]) {
            c3[k] = c1[i];
            e3[k++] = e1[i++];
        }
        else if(e1[i] < e2[j]) {
            c3[k] = c2[j];
            e3[k++] = e2[j++];
        }
        else {
            c3[k] = c1[i] + c2[j];
            e3[k++] = e1[i];
            i++; 
            j++;
        }
    }

    while(i < n1) {
        c3[k] = c1[i];
        e3[k++] = e1[i++];
    }

    while(j < n2) {
        c3[k] = c2[j];
        e3[k++] = e2[j++];
    }

    return k;   // number of terms in result
}

int subtractPoly(int c1[], int e1[], int n1,
                 int c2[], int e2[], int n2,
                 int c3[], int e3[]) {

    int i = 0, j = 0, k = 0;

    while(i < n1 && j < n2) {
        if(e1[i] > e2[j]) {
            c3[k] = c1[i];
            e3[k++] = e1[i++];
        }
        else if(e1[i] < e2[j]) {
            c3[k] = -c2[j];     // important change
            e3[k++] = e2[j++];
        }
        else {
            c3[k] = c1[i] - c2[j];
            e3[k++] = e1[i];
            i++; 
            j++;
        }
    }

    while(i < n1) {
        c3[k] = c1[i];
        e3[k++] = e1[i++];
    }

    while(j < n2) {
        c3[k] = -c2[j];   // important
        e3[k++] = e2[j++];
    }

    return k;
}

int main() {

    int c1[MAX], e1[MAX], n1;
    int c2[MAX], e2[MAX], n2;
    int c3[MAX], e3[MAX], n3;

    printf("Polynomial 1:\n");
    readPoly(c1, e1, &n1);

    printf("Polynomial 2:\n");
    readPoly(c2, e2, &n2);

    printf("\nPolynomial 1: ");
    displayPoly(c1, e1, n1);

    printf("Polynomial 2: ");
    displayPoly(c2, e2, n2);

    n3 = addPoly(c1, e1, n1, c2, e2, n2, c3, e3);
    printf("Sum: ");
    displayPoly(c3, e3, n3);

    n3 = subtractPoly(c1, e1, n1, c2, e2, n2, c3, e3);
    printf("Subtraction: ");
    displayPolySub(c3, e3, n3);

    return 0;
}