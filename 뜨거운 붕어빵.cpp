#include<stdio.h>
#include <iostream>
#include<conio.h>

int main()
{
	int N, M;

	int boong[10] = { 0 };

	scanf_s("%d %d", &N, &M);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			boong[M - j - 1] = _getche();
		}

		for (int j = 0; j < M; j++)
		{
			printf("%d", boong[j] - 48);
		}
		printf("\n");
	}
	system("pause");
}