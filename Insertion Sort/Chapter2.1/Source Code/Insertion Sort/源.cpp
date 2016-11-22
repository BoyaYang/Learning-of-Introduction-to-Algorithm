/***********************************

the pseudocode of insertion sort

INSERTION_SORT(A)

for j <- 2 to length[A]
	do key <- A[j]
		|> Insert A[j] into the sorted swquence A[1...j-1].
		i <- j-1
		while i > 0 and A[i] > key
			do A[i + 1] <- A[i]
				i <- i - 1
		A[i+1] <- key

************************************/

#include<stdio.h>
#include<stdlib.h>

void insertionSortNondecreasing(int* A,int length)
{
	int key,i,j;
	for (j = 1;j < length;j++)
	{
		key = A[j];
		i = j - 1;
		while (i >= 0 && A[i] > key)
		{
			A[i + 1] = A[i];
			i--;
		}
		A[i + 1] = key;
	}
}

void insertionSortNonincreasing(int* A, int length)
{
	int key, i, j;
	for (j = 1;j < length;j++)
	{
		key = A[j];
		i = j - 1;
		while (i >= 0 && A[i] < key)
		{
			A[i + 1] = A[i];
			i--;
		}
		A[i + 1] = key;
	}
}

int main()
{
	int *A = (int*)malloc(4*sizeof(int));
	for (int i = 0;i < 4;i++)
	{
		scanf("%d", (A + i));
	}
	insertionSortNondecreasing(A, 4);
	for (int i = 0;i < 4;i++)
	{
		printf("%d", *(A + i));
	}
	printf("\n");
	insertionSortNonincreasing(A, 4);
	for (int i = 0;i < 4;i++)
	{
		printf("%d", *(A + i));
	}
}