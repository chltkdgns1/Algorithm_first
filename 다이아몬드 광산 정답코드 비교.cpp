#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <iostream>
#include <cmath>
#include <cstring>
#include <string>
#include <stack>
#include <queue>

using namespace std;

typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef long long lld;
typedef unsigned long long ulld;

const int INF = 987654321;

char board[800][800];

//[0] ÁÂÇÏ ´ë°¢ [1] ¿ìÇÏ ´ë°¢
//[2] ÁÂ»ó ´ë°¢ [3] ¿ì»ó ´ë°¢
//[0] == À§¶Ñ²± [1] == ¹Ø¶Ñ²±
int chk[800][800][4];
int r, c;

int main()
{
	scanf_s("%d%d", &r, &c);
	int ans = 0;
	for (int i = 0; i < r; ++i)scanf_s("%s", board[i]);

	for (int i = r - 1; i >= 0; --i) {
		for (int j = c - 1; j >= 0; --j) {
			chk[i][j][0] = chk[i][j][1] = board[i][j] == '1';
			if (chk[i][j][0] == 0)continue;

			if (i + 1 < r && j - 1 >= 0) {
				chk[i][j][0] = chk[i + 1][j - 1][0] + chk[i][j][0];
			}
			if (i + 1 < r && j + 1 < c) {
				chk[i][j][1] = chk[i + 1][j + 1][1] + chk[i][j][1];
			}
		}
	}

	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; ++j) {
			chk[i][j][2] = chk[i][j][3] = board[i][j] == '1';
			if (chk[i][j][2] == 0)continue;
			ans = 1;
			if (i - 1 >= 0 && j - 1 >= 0) {
				chk[i][j][2] = chk[i - 1][j - 1][2] + chk[i][j][2];
			}
			if (i - 1 >= 0 && j + 1 < c) {
				chk[i][j][3] = chk[i - 1][j + 1][3] + chk[i][j][3];
			}
		}
	}

	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; ++j) {
			chk[i][j][0] = min(chk[i][j][0], chk[i][j][1]);
			chk[i][j][1] = min(chk[i][j][2], chk[i][j][3]);
		}
	}

	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; ++j) {
			for (int k = ans + 1; k <= chk[i][j][0]; ++k) {
				int oi = i + (k - 1) * 2;
				if (oi >= r)continue;
				if (chk[oi][j][1] >= k)ans = k;
			}
		}
	}
	printf("%d\n", ans);
	system("pause");
	/*printf("\n");
	for(int i=0;i<r;++i){
		for(int j=0;j<c;++j){
			printf("%d",chk[i][j][0]);
		}
		printf("\n");
	}
	printf("\n");

	for(int i=0;i<r;++i){
		for(int j=0;j<c;++j){
			printf("%d",chk[i][j][1]);
		}
		printf("\n");
	}*/
}