#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
/*실습 문제 2번

 복습 다시 제대로 해서 문제 3번 공부하겠습니다..

 */

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

void addq(int item, int nCount)
{
	int i = 0;
	if (isFull()) {
		printf("queue is Full\n");
		exit(1);
	}
	for (i = nCount - 1; i >= 0; i--) {
		if (item < queue[i])
			queue[i + 1] = queue[i];
		else
			break;
	}
	queue[i + 1] = item;
	rear = (rear + 1) % MAX_QUEUE_SIZE;
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
	int nCount = 1;

	fp = fopen("data.txt", "r");

	if (fp == NULL) {
		printf("file not open\n");
		exit(1);
	}

	while (!feof(fp))
	{
		fscanf(fp, "%d", &temp);
		addq(temp, nCount);
		nCount++;
	}

	for (i = 0; i < nCount - 1; i++) {
		printf("%d -> ", deleteq());
	}

	fclose(fp);
	return 0;
}