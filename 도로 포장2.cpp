// ver dfs Æ²¸²


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector <pair<int, int>> v[10001];
bool check[10001];
int d[10001];
int n, m, k;
int min1 = 1e9;
void dfs(int s,int index) {
	if (s == n) {
		int t[10001];
		for (int i = 0; i < index; i++) t[i] = d[i];
		sort(t, t + index);
		int total = 0;
		for (int i = 0; i < index - k; i++) total += t[i];
		if (min1 > total) min1 = total;
		return;
	}
	for (int i = 0; i < v[s].size(); i++) {
		int y = v[s][i].first;
		if (!check[y]) {
			check[y] = 1;
			d[index] = v[s][i].second;
			dfs(y,index + 1);
			check[y] = 0;
			d[index] = 0;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m >> k;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({ b,c });
		v[b].push_back ({ a,c });
	}
	check[1] = 1;
	dfs(1,0);
	cout << min1 << "\n";
}