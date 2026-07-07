#include <stdio.h>
#include <stdlib.h>

typedef struct {
	float coeff;
	int expo;
} Term;
typedef struct {
	int n;
	Term *t;
} Poly;

void create(Poly *p) {
	printf("Enter the number of terms : ");
	scanf("%d",&p->n);
	p->t = (Term *)malloc(p->n * sizeof(Term));
	printf("Enter terms (coefficient and exponent :\n");
	for(int i = 0; i < p->n; i++)
		scanf("%f%d",&p->t[i].coeff,&p->t[i].expo);
}

void display(Poly p) {
	for(int i = 0; i < p.n; i++) {
		printf("%.1fx^%d",p.t[i].coeff,p.t[i].expo);
		if(i < p.n-1)
		printf(" + ");
	}
	printf("\n");
}

void displaySub(Poly p) {
        for(int i = 0; i < p.n; i++) {
                printf("%.1fx^%d",p.t[i].coeff,p.t[i].expo);
                if(i < p.n-1)
                printf(" ");
        }
        printf("\n");
}

Poly add(Poly *p1, Poly *p2) {
	Poly sum;
	sum.t = (Term *)malloc((p1->n + p2->n)*sizeof(Term));
	int i = 0, j = 0, k = 0;
	while (i < p1->n && j < p2->n) {
		if(p1->t[i].expo > p2->t[j].expo)
			sum.t[k++] = p1->t[i++];
		else if(p1->t[i].expo < p2->t[j].expo)
			sum.t[k++] = p2->t[j++];
		else {
			sum.t[k].expo = p1->t[i].expo;
			sum.t[k++].coeff = p1->t[i++].coeff + p2->t[j++].coeff;
		}
	}
	for(; i < p1->n; i++) sum.t[k++] = p1->t[i];
	for(; j < p2->n; j++) sum.t[k++] = p2->t[j];
	sum.n = k;
	return sum;
}

Poly subtract(Poly *p1, Poly *p2) {
	Poly sub;
	sub.t = (Term *)malloc((p1->n + p2->n)*sizeof(Term));
	int i = 0, j = 0, k = 0;
	while (i < p1->n && j < p2->n) {
                if(p1->t[i].expo > p2->t[j].expo)
                        sub.t[k++] = p1->t[i++];
                else if(p1->t[i].expo < p2->t[j].expo)
                        sub.t[k++] = p2->t[j++];
                else {
                        sub.t[k].expo = p1->t[i].expo;
                        sub.t[k++].coeff = p1->t[i++].coeff - p2->t[j++].coeff;
                }
        }
        for(; i < p1->n; i++) sub.t[k++] = p1->t[i];
        for(; j < p2->n; j++) sub.t[k++] = p2->t[j];
        sub.n = k;
        return sub;
}

int main() {
	Poly p1,p2,p3;
	printf("Polynomial 1 :\n");
	create(&p1);
	printf("Polynomial 2:\n");
	create(&p2);
	p3 = add(&p1,&p2);
	printf("\nPoly 1 : ");
	display(p1);
	printf("Poly 2 : ");
	display(p2);
	printf("Sum : ");
	display(p3);
	p3 = subtract(&p1,&p2);
        printf("Sub : ");
        displaySub(p3);
	free(p1.t);
	free(p2.t);
	free(p3.t);
	return 0;
}