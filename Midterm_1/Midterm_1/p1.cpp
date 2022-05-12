#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct  POINT{
	double x;
	double y;
}POINT;

double distance(double x1, double y1, double x2, double y2) 
{
	double distance = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2)); //�� ��ǥ ������ �Ÿ�
	return distance;
}

int main()
{
	int cnt = 0; // data�� ���� ���� ī��Ʈ
	FILE * fp = fopen("data01.txt", "r");

	if (fp == NULL) {
		printf("File not found\n");
		exit(1);
	}

	char space;

	while (!feof(fp)) {
		fscanf(fp, "%c", &space); //���� ��ȣ�� �ٹٲ��̸� cnt�� ����
		if (space == '\n')
			cnt++;
	}

	
	POINT *p = (POINT*)malloc(sizeof(POINT)*(cnt+1));   //���� �� ��ŭ ���� �Ҵ�

	int i = 0;

	//rewind(fp);
	//fseek(fp, 0, SEEK_SET);
	while (!feof(fp)) {
		fscanf(fp, "%lf %lf",p[i].x, p[i].y);
		i++;
	}

	int k = 1;
	for (int i = 0; i < cnt; i++)
	{
		
		for (int j = i+1; j <= cnt; j++)
		{
			printf("%d. ", k);
			printf("(%d, %d)�� (%d, %d)�� ���� �Ÿ��� %.5f �Դϴ�.\n", p[i].x, p[i].y, p[j].x, p[j].y,
				distance(p[i].x, p[i].x, p[j].x, p[j].x));
			k++;
		}
	}


	fclose(fp);
	free(p);
	return 0;
}