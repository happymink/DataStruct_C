///////////////////////////////////////////////
//
// 작성자 : 이민균
// 작성일 : 2022년 03월 26일
// 프로그램 명 : HW 3 , 문제 2번 , 알고리즘 실행 시간 비교
// 프로그램 설명 : 사칙연산을 연속적으로 실행하여 실행 시간을 측정하는 프로그램
//
///////////////////////////////////////////////

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>	//시간측정 헤더파일 선언

int main()
{
	int i, j;	//반복문 제어 변수
	double sum = 0;	//연산을 저장할 변수
	char type; //연산의 종류
	int num = 0;	//반복 획수 저장 변수 

	clock_t start, stop;	//시간 측정을 위해 start,stop변수 선언
	double duration;	//측정시간 저장변수

	printf("연산을 선택하세요(+, -, *, / ) :");
	scanf("%c", &type);	//선택한 연산종류 type변수에 저장
	printf("반복 숫자를 입력하세요:");
	scanf("%d", &num);	//양의 정수 num을 입력받기 

	switch (type)		//알고리즘 종류에 따라 switch문을 활용하여 수행
	{
	case '+':
		start = clock();	//타이머 시작
		for (i = 0; i < num; i++)
		{
			sum = num + num;		//알고리즘 A  sum <- n+n;
		}
		stop = clock();		//타이머 종료
		duration = (double)(stop - start) / CLOCKS_PER_SEC;		//측정 시간 계산
		printf("수행시간은 %f초입니다.\n", duration);	//시간 출력
		break;
	case '-':
		start = clock();	//타이머 시작
		for (i = 0; i < num; i++)
		{
			sum = num - num;		//알고리즘 A  sum <- n-n;
		}
		stop = clock();		//타이머 종료
		duration = (double)(stop - start) / CLOCKS_PER_SEC;		//측정 시간 계산
		printf("수행시간은 %f초입니다.\n", duration);	//시간 출력
		break;

	case '*':
		start = clock();	//타이머 시작
		for (i = 0; i < num; i++)
		{
			sum = num * num;		//알고리즘 A  sum <- n*n;
		}
		stop = clock();		//타이머 종료
		duration = (double)(stop - start) / CLOCKS_PER_SEC;		//측정 시간 계산
		printf("수행시간은 %f초입니다.\n", duration);	//시간 출력
		break;

	case '/':
		start = clock();	//타이머 시작
		for (i = 0; i < num; i++)
		{
			sum = num / num;		//알고리즘 A  sum <- n/n;
		}
		stop = clock();		//타이머 종료
		duration = (double)(stop - start) / CLOCKS_PER_SEC;		//측정 시간 계산
		printf("수행시간은 %f초입니다.\n", duration);	//시간 출력
		break;

	default:			//알고리즘 번호 1,2,3 이외의 번호가 입력될 시 
		printf("잘못된 문자입력입니다.\n");
		break;

		return 0;

	}
}