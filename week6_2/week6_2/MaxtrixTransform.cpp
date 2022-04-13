#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

int main()
{
	int nAr[SIZE][SIZE];
	int TransAr[SIZE][SIZE];

	int nTemp;
	char chTemp = '0';
	int nCount = 0;
	int nRow = 0;
	FILE *fp = fopen("data.txt", "r");

	if (fp == NULL) {
		printf("file not open\n");
		return 0;
	}
	
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			nAr[i][j] = -1;
			TransAr[i][j] = -1;
		}
	}
	// 1  2   3	 4	5
	// 6  7	  8  9	10
	// 11 12 13 14  15 
	//���� ���� ���ϱ�
	while (!feof(fp)) {
		if (chTemp == '\n')
			break;
		fscanf(fp, "%d%c", &nTemp, &chTemp);
		nCount++;
	}

	rewind(fp);
	
	// ���� ��� 2���� �迭�� ���� ������ �Է�
	while (!feof(fp)) {
		for (int i = 0; i < nCount; i++) {
			fscanf(fp, "%d", &nAr[nRow][i]);
		}
		nRow++;
	}

	printf("���� ����� ���\n");
	for (int i = 0; i < nRow; i++) {
		for (int j = 0; j < nCount; j++) {
			printf("%d\t", nAr[i][j]);
		}
		printf("\n");
	}


	//��ġ��� ��ȯ
	for (int i = 0; i < nRow; i++) {
		for (int j = 0; j < nCount; j++) {
			TransAr[j][i] = nAr[i][j];
		}
	}
	printf("��ġ ����� ���\n");
	for (int i = 0; i < nCount; i++) {
		for (int j = 0; j < nRow; j++) {
			printf("%d\t", TransAr[i][j]);
		}
		printf("\n");
	}

	return 0;
}
