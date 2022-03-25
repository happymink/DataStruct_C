#include <stdio.h>
#include <stdlib.h>

// factorial
// 5! =  5 * 4 * 3 * 2 * 1

int factorial(int n) 
{
	if (n == 0)
		return 1;
	else
		return n * factorial(n-1);
}

// x^n
// x = 2, n = 5
// 2* 2* 2* 2* 2
// 2 * 2^4
//     2 * 2^3

int power(int x, int n)
{
	if (n == 0)
		return 1;
	else
		return x * power(x, n - 1);
}

int fibonacci(int n)
{
	if (n == 0)
		return 0;
	else if (n == 1)
		return 1;
	else
		return fibonacci(n - 1) + fibonacci(n - 2);
}


int length(char *str)
{
	if (*str == '\0')
		return 0;
	else
		return 1 + length(str + 1);
}

void printStr(char *str)
{
	if (*str == '\0')
		return;
	else
	{
		printf("%c", *str);
		printStr(str + 1);
	} 
		
}

void printReverseStr(char *str)
{
	if (*str == '\0')
		return;
	else
	{
		printReverseStr(str +1);
		printf("%c", *str);
	}
}


int search(int data[], int n, int target)
{
	if (n <= 0)
		return -1; //못찾음
	else if (target == data[n - 1])
		return n - 1; //찾았음
	else {
		search(data, n - 1, target);
	}
}
int main() {
	int data[] = { 1, 3, 5, 4, 9, 7 };
	
	printf("serach : %d\n", search(data, 6, 3));
	return 0;
}