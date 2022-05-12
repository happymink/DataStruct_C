#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


#define MAX_QUEUE_SIZE 100


int queue[MAX_QUEUE_SIZE];
int front, rear;

void initialize()
{
	front = rear = 0;
}

int isEmpty()
{
	return (front == rear);
}

int isFull()
{
	return ((rear + 1) % MAX_QUEUE_SIZE == front);
}

int addq(int item)
{
	if (isFull()) {
		printf("queue is full \n");
		exit(0);
	}
	rear = rear + 1 % MAX_QUEUE_SIZE;
	queue[rear] = item;
}

int deleteq()
{
	if (isEmpty()) {
		printf("queue is empty\n");
		exit(0);
	}
	front = front + 1 % MAX_QUEUE_SIZE;
	return queue[front];
}

int main()
{
	FILE *fp;
	int temp;
	int i = 0;
	int nCount = 0;
	
	fp = fopen("data.txt", "r");

	if (fp == NULL) {
		printf("file not open\n");
		exit(1);
	}
	
	while (!feof(fp))
	{
		fscanf(fp, "%d", &temp);
		addq(temp);
		printf("front = %d rear = %d addq(%d) \n", front, rear, temp);
		nCount++;
	}

	for (i = 0; i < nCount; i++) {
		printf("front = %d rear = %d deleteq(%d) \n", front, rear, deleteq());
	}
	printf("front = %d rear = %d \n", front, rear);

	fclose(fp);
	return 0;
}