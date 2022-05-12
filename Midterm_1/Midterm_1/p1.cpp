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
	double distance = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2)); //두 좌표 사이의 거리
	return distance;
}

int main()
{
	int cnt = 0; // data의 라인 수를 카운트
	FILE * fp = fopen("data01.txt", "r");

	if (fp == NULL) {
		printf("File not found\n");
		exit(1);
	}

	char space;

	while (!feof(fp)) {
		fscanf(fp, "%c", &space); //읽은 기호가 줄바꿈이면 cnt를 증가
		if (space == '\n')
			cnt++;
	}

	
	POINT *p = (POINT*)malloc(sizeof(POINT)*(cnt+1));   //라인 수 만큼 동적 할당

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
			printf("(%d, %d)와 (%d, %d)의 사이 거리는 %.5f 입니다.\n", p[i].x, p[i].y, p[j].x, p[j].y,
				distance(p[i].x, p[i].x, p[j].x, p[j].x));
			k++;
		}
	}


	fclose(fp);
	free(p);
	return 0;
}