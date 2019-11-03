#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int dp[101][101][101];
bool visit[1001][1001];
string aa, bb, cc;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> aa >> bb >> cc;
	int c = aa.length(), d = bb.length(), e = cc.length();
	for (int i = 0; i < c; i++) {
		for (int k = 0; k < d; k++) {
			for (int z = 0; z < e; z++) {
				if (aa[i] == bb[k] && bb[k] == cc[z]) dp[i + 1][k + 1][z + 1] = dp[i][k][z] + 1;
				else dp[i + 1][k + 1][z + 1] = max(dp[i+1][k][z +1],max(dp[i + 1][k + 1][z], dp[i][k + 1][z + 1]));
			}
		}
	}
	cout << dp[c][d][e] << "\n";
}