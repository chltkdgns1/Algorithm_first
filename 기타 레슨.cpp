#include <cstdio>
#include <algorithm>
#include <iostream>

#define MAX_SIZE 100000
#define INF 1e9

using namespace std;

int lesson[MAX_SIZE];

int main()
{
	int n, c;
	scanf("%d %d", &n, &c);

	int max_lesson = 0;

	for (int i = 0; i < n; i++)
	{
		scanf("%d", lesson + i);
		max_lesson = lesson[i] > max_lesson ? lesson[i] : max_lesson;
	}

	int left = max_lesson, right = INF / c;

	while (left <= right)
	{
		int mid = (left + right) / 2;
		int sum = 0;
		int bluelay = 0;

		for (int i = 0; i < n; i++)
		{
			if (sum + lesson[i] > mid)
			{
				sum = 0;
				bluelay++;
			}
			sum += lesson[i];
		}

		if (sum != 0) bluelay++;

		if (bluelay <= c) right = mid - 1;
		else left = mid + 1;
	}

	printf("%d\n", left);

	return 0;
}
