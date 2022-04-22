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
	int n = strlen(in); //�Է¹��� ��Ʈ�� ���̸� ����
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
			if (is_empty(&s)) // 2. �ݴ� ��ȣ�� ��Ī�Ǵ� ���� ��ȣ�� ���ÿ� ����
				return 0; //false
			else { // 1. ���ÿ� ��ȣ�� �ֱ� ������ ��Ī�ϴ����� Ȯ��
				printf("%d ", pnumber--);
				open_ch = pop(&s);
				if ((open_ch == '(' && ch != ')') ||
					(open_ch == '{' && ch != '}') ||
					(open_ch == '[' && ch != ']'))
				{
					return 0; //¦�� �ȸ��� ��� false return
				}
				break;
			}
		} //end of switch()
	} //end of for()

	if (!is_empty(&s)) // 3. ¦�� ���� �ʴ� ���� ��ȣ�� ���ÿ� �����ִ� ���
		return 0;	//false

	return 1; 
}

int main()
{
	char line[MAX_STACK_SIZE]; // ����� �Է� ��Ʈ�� (((())()) 
	printf("���� :");
	gets_s(line, MAX_STACK_SIZE);
	printf("��ȣ�� :");
	check_matching(line);
	return 0;
}