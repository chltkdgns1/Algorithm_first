#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
vector <int> v[20001];
int d[20001];
int max1;
void bfs(int s) {
	d[s] = 0;
	queue <pair<int,int>> q;
	q.push({ s,0 });
	while (1) {
		int len = q.size();
		if (!len) break;
		for (int i = 0; i < len; i++) {
			int n = q.front().first;
			int dis = q.front().second;
			q.pop();
			for (int j = 0; j < v[n].size(); j++) {
				if (d[v[n][j]] > d[n] + 1) {
					d[v[n][j]] = d[n] + 1;
					q.push({ v[n][j],dis + 1 });
					max1 = max(max1,d[n] + 1);
				}
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	for (int i = 1; i <= n; i++) d[i] = 1e9;
	bfs(1);
	int a = 0, c = 0;
	for (int i = 1; i <= n; i++) {
		if (d[i] == max1) {
			if (!a) a = i;
			c++;
		}
	}
	cout << a << " " << max1 << " " << c << "\n";
}