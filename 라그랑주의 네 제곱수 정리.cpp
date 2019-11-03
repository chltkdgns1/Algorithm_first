#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;
int cnt;
void dfs(int first, int num,int index) {
	if (index > 4)return;
	if (num == 0) {
		if (!num && index <= 4) cnt++;
		return;
	}
	for (int i = first; i*i <= num; i++) {
		dfs(i, num - i * i,index + 1);
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	while (1) {
		int n;
		cin >> n;
		if (!n) break;
		dfs(1,n,0);
		cout << cnt << "\n";
		cnt = 0;
	}
}

/*
#include<stdio.h>
#include <iostream>
using namespace std;
#define MAX_N 65536
int T;
int N;
int D[MAX_N + 1][5];
int M[183];
int main()
{
	int i, j, k;
	for (i = 1; i <= 181; i++)
	{
		M[i] = i * i;
	}
	for (i = 1; i <= 4; i++)
	{
		D[i][i] = 1;
	}
	for (i = 2; i <= 181; i++)
	{
		D[M[i]][1]++;
		for (j = 1; j <= 32767; j++)
		{
			for (k = 1; k < 4; k++)
			{
				if (D[j][k] != 0) D[j + M[i]][k + 1] += D[j][k];
			}
		}
	}

	for (int i = 1; i <= 200; i++) {
		for (int j = 1; j < 5; j++) {
			cout << D[i][j] << " ";
		}
		cout << "\n";
	}
	system("pause");
	while (1) {
		scanf_s("%d", &N);
		if (N == 0) break;
		printf("%d\n", D[N][1] + D[N][2] + D[N][3] + D[N][4]);
	}
	return 0;
}
*/
