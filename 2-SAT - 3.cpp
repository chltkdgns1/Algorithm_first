#include <iostream>
#include <vector>
#include <stack>
using namespace std;
vector <int> v[20001], e[20001];
bool visit[20001];
int d[20001];
stack <int> st;
void dfs(int s) {
	visit[s] = 1;
	for (auto a : v[s]) {
		if (!visit[a]) dfs(a);
	}
	st.push(s);
}
void redfs(int s,int cnt) {
	d[s] = cnt;
	for (auto a : e[s]) {
		if (!d[a]) redfs(a,cnt);
	}
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, m; cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		v[n - a].push_back(n + b);
		v[n - b].push_back(n + a);
		e[n + a].push_back(n - b);
		e[n + b].push_back(n - a);
	}
	for (int i = 0; i <= 2 * n; i++) {
		if (!visit[i]) dfs(i);
	}

	int cnt = 0;
	while (!st.empty()) {
		int s = st.top();
		st.pop();
		if (d[s]) continue;
		redfs(s,cnt++);
	}
	for (int i = 1; i <= n; i++) {
		if (d[n - i] == d[n + i]) {
			cout << 0 << "\n";
			return 0;
		}
	}
	cout << 1 << "\n";
	for (int i = 1; i <= n; i++) {
		cout << (d[n - i] < d[n + i]) << " ";
	}
}