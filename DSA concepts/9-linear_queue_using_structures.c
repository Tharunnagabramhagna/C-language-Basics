#include <stdio.h>
#define MAX 5

struct QUEUE {
	int arr[MAX];
	int front;
	int rear;
};

int isFull(struct QUEUE *q) {
	return (q->rear == MAX - 1);
}

int isEmpty(struct QUEUE *q) {
	return (q->front == -1);
}

void enqueue(struct QUEUE *q, int val) {
	if(isFull(q))
		printf("Queue overflow.\n");
	else {
		if(q->front == -1)
			q->front = 0;
		q->arr[++q->rear] = val;
	}
}

void dequeue(struct QUEUE *q) {
	if(isEmpty(q))
		printf("Queue underflow.\n");
	else {
		printf("Deleted Element = %d\n",q->arr[q->front++]);
		if(q->front > q-> rear)
			q->front = q->rear = -1;
	}
}

void display(struct QUEUE *q) {
	if(isEmpty(q))
		printf("Queue underflow.\n");
	else {
		printf("Elements of QUEUE : ");
		for(int i = q->front; i <= q->rear; i++)
			printf("%d ",q->arr[i]);
		printf("\n");
	}
}

int main()
{
	struct QUEUE q;
	q.front = -1;
	q.rear = -1;
	int choice,val;
	while(1) {
		printf("\n_____QUEUE FUNCTIONS_____\n");
		printf("Enter your choice :\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
		scanf("%d",&choice);
		switch(choice) {
		case 1 :
			printf("Enter your value : ");
			scanf("%d",&val);
			enqueue(&q,val);
			break;
		case 2 :
			dequeue(&q);
			break;
		case 3 :
			display(&q);
			break;
		case 4 :
			printf("Exiting the queue.\n");
			return 0;
		default :
			printf("Invalid Choice.\n");
		}
	}
	return 0;
}