////////////////////////////////////////////////////////////////
//
// 작성자 : 이민균	
// 작성일 : 2022년 03월 10일
// 프로그램명 : 파일입출력을 이용한 사용자 정의 n개의 데이터 출력 및 최대값,최소값 출력
// 프로그램설명 :	파일입출력을 통해 사용자가 임의로 정한 개수만큼 데이터를 출력함과 동시에 최대값과 최소값을 판별한다.
//					
//
////////////////////////////////////////////////////////////////
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void print_list(int n) {
	for (int i = 1; i <= n; i++) {
		printf("%5d ", i);
	}
	printf("\n===============================================\n");
}

int main()
{
	int arr[10000] = {}; // 10,000개 이하의 수를 저장 할 정수형 배열 선언
	FILE *fp;	// 파일포인터 변수선언
	int max, min; //최대 최소값을 저장할 정수형 변수
	int out_num; //한 라인에 출력할 정수의 개수를 저장
	int cnt = 1;	 //출력된 숫자를 카운트하는 정수형 변수
	fp = fopen("data.txt", "r");	// data.txt파일을 읽기모드로 열어 생성된 FILE구조체를 fp에 할당
	if (fp == NULL)	// 만약 fopen함수에서 에러가 발생하여 fp에 NULL값이 저장되었다면 파일열기실패
	{
		printf("파일이 열리지 않았습니다.\n");
		return 0;	// 메세지 출력하고 프로그램 종료
	}
	
	fscanf(fp, "%d", &out_num);
	fscanf(fp, "%d", &arr[0]);  //첫 번째 수를 따로 빼내어서 저장
	max = arr[0]; //최대값과 최소값을 배열의 첫 번째 요소로 지정 // 개선방안 생각해보기 ->이로인해 for 반복문 변수 안이쁨
	min = arr[0]; 
	while (!feof(fp))	// 파일포인터가 파일의 끝을 가르킬때까지 반복한다.
	{
		fscanf(fp, "%d", &arr[cnt]);	// 파일에서 정수형 값을 읽고
		if (arr[cnt] > max) { max = arr[cnt]; }
		if (arr[cnt] < min) { min = arr[cnt]; }
		cnt++;
		
	}
	print_list(out_num);
	int k = 0;
	int max_loc;
		for (int j = 0; j < cnt; j++) {
			printf("%6d", arr[k]);
			k++;

			if (arr[k] == max) {

			}
			if (k % out_num == 0) {  //줄바꿈, 만약 n으로 나누어 떨어진다면
				printf("\n");
			}
		
		}

	printf("\n max = %d \n min = %d", max, min); //test

	fclose(fp);	// 파일을 사용완료했으므로 파일포인터를 닫는다.
	return 0;
}
