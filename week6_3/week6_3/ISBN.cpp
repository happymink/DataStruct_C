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
	int nISBN[13]; // 13자리 규격
	int nCount = 0;
	int nResult = 0;
	FILE *fp = fopen("data.txt", "r");

	if (fp == NULL) {
		printf("file not open\n");
		return 0;
	}

	while (!feof(fp)) {
		if (nCount > 13) {
			printf("ISBN 코드는 13자리입니다.\n");
			return 0;
		}

		fscanf(fp, "%d", &nISBN[nCount]);
		nCount++;

	}

	nResult = IS_ISBN(nISBN);

	for (int i = 0; i < 13; i++)
		printf("%d", nISBN[i]);

	if (nResult == -1)
		printf("은 유효하지 않은 코드입니다.\n");
	else if (nResult == 1)
		printf("은 유효한 코드입니다.\n");


	return 0;
}