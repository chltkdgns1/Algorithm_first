#include <iostream>
#include <string>
using namespace std;
string s;int dp[42];int dfs(int index) {int &res = dp[index];
	if (res) return dp[index];
	if (index > s.length()) return 0;
	if (index == s.length()) return 1;
	if (index + 1 < s.length()) {
		string t;
		t += s[index];
		t += s[index + 1];
		if (stoi(t) <= 34 && t[0] != '0') dp[index] += dfs(index + 2);
		if(t[0] != '0') dp[index] += dfs(index + 1);
	}
	else if (s[index] != '0') dp[index] += dfs(index + 1);
	return dp[index];
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> s;
	dfs(0);
	cout << dp[0] << "\n";
}