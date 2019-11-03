#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;
int dp[61][61][61],n,d[3]; // 각각의 자리
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n;
	int arr[3] = { 1,3,9 };
	int brr[3] = { 1,3,9 };
	for (int i = 0; i < n; i++) cin >> d[i];
	memset(dp, -1, sizeof(dp));
	dp[d[0]][d[1]][d[2]] = 0;
	for (int i = 60; i >= 0; i--) {
		for (int k = 60; k >= 0; k--) {
			for (int z = 60; z >= 0; z--) {
				if (dp[i][k][z] != -1) {
					do {
						int a=0, b=0, c=0;
						if ((i - arr[0])>0)a = i - arr[0];
						if ((k - arr[1])>0) b = k - arr[1];
						if ((z - arr[2])>0) c = z - arr[2];
						int &res = dp[a][b][c];
						if (res != -1) {
							if (res > dp[i][k][z] + 1) res = dp[i][k][z] + 1;
						}
						else res = dp[i][k][z] + 1;
					} while (next_permutation(arr, arr + 3));
					for (int i = 0; i < 3; i++) arr[i] = brr[i];
				}
			}
		}
	}
	cout << dp[0][0][0] << "\n";
}