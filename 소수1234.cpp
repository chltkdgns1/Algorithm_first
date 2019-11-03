#include <stdio.h>
#include <iostream>
int main()
{
	int M, N; // N = 13
	int count;
	int arr[1000001];
	//scanf_s("%d %d", &M, &N);

	for (int k = 1; k < 1000001; k++)
	{
		arr[k] = k;
		printf("%d", arr[k]);
	}
}
/*
	for (int i = M; i <= N; i++)
	{
		count = 0;
		for (int j = 1; j <= i; j++)
		{
			if (i % j == 0)
				count++;
			if (count > 2)
				break;
		}
		if (count == 2)
			printf("%d\n", i);
	}
	system("pause");

	return 0;
}*/
/*
i 6 7 8 9 10 11 12 13 14 15 16 17 18

j 6 7 8 9 10 11 12 13 14 15 16 17 18

*/
