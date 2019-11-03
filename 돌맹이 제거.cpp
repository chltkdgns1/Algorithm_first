#include <iostream>
#include <vector>
#define MAX 500
using namespace std;
vector <int> v[MAX * 2 + 1];
bool check[2 * MAX + 1];
int d[2 * MAX + 1];
bool dfs(int s) {
	if (check[s]) return false;
	check[s] = 1;
	for (int i = 0; i < v[s].size(); i++) {
		int y = v[s][i];
		if (!d[y] || dfs(d[y])) {
			d[y] = s;
			return true;
		}
	}
	return false;
}
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
	}
	int c = 0;
	for (int i = 1; i <= n; i++) {
		fill(check + 1, check + 1 + n, 0);
		if (dfs(i)) c++;
	}
	cout << c << "\n";
}