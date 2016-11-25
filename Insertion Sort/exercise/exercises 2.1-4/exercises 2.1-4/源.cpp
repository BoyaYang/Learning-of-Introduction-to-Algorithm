#include<stdio.h>
#include<stdlib.h>

void sumBinaryInteger(int* A, int* B, int* C,int n)
{
	int i,j;
	for (i = 0;i < n + 1;i++)
	{
		C[i] = 0;
	}
	for (i = n;i > 0;i--)
	{
		C[i] += A[i-1] + B[i-1];
		if (C[i] == 2)
		{
			C[i] = 0;
			C[i - 1] = 1;
		}
		if (C[i] == 3)
		{
			C[i] = 1;
			C[i - 1] = 1;
		}
	}
	return;
}

int main()
{
	int n;
	int *A, *B, *C;
	printf("please enter an integer:\n");
	scanf("%d", &n);
	A = (int*)malloc(sizeof(int)*n);
	B = (int*)malloc(sizeof(int)*n);
	C = (int*)malloc(sizeof(int)*(n + 1));
	printf("please enter A:\n");
	for (int i = 0;i < n;i++)
	{
		scanf("%d", (A+i));
	}
	printf("please enter B:\n");
	for (int i = 0;i < n;i++)
	{
		scanf("%d", (B+i));
	}
	sumBinaryInteger(A, B, C, n);
	for (int i = 0;i < (n+1);i++)
	{
		printf("%d", *(C+i));
	}
}