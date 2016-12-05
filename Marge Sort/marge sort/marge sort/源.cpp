#include<stdio.h>
#include<stdlib.h>

void marge(int *A, int p, int q, int r)
{
	int n1 = q - p + 1;
	int n2 = r - q;
	int i, k = 0, j = 0;
	int *B = (int*)malloc(sizeof(int)*(n1+1));
	int *C = (int*)malloc(sizeof(int)*(n2+1));
	for (i = 0;i < n1;i++)
	{
		*(B + i) = *(A + p + i);
	}
	*(B + i) = 100000;
	for (i = 0;i < n2;i++)
	{
		*(C + i) = *(A + q + i+1);
	}
	*(C + i) = 100000;
	for (i = p;i <= r;i++)
	{
		if (*(B + k) <= *(C + j))
		{
			*(A + i) = *(B + k);
			k++;
		}
		else
		{
			*(A + i) = *(C + j);
			j++;
		}
	}
}

void margeSort(int *A, int p, int r)
{
	if (p < r)
	{
		int q = (p + r) / 2;
		margeSort(A, p, q);
		margeSort(A, q + 1, r);
		marge(A, p, q, r);
	}
}

int main()
{
	int A[] = { 3,41,52,26,38,57,9,49 };
	margeSort(A, 0, 7);
	for (int i = 0;i < 8;i++)
	{
		printf("%d ", A[i]);
	}
}