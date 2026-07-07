#include <stdio.h>
#define MAX 5

struct  CQUEUE {
	int arr[MAX];
	int front;
	int rear;
};

int isFull(struct CQUEUE *cq) {
	return ((cq->rear+1)%MAX == cq->front);
}

int isEmpty(struct CQUEUE *cq) {
	return (cq->front == -1 && cq->rear == -1);
}

void enqueue(struct CQUEUE *cq, int val) {
	if(isFull(cq))
		printf("Circular Queue overflow.\n");
	else {
		if(cq->front == -1)
			cq->front = 0;
		cq->rear = (cq->rear + 1) % MAX;
		cq->arr[cq->rear] = val;
	}
}

void dequeue(struct CQUEUE *cq) {
	if(isEmpty(cq))
		printf("Circular Queue underflow.\n");
	else {
		printf("Deleted Element = %d\n",cq->arr[cq->front]);
		if(cq->front == cq-> rear)
			cq->front = cq->rear = -1;
		else
		    // Increment
			cq->front = (cq->front + 1)%MAX;
	}
}

void display(struct CQUEUE *cq) {
	if(isEmpty(cq))
		printf("Circular Queue underflow.\n");
	else {
		printf("Elements of CQUEUE : ");
		for(int i = cq->front;; i = (i+1)%MAX) {
			printf("%d ",cq->arr[i]);
			if(i == cq->rear)
			    break;
	    }
		printf("\n");
	}
}

int main()
{
	struct CQUEUE cq;
	cq.front = -1,cq.rear = -1;
	int choice,val;
	while(1) {
		printf("\n_____CIRCULAR QUEUE FUNCTIONS_____\n");
		printf("Enter your choice :\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
		scanf("%d",&choice);
		switch(choice) {
		case 1 :
			printf("Enter your value : ");
			scanf("%d",&val);
			enqueue(&cq,val);
			break;
		case 2 :
			dequeue(&cq);
			break;
		case 3 :
			display(&cq);
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