#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 100

typedef int element;

typedef struct {
	element data[MAX_STACK_SIZE];
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

void push(StackType *s, element item)
{
	if (is_full(s)) {
		printf("Stack is full \n");
		return;
	}

	s->data[++(s->top)] = item;
}


int is_empty(StackType *s)
{
	return (s->top < 0);

	//if (s->top <= 0)
	//	return 1;
	//else
	//	return 0;
}


element pop(StackType *s)
{
	if (is_empty(s)) {
		printf("Stack is empty\n");
		exit(0);
	}
	return s->data[(s->top)--];
}


void peek()
{

}

int main()
{
	StackType s;
	init_stack(&s);
	int size = 0;
	int array[MAX_STACK_SIZE];
	printf("정수 배열의 크기 : ");
	scanf("%d", &size);
	
	printf("정수를 입력하시오 :");
	for (int i = 0; i < size; i++) {
		scanf("%d", &array[i]);
	}

	for (int i = 0; i < size; i++) {
		printf("%d ", array[i]);
		push(&s, array[i]);
	}
	printf("\n");

	for (int i = 0; i < size; i++) {
		printf("%d ", pop(&s));
	}

	return 0;
}