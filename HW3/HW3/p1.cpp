///////////////////////////////////////////////
//
// 작성자 : 이민균
// 작성일 : 2022년 03월 26일
// 프로그램 명 : HW 3 , 문제 1번 , 알고리즘 실행 시간 비교
// 프로그램 설명 : 책 25페이지의 알고리즘 A, B, C를 참조하여 프로그래밍하고 각 알고리즘의 실행 시간을 비교하여라.
//
///////////////////////////////////////////////

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>	//시간측정 헤더파일 선언


int main()
{
	int i, j;	//반복문 제어 변수
	double sum = 0;	//연산을 저장할 변수
	int type = 0; //연산의 종류
	double num = 0;	//입력받을 변수 

	clock_t start, stop;	//시간 측정을 위해 start,stop변수 선언
	double duration;	//측정시간 저장변수

	printf("알고리즘을 선택하세요(1, 2, 3) :");
	scanf("%d", &type);	//선택한 알고리즘 번호를 type변수에 저장
	printf("반복 숫자를 입력하세요:");
	scanf("%lf", &num);	//양의 정수 num을 입력받기 

	switch (type)		//알고리즘 종류에 따라 switch문을 활용하여 수행
	{
	case 1:
		start = clock();	//타이머 시작
		for (i = 0; i < num; i++)
		{
			sum = num * num;		//알고리즘 A  sum <- n*n;
		}
		stop = clock();		//타이머 종료
		duration = (double)(stop - start) / CLOCKS_PER_SEC;		//측정 시간 계산
		printf("수행시간은 %f초입니다.\n", duration);	//시간 출력
		break;

	case 2:
		start = clock();	//타이머 시작
		for (i = 0; i < num; i++)
		{
			sum = sum + num;		//알고리즘 B for i <-1 to n do
								//				sum <-sum + n;
		}
		stop = clock();
		duration = (double)(stop - start) / CLOCKS_PER_SEC;
		printf("수행시간은 %f초입니다.\n", duration);
		break;
	case 3:
		start = clock();
		for (i = 0; i < num; i++)
		{
			for (j = 0; j < num; j++)
			{
				sum = sum + 1;		//알고리즘 C	for i<-1 to n do
									//					for j<-1 to n do
									//						sum <- sum + 1;
			}
		}
		stop = clock();
		duration = (double)(stop - start) / CLOCKS_PER_SEC;
		printf("수행시간은 %f초입니다.\n", duration);
		break;
	default:			//알고리즘 번호 1,2,3 이외의 번호가 입력될 시 
		printf("잘못된 번호입력입니다.\n");
		break;

		return 0;

	}
}