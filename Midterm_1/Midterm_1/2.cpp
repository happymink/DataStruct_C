#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void func(int num) {
	int cnt = 0;
	int sum = 0;
	if (num % 2 == 0) //¦��
	{
		for (int i = 0; i <= num; i += 2) {
			sum += i;
			cnt++;
		}

	}
	if (num % 2 == 1) //Ȧ��
	{
		for (int i = 1; i <= num; i += 2) {
			sum += i;
			cnt++;
		}

	}
		
	printf("�Էµ� �� : %d\n",num);
	printf("���� Ƚ�� : %d\n", cnt);
	printf("���� �� : %d\n", sum);
}

int main()
{
	int arr[1000];
	FILE * fp = fopen("data01.txt", "r");

	if (fp == NULL) {
		printf("File not found\n");
		exit(1);
	}

	int cnt = 0;
	while (!feof(fp)) {
		fscanf(fp, "%d", &arr[cnt]);
		cnt++;
	}

	for (int i = 0; i < cnt; i++)
	{
		func(arr[i]);
	}

	fclose(fp);
	
	return 0;
}