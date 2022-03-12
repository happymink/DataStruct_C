////////////////////////////////////////////////////////////////
//
// 작성자 : 이민균	
// 작성일 : 2022년 03월 12일
// 프로그램명 : 파일입출력을 이용한 사용자 정의 n개의 데이터 출력 및 최대값,최소값 출력
// 프로그램설명 : 파일입출력을 통해 사용자가 임의로 정한 개수만큼 데이터를 출력함과 동시에 최대값과 최소값을 판별한다.
//					
//
////////////////////////////////////////////////////////////////

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

////////////////////////////////////////////////////////////////
//
// 작성자 : 이민균
// 작성일 : 2022년 03월 12일
// 함수명 : print_list , print_line
// 함수설명 :	 data.txt의 첫 라인 수 만큼의 목차를 출력하고 라인을 그린다.
// 함수입력: int n
// 함수출력: void형 printf 반복문
////////////////////////////////////////////////////////////////

void print_list(int n) {
	printf("%d개의 데이터 만큼씩 한줄에 출력 \n\n", n);
	for (int i = 1; i <= n; i++) {
		printf("%8d", i);
	}
	for (int i = 0; i < n; i++) {
		printf("========");
	}
}

void print_line(int n) {
	for (int i = 0; i < n; i++) {
		printf("--------");
	}
}


int main()
{
	int arr[10000] = {};			// data.txt에서 데이터를 읽은 후 저장 할 정수형 배열 선언
	int check[10000] = { 0 };		// 위의 배열 arr[]에 저장 된 값들의 최대 최소를 판별하기 위한 정수형 배열 선언
									// 0 = 기본, 1 = 최대값, 2 = 최소값

	char c_max[20] = "최대값";		//문자열 자릿수를 맞추기 위한 char 배열 1
	char c_min[20] = "최소값";		//문자열 자릿수를 맞추기 위한 char 배열 2
	char c_space[20] = "     ";		//문자열 자릿수를 맞추기 위한 char 배열 3

	FILE *fp;						// 파일포인터 변수선언
	int max, min;					//data.txt 데이터 중에서 최대 최소값을 저장할 정수형 변수
	int out_num;					//한 라인에 출력할 정수의 개수를 저장하는 변수
	int cnt = 1;					//data.txt의 총 정수의 갯수를 카운트하는 변수

	fp = fopen("data.txt", "r");	// data.txt파일을 읽기모드로 열어 생성된 FILE구조체를 fp에 할당
	if (fp == NULL)					// 만약 fopen함수에서 에러가 발생하여 fp에 NULL값이 저장되었다면 파일열기실패
	{
		printf("파일이 열리지 않았습니다.\n");
		return 0;					// 메세지 출력하고 프로그램 종료
	}

	fscanf(fp, "%d", &out_num);		//data.txt 에서 첫 줄을 읽어  out_num에 저장 (한 라인에 출력할 정수의 개수를 저장하는 변수)
	fscanf(fp, "%d", &arr[0]);		//초기 max, min 초기화를 위해 배열의 첫 번째 수를 따로 저장

	max = arr[0];					//최대값과 최소값을 배열의 첫 번째 요소로 지정
	min = arr[0];

	while (!feof(fp))	// 파일포인터가 파일의 끝을 가르킬때까지 반복한다.
	{
		fscanf(fp, "%d", &arr[cnt]);	// 파일에서 정수형 값을 읽고
		if (arr[cnt] > max) { max = arr[cnt]; }	// 읽은 값을 기존의 max, min와 비교하여 최신화
		if (arr[cnt] < min) { min = arr[cnt]; }
		cnt++;		//data.txt의 총 정수의 갯수 카운트
	}

	print_list(out_num);	// data.txt의 첫 라인 수 만큼의 목차를 출력 

	int k = 0;		//배열의 순서를 제어하기 위한 변수 k, g 초기화
	int g = 0;

	for (int j = 0; j < (cnt / out_num) + 1; j++) {		// (data.txt 에서 읽은 총 데이터의 갯수 / 한 라인에 출력할 데이터의 갯수) + 1 만큼 반복
		if (k == cnt) { break; }
		for (int i = 0; i < out_num; i++) {				//	1.  한 라인의 출력할 데이터의 갯수 만큼 반복
			if (arr[k] == max) { check[k] = 1; }		//	2.  만약 arr[k]가 최대값 혹은 최소값이라면 배열 check[k] 수정  
			else if (arr[k] == min) { check[k] = 2; }	//											 :: 기본 = 0, 최대값 = 1, 최소값 = 2 
			printf("%8d", arr[k]);						//	3.  arr[k] 출력 후 k값 1 증가
			k++;
			if (k == cnt) { printf("\n"); break; }		//	4.  반복문이 정밀하지 않기때문에 정수를 다 읽었으면 루프 탈출
		}
		for (int i = 0; i < out_num; i++) {					//	5. 이전 반복문과 같은 조건의 반복문을 선언
			if (check[g] == 0) { printf("%8s", c_space); }//	6. 위에서 판별한 check[g]를 확인하여 기본일 경우 공백 출력,
			else if (check[g] == 1) { printf("%8s", c_max); }		//				   최대값 혹은 최소값일 경우 문자 출력
			else if (check[g] == 2) { printf("%8s", c_min); }
			if (g == cnt) { printf("\n"); break; }
			g++;
		}
		print_line(out_num);		// 라인(----) 출력
	}
	printf("\n\n\n max = %d \n min = %d\n\n", max, min); //test
	fclose(fp);	// 파일을 사용완료했으므로 파일포인터를 닫는다.
	return 0;
}
