#include <stdio.h>
#include <stdlib.h>
#define Max_DEGREE 100
// 10X ^ 5 + 6X + 3 // 계수 10 ,0 ,0 ,0 ,6 ,3 차수 5
// 7X ^ 4 + 5X ^ 2 + 1 // 계수 7, 0, 5, 0, 1 차수 4
typedef struct {
	int degree; //차수
	float coef[Max_DEGREE];
} polynomial;

polynomial poly_add(polynomial A, polynomial B)
{
	polynomial C;
	int Apos = 0, Bpos = 0, Cpos = 0;
	int degree_a = A.degree;
	int degree_b = B.degree;

	if (A.degree > B.degree)
		C.degree = A.degree;
	else
		C.degree = B.degree;

	while (Apos <= A.degree && Bpos <= B.degree) {
		if (degree_a > degree_b) {
			C.coef[Cpos++] = A.coef[Apos++];
			degree_a--;
		}
		else if (degree_a == degree_b) {
			C.coef[Cpos++] = A.coef[Apos++] + B.coef[Bpos++];
			degree_a--;
			degree_b--;
		}
		else {
			C.coef[Cpos++] = B.coef[Bpos++];
			degree_b--;
		}
	}
	return C;
}

void print_poly(polynomial p)
{
	for (int i = p.degree; i > 0; i--) 
		printf("%3.1fX^%d + ", p.coef[p.degree - i], i);

	printf("%3.1f \n", p.coef[p.degree]); //X^0 , 상수
}

int main(void)
{
	polynomial a = { 5, {10, 0, 0, 0, 6, 3} };
	polynomial b = { 4, {7, 0, 5, 0, 1} };
	polynomial c; // a+b 결과
	
	print_poly(a);
	print_poly(b);

	c = poly_add(a, b);

	print_poly(c);
	return 0;
}