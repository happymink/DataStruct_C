#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable : 4996)
#define MONTH 12
#define YEAR 8
int main(void)
{
	//행 :연도 | 열 : 월
	int Yeardata[YEAR][MONTH] = { 0 };
	int nCount = 0;
	int YearSum[YEAR] = { 0 }; //연도 별 총합
	int MonthSum[MONTH] = { 0 }; //월별 총합

	// file open 
	FILE* fp;
	fp = fopen("data.txt", "r");

	// file null check
	if (fp == NULL) {
		printf("file not open\n");
		return 0;
	}

	while (!feof(fp)) { //data 파일 읽어서 배열에 저장
		fscanf(fp, "%d%d%d%d%d%d%d%d%d%d%d%d",
			&Yeardata[nCount][0],
			&Yeardata[nCount][1],
			&Yeardata[nCount][2],
			&Yeardata[nCount][3],
			&Yeardata[nCount][4],
			&Yeardata[nCount][5],
			&Yeardata[nCount][6],
			&Yeardata[nCount][7],
			&Yeardata[nCount][8],
			&Yeardata[nCount][9],
			&Yeardata[nCount][10],
			&Yeardata[nCount][11]);
		nCount++;
	}

	fclose(fp); //file pointer close
	printf("\n|========================================================================================|\n");
	printf("|년도  | 1월 | 2월 | 3월 | 4월 | 5월 | 6월 | 7월 | 8월 | 9월 | 10월| 11월| 12월|년별총합 |\n");

	for (int i = 0; i < YEAR; i++) {
		printf("|%d년|", 2000 + i);
		for (int j = 0; j < MONTH; j++) {
			printf(" %3d |", Yeardata[i][j]);
			YearSum[i] += Yeardata[i][j];
		}
		printf("%6d   |\n", YearSum[i]);
	}

	for (int i = 0; i < MONTH; i++) {
		for (int j = 0; j < YEAR; j++) {
			MonthSum[i] += Yeardata[j][i];
		}
	}

	printf("|========================================================================================|\n");
	printf("|월별평|");
	for (int i = 0; i < MONTH; i++) {
		printf("%4d |", (MonthSum[i]/YEAR));
	}
	printf("\n|==============================================================================|\n");
	return 0;
}