#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STACK_SIZE 100
#define FALSE 0
#define TRUE 1
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


int check_matching(char *in)
{
	StackType s;
	int n = strlen(in);
	char ch, open_ch;
	init_stack(&s);

	for (int i = 0; i < n; i++)
	{
		ch = in[i];

		switch (ch) {
		case '(':
		case '{':
		case '[':
			push(&s, ch);
			break;
		case ')':
		case '}':
		case ']':
			if (is_empty(&s)) { //왼쪽 괄호가 부족함 , 오른쪽 괄호가 더 많음
				return FALSE;
			}
			else {
				open_ch = pop(&s); //괄호 순서가 짝이 안맞음
				if ((open_ch == '(' && ch != ')') ||
					(open_ch == '{' && ch != '}') ||
					(open_ch == '[' && ch != ']'))
					return FALSE;
			}
		}
	}

	if (is_empty(&s)) //왼쪽괄호(여는괄호)가 남아있으면 짝이 안맞음
		return FALSE;

	return TRUE;
}


int main()
{
	char buf[1024] = { 0 }; //파일에서 읽은 수식을 임시로 저장
	FILE *fp = fopen("data.txt", "r");

	if (fp == NULL) {
		printf("error\n");
		return 0;
	}

	while (!feof(fp))
	{
		fscanf(fp, "%s", buf);
		if (check_matching(buf) == TRUE)
			printf("괄호검사 성공");
		else
			printf("괄호검사 실패");
		printf(" :: %s\n", buf);
	}

	fclose(fp);
	return 0;
}