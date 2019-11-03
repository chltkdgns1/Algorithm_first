#include <iostream>
#include <vector>
#include <unordered_set>
#include <string.h>
using namespace std;

vector <int> v[100001];
unordered_set <int> e;
bool visit[100001];

int edge;
void dfs(int s) {
	visit[s] = 1;
	int cnt = 0;
	for (int i = 0; i < v[s].size(); i++) {
		int y = v[s][i];
		if (!visit[y]) {
			cnt++;
			dfs(y);
		}
	}
	if (!cnt) e.insert(s),edge = s;
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, m;
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	dfs(1);
	memset(visit, 0, sizeof(visit));
	dfs(edge);
	cin >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		if (a == 1) {
			if (e.find(b) == e.end()) {
				cout << "yes" << "\n";
			}
			else cout << "no" << "\n";
		}
		else if (a == 2) cout << "yes" << "\n";
	}
}