///////////////////////////////////////////////
//
// �ۼ��� : �̹α�
// �ۼ��� : 2022�� 03�� 26��
// ���α׷� �� : HW 3 , ���� 1�� , �˰��� ���� �ð� ��
// ���α׷� ���� : å 25�������� �˰��� A, B, C�� �����Ͽ� ���α׷����ϰ� �� �˰����� ���� �ð��� ���Ͽ���.
//
///////////////////////////////////////////////

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>	//�ð����� ������� ����


int main()
{
	int i, j;	//�ݺ��� ���� ����
	double sum = 0;	//������ ������ ����
	int type = 0; //������ ����
	double num = 0;	//�Է¹��� ���� 

	clock_t start, stop;	//�ð� ������ ���� start,stop���� ����
	double duration;	//�����ð� ���庯��

	printf("�˰����� �����ϼ���(1, 2, 3) :");
	scanf("%d", &type);	//������ �˰��� ��ȣ�� type������ ����
	printf("�ݺ� ���ڸ� �Է��ϼ���:");
	scanf("%lf", &num);	//���� ���� num�� �Է¹ޱ� 

	switch (type)		//�˰��� ������ ���� switch���� Ȱ���Ͽ� ����
	{
	case 1:
		start = clock();	//Ÿ�̸� ����
		for (i = 0; i < num; i++)
		{
			sum = num * num;		//�˰��� A  sum <- n*n;
		}
		stop = clock();		//Ÿ�̸� ����
		duration = (double)(stop - start) / CLOCKS_PER_SEC;		//���� �ð� ���
		printf("����ð��� %f���Դϴ�.\n", duration);	//�ð� ���
		break;

	case 2:
		start = clock();	//Ÿ�̸� ����
		for (i = 0; i < num; i++)
		{
			sum = sum + num;		//�˰��� B for i <-1 to n do
								//				sum <-sum + n;
		}
		stop = clock();
		duration = (double)(stop - start) / CLOCKS_PER_SEC;
		printf("����ð��� %f���Դϴ�.\n", duration);
		break;
	case 3:
		start = clock();
		for (i = 0; i < num; i++)
		{
			for (j = 0; j < num; j++)
			{
				sum = sum + 1;		//�˰��� C	for i<-1 to n do
									//					for j<-1 to n do
									//						sum <- sum + 1;
			}
		}
		stop = clock();
		duration = (double)(stop - start) / CLOCKS_PER_SEC;
		printf("����ð��� %f���Դϴ�.\n", duration);
		break;
	default:			//�˰��� ��ȣ 1,2,3 �̿��� ��ȣ�� �Էµ� �� 
		printf("�߸��� ��ȣ�Է��Դϴ�.\n");
		break;

		return 0;

	}
}