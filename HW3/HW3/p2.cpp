///////////////////////////////////////////////
//
// �ۼ��� : �̹α�
// �ۼ��� : 2022�� 03�� 26��
// ���α׷� �� : HW 3 , ���� 2�� , �˰��� ���� �ð� ��
// ���α׷� ���� : ��Ģ������ ���������� �����Ͽ� ���� �ð��� �����ϴ� ���α׷�
//
///////////////////////////////////////////////

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>	//�ð����� ������� ����

int main()
{
	int i, j;	//�ݺ��� ���� ����
	double sum = 0;	//������ ������ ����
	char type; //������ ����
	int num = 0;	//�ݺ� ȹ�� ���� ���� 

	clock_t start, stop;	//�ð� ������ ���� start,stop���� ����
	double duration;	//�����ð� ���庯��

	printf("������ �����ϼ���(+, -, *, / ) :");
	scanf("%c", &type);	//������ �������� type������ ����
	printf("�ݺ� ���ڸ� �Է��ϼ���:");
	scanf("%d", &num);	//���� ���� num�� �Է¹ޱ� 

	switch (type)		//�˰��� ������ ���� switch���� Ȱ���Ͽ� ����
	{
	case '+':
		start = clock();	//Ÿ�̸� ����
		for (i = 0; i < num; i++)
		{
			sum = num + num;		//�˰��� A  sum <- n+n;
		}
		stop = clock();		//Ÿ�̸� ����
		duration = (double)(stop - start) / CLOCKS_PER_SEC;		//���� �ð� ���
		printf("����ð��� %f���Դϴ�.\n", duration);	//�ð� ���
		break;
	case '-':
		start = clock();	//Ÿ�̸� ����
		for (i = 0; i < num; i++)
		{
			sum = num - num;		//�˰��� A  sum <- n-n;
		}
		stop = clock();		//Ÿ�̸� ����
		duration = (double)(stop - start) / CLOCKS_PER_SEC;		//���� �ð� ���
		printf("����ð��� %f���Դϴ�.\n", duration);	//�ð� ���
		break;

	case '*':
		start = clock();	//Ÿ�̸� ����
		for (i = 0; i < num; i++)
		{
			sum = num * num;		//�˰��� A  sum <- n*n;
		}
		stop = clock();		//Ÿ�̸� ����
		duration = (double)(stop - start) / CLOCKS_PER_SEC;		//���� �ð� ���
		printf("����ð��� %f���Դϴ�.\n", duration);	//�ð� ���
		break;

	case '/':
		start = clock();	//Ÿ�̸� ����
		for (i = 0; i < num; i++)
		{
			sum = num / num;		//�˰��� A  sum <- n/n;
		}
		stop = clock();		//Ÿ�̸� ����
		duration = (double)(stop - start) / CLOCKS_PER_SEC;		//���� �ð� ���
		printf("����ð��� %f���Դϴ�.\n", duration);	//�ð� ���
		break;

	default:			//�˰��� ��ȣ 1,2,3 �̿��� ��ȣ�� �Էµ� �� 
		printf("�߸��� �����Է��Դϴ�.\n");
		break;

		return 0;

	}
}