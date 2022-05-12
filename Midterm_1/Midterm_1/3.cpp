#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
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


int main()
{
	StackType s;
	init_stack(&s);
	char input[50];
	printf("문자열을 입력하시오: ");
	scanf("%s", &input);
	int len = strlen(input);

	char reverse[50]; //반전된 문자열을 담을 배열

	for (int i = 0; i < len; i++) {
		push(&s, input[i]);
	}
	
	char ch;
	for (int i = 0; i < len; i++) {
		ch = pop(&s);
		reverse[i] = ch;
	}

	if (input == reverse)
		printf("%s은 회문입니다.\n", input);
	else printf("%s은 회문이 아닙니다.\n", input);
	return 0;
}