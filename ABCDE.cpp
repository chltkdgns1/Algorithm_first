#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

vector <int> v[2001];
bool visit[2001];
bool dfs(int s,int cnt) {
	if (cnt == 5) {
		return true;
	}
	for (int i = 0; i < v[s].size(); i++) {
		int y = v[s][i];
		if (!visit[y]) {
			visit[y] = 1;
			if (dfs(y, cnt + 1) == true) return true;
			visit[y] = 0;
		}
	}
	return false;
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	for (int i = 0; i < n; i++) {
		memset(visit, 0, sizeof(visit));
		if (dfs(i, 0) == true) {
			cout << 1 << "\n";
			return 0;
		}
	}
	cout << 0 << "\n";
}