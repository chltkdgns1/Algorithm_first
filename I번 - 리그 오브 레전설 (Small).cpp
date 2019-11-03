#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
ll dp[10001];
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, b; cin >> n >> b;
	vector <int> v; v.push_back(1), v.push_back(b);
	for (int i = 1; i <= n; i++) {
		for (int k = 0; k < v.size(); k++) {

		}
	}
	cout << dp[0][4] + dp[1][4] << "\n";
	system("pause");

}