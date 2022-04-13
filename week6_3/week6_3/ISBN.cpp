#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int IS_ISBN(int ar[])
{
	int nSum = 0;

	for (int i = 0; i < 13; i++) {
		if (i % 2 == 1)
			nSum += ar[i] * 3;
		else
			nSum += ar[i];
	}

	if (nSum % 10 == 0)
		return 1;
	else 
		return -1;
}

int main()
{
	int nISBN[13]; // 13�ڸ� �԰�
	int nCount = 0;
	int nResult = 0;
	FILE *fp = fopen("data.txt", "r");

	if (fp == NULL) {
		printf("file not open\n");
		return 0;
	}

	while (!feof(fp)) {
		if (nCount > 13) {
			printf("ISBN �ڵ�� 13�ڸ��Դϴ�.\n");
			return 0;
		}

		fscanf(fp, "%d", &nISBN[nCount]);
		nCount++;

	}

	nResult = IS_ISBN(nISBN);

	for (int i = 0; i < 13; i++)
		printf("%d", nISBN[i]);

	if (nResult == -1)
		printf("�� ��ȿ���� ���� �ڵ��Դϴ�.\n");
	else if (nResult == 1)
		printf("�� ��ȿ�� �ڵ��Դϴ�.\n");


	return 0;
}