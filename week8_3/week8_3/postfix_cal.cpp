#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STACK_SIZE 100

typedef struct element;

typedef struct {
	int stack[MAX_STACK_SIZE];
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

void push(StackType *s, int item)
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


int pop(StackType *s)
{
	if (is_empty(s)) {
		printf("Stack is empty\n");
		exit(1);
	}
	return s->stack[(s->top)--];
}


int peek(StackType *s)
{
	return s->stack[(s->top)];
}


int eval(char exp[]) {
	StackType s;
	int len = strlen(exp);
	char ch;
	int value;
	int op1, op2;

	init_stack(&s);

	for (int i = 0; i < len; i++) {
		ch = exp[i];

		if ((ch != '+') && (ch != '-') && (ch != '*') && (ch != '/')) { //피연산자의 경우
			value = ch - '0'; //char -> int
			push(&s, value);
		}
		else {	//연산자의 경우
			op2 = pop(&s);
			op1 = pop(&s);

			switch (ch)
			{
			case '+':
				push(&s, op1 + op2);
				break;
			case '-':
				push(&s, op1 - op2);
				break;
			case '*':
				push(&s, op1 * op2);
				break;
			case '/':
				push(&s, op1 / op2);
				break;
			}
		}
	}
	return pop(&s);
}

int main()
{
	int result;
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
		printf("후위표기식은 : %s\n", buf);
		result = eval(buf);
		printf("결과값은 %d\n", result);
	}

	fclose(fp);
	return 0;
}