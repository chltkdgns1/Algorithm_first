#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
typedef long long ll;
class Data {
public:
	int a, b, c;
};
bool cmp(const Data &a, const Data &b) {
	return a.b < b.b;
}
ll dp[10001];
int main(){
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t; cin >> t;
	while (t--){
		int n, m; cin >> n >> m;
		int a, b, c;
		vector <Data> v;
		for (int i = 0; i < m; i++) {
			cin >> a >> b >> c;
			v.push_back({ a,b,c });
		}
		sort(v.begin(), v.end(), cmp);
		memset(dp, 98765432, sizeof(dp));
		dp[0] = 0;
		for (int i = 0; i < m; i++) {
			for (int k = n - 1; k >= 0; k--) {
				int u = min(n, k + v[i].a);
				dp[u] = min(dp[u], dp[k] + v[i].c + (u - k)*v[i].b);
			}
		}
		cout << dp[n] << "\n";
	}
}