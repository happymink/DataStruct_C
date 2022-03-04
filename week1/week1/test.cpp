// week1 요금 지불 프로그램
//20174176 이민균
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int tax_caculate(int m) //세금 계산 함수
{
	if (m < 1000) // 0%
	{
		return 0;
	}
	else if (m < 3000) // 15%
	{
		return (m*0.15);
	}
	else if (m < 7000) // 20%
	{
		return (m*0.2);
	}
	else if (m < 10000) // 27%
	{
		return (m*0.27);
	}
	else if (m > 10000) // 35%
	{
		return (m*0.35);
	}
};

void payment_caculate(int t, int *p) //화폐의 개수 계산 함수
{
	int tax = tax_caculate(t);
	p[0] = (t / 10000);
	t = t - p[0] * 10000;

	p[1] = (t / 5000);
	t = t - p[1] * 5000;

	p[2] = (t / 1000);
	t = t - p[2] * 1000;

	p[3] = (t / 500);
	t = t - p[3] * 500;

	p[4] = (t / 100);

};

int main() {
	int payment[5];

	FILE *fp;
	fp = fopen("data.txt", "r");
	int money, tax, total;
	if (fp == NULL) {
		printf("file not found\n");
		return 0;
	}

	while (!feof(fp))
	{
		fscanf(fp, "%d", &money);
		tax = tax_caculate(money);
		total = money + tax;
		payment_caculate(total, payment);
		printf("사용금액(%d) + 세금(%d) = %d \n", money, tax, total);
		printf("1만원권 %d개\n", payment[0]);
		printf("5천원권 %d개\n", payment[1]);
		printf("1천원권 %d개\n", payment[2]);
		printf("5백원권 %d개\n", payment[3]);
		printf("1백원권 %d개\n", payment[4]);
		printf("=====================\n");
	}

	fclose(fp);

	return 0;
}