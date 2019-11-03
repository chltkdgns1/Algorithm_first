#include <iostream>
#include <algorithm>
using namespace std;

int dp[101][100001];
class Data {
public:
	int a, b, x, y;
};
Data d[100];
int n, k;
int solve(int cnt,int money,int time){
	if (cnt == n) {
		return money;
	}
	if (dp[cnt][time]) return dp[cnt][time];
	return dp[cnt][time] = max(solve(cnt + 1, money + d[cnt].b, time + d[cnt].a), solve(cnt + 1, money + d[cnt].y, time + d[cnt].x));
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int a, b, x, y;
		cin >> a >> b >> x >> y;
		d[i].a = a, d[i].b = b, d[i].x = x, d[i].y = y;
	}
	system("pause");
}