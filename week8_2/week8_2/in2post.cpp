#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STACK_SIZE 100


typedef struct {
	char stack[MAX_STACK_SIZE];
	int top;
}StackType;

void init_stack(StackType *s)
{
	s->top = -1;
}

int is_full(StackType *s)
{
	return (s->top == (MAX_STACK_SIZE - 1));

	//if (s->top == (MAX_STACK_SIZE - 1))
	//	return 1;
	//else
	//	return 0;
}

void push(StackType *s, char item)
{
	if (is_full(s)) {
		printf("Stack is full \n");
		return;
	}

	s->stack[++(s->top)] = item;
}


int is_empty(StackType *s)
{
	return (s->top < 0);

	//if (s->top <= 0)
	//	return 1;
	//else
	//	return 0;
}


char pop(StackType *s)
{
	if (is_empty(s)) {
		printf("Stack is empty\n");
		exit(1);
	}
	return s->stack[(s->top)--];
}


char peek(StackType *s)
{
	return s->stack[(s->top)];
}

int prec(char op)  //������ �켱���� ��ȯ
{
	//�켱���� (����) 0 - 2 (����)
	switch (op) {
	case '(':
	case ')':
		return 0;
	case '+':
	case '-':
		return 1;
	case '*':
	case '/':
		return 2;
	}
	return -1;
}


void infix_to_postfix(char exp[])
{
	StackType s;
	int len = strlen(exp);
	char ch,top_op;
	init_stack(&s);

	for (int i = 0; i < len; i++)
	{
		ch = exp[i];

		switch (ch)
		{
		case '+':
		case '-':
		case '*':
		case '/': //������ �켱������ �����ְ� ���ö����� �켱���� ���������ڸ� ������
			while (!is_empty(&s) && (prec(ch) <= prec(peek(&s))))
				printf("%c", pop(&s));
			
			push(&s, ch);
			break;
		case '(':
			push(&s, ch);
			break;
		case ')':
			// code �ݴ°�ȣ�� ���ö����� ���� , pop
			top_op = pop(&s);
			while (top_op != '(') {
				printf("%c", top_op);
				top_op = pop(&s);
			}
			break;

		default: //�ǿ����� ������ ȭ�� ���
			printf("%c", ch);
			break;

		} //end of switch

	} //end of for()

		//���ÿ� ���� ������ ó��
}

int main()
{
	StackType s;
	init_stack(&s);
	
	char buf[1024] = { 0 };
	FILE * fp = fopen("data.txt", "r");

	if (fp == NULL) {
		printf("error\n");
		exit(1);
	}

	while (!feof(fp)) {
		fscanf(fp, "%s", buf);
		infix_to_postfix(buf);
		printf("\n");
	}

	fclose(fp);
	return 0;
}