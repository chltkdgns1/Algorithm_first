#include <iostream>
#include <string>
typedef long long ll;
using namespace std;
ll dp[60];
ll fibo(int n) {
	if (dp[n]) return dp[n];
	if (n == 1) return dp[1] = 5;
	if (n == 2) return dp[2] = 13;
	return dp[n] = fibo(n - 1) + fibo(n - 2) + 1;
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	ll d; int index = 0;fibo(50);
	for (int k = 50; k >= 2; k--) {
		if (n - dp[k] > 0) {
			n -= dp[k] + 1;
		}
	}
	string s = "Messi Gimossi";
	if (n == 0 || s[n - 1] == ' ') cout << "Messi Messi Gimossi";
	else cout << s[n - 1] << "\n";
}