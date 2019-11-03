#include <iostream>
#include <vector>
using namespace std;
bool check[1001];
vector <int> v[1001];
void dfs(int s) {
	check[s] = 1;
	for (int i = 0; i < v[s].size(); i++) {
		int y = v[s][i];
		if (!check[y]) {
			dfs(y);
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n,a;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> a;
			v[i].push_back(a);
		}
		int cnt = 0;
		for (int i = 1; i <= n; i++) {
			if (!check[i]) {
				dfs(i);
				cnt++;
			}
		}
		for (int i = 1; i <= n; i++) {
			check[i] = 0; v[i].clear();
		}
		cout << cnt << "\n";
	}
}