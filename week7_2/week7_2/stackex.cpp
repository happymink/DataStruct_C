#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STACK_SIZE 100

typedef char element;

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

int check_matching(char *in)
{
	StackType s;
	init_stack(&s);
	char ch, open_ch;
	int pnumber = 0;
	int n = strlen(in); //입력받은 스트링 길이를 구함
	// { [ ( -------- ) ] }

	for (int i = 0; i < n; i++) {
		ch = in[i];

		switch (ch) {
		case '(':
		case '{':
		case '[':
			printf("%d ", ++pnumber);
			push(&s, ch);
			break;

		case ')':
		case '}':
		case ']':
			if (is_empty(&s)) // 2. 닫는 괄호와 매칭되는 여는 괄호가 스택에 없음
				return 0; //false
			else { // 1. 스택에 괄호가 있기 때문에 매칭하는지를 확인
				printf("%d ", pnumber--);
				open_ch = pop(&s);
				if ((open_ch == '(' && ch != ')') ||
					(open_ch == '{' && ch != '}') ||
					(open_ch == '[' && ch != ']'))
				{
					return 0; //짝이 안맞을 경우 false return
				}
				break;
			}
		} //end of switch()
	} //end of for()

	if (!is_empty(&s)) // 3. 짝이 맞지 않는 여는 괄호가 스택에 남아있는 경우
		return 0;	//false

	return 1; 
}

int main()
{
	char line[MAX_STACK_SIZE]; // 사용자 입력 스트링 (((())()) 
	printf("수식 :");
	gets_s(line, MAX_STACK_SIZE);
	printf("괄호수 :");
	check_matching(line);
	return 0;
}