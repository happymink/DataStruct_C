#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


#define MAX_QUEUE_SIZE 100


typedef struct {
	int nNum;
	char name[100];
} QueueObject;

QueueObject queue[MAX_QUEUE_SIZE];
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

void addq(QueueObject item)
{
	if (isFull()) {
		printf("queue is Full\n");
		exit(1);
	}
	rear = (rear + 1) % MAX_QUEUE_SIZE;
	queue[rear] = item;
}

QueueObject deleteq()
{
	if (isEmpty()) {
		printf("queue is empty\n");
		exit(0);
	}
	front = front + 1 % MAX_QUEUE_SIZE;
	return queue[front];
}

int get_count(QueueObject *q)
{
	int i, j, count = 0;
	if (isEmpty()) {
		return count;
	}
	if(q)
}

int main()
{
	QueueObject queue;
	initialize();
	FILE *fp;
	int temp;
	int i = 0;
	int nCount = 1;

	fp = fopen("data.txt", "r");

	if (fp == NULL) {
		printf("file not open\n");
		exit(1);
	}

	while (!feof(fp))
	{
		fscanf(fp, "%d", &temp);
		addq(temp);
		nCount++;
	}

	for (i = 0; i < nCount - 1; i++) {
		printf("%d -> ", deleteq());
	}

	fclose(fp);
	return 0;
}