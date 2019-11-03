#include <iostream>
#include <math.h>
using namespace std;

double dp[2][101];
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, m; cin >> n >> m;
	double a, b, c, d; cin >> a >> b >> c >> d;
	for (int i = 0; i < n; i++) {
		if (!i && m ){
			dp[0][i] = c;
			dp[1][i] = d;
		}
		else if(!i && !m){
			dp[0][i] = a;
			dp[1][i] = b;
		}
		else {
			dp[0][i] = dp[0][i - 1] * a + dp[1][i - 1] * c;
			dp[1][i] = dp[0][i - 1] * b + dp[1][i - 1] * d;
		}
	}
	cout << round(dp[0][n - 1] * 1000) << "\n";
	cout << round(dp[1][n - 1] * 1000 )<< "\n";
}