#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define MAX 100
#define INF 1000000000

int n = 6, result;
int c[MAX][MAX], f[MAX][MAX], d[MAX];
vector <int> v[MAX];

void maxFlow(int start, int end) {
	while (1) {
		fill(d, d + MAX, -1);
		queue <int> q;
		q.push(start);
		while (!q.empty()) {
			int x = q.front();
			q.pop();
			for (int i = 0; i < v[x].size(); i++) {
				int y = v[x][i];
				if (d[y] == -1 && c[x][y] - f[x][y] > 0) {
					q.push(y);
					d[y] = x;
					if (y == end) break;
				}
			}
		}
		if (d[end] == -1) break; 
		int flow = INF;
		for (int i = end; i != start; i = d[i]) {
			flow = min(flow, c[d[i]][i] - f[d[i]][i]);
		}
		for (int i = end; i != start; i = d[i]) {
			f[d[i]][i] += flow;
			f[i][d[i]] -= flow;
		}
		result += flow;
	}
}

int main() {
	int n,m;
	cin >> n>>m;
	for (int i = 0; i < m; i++) {
		int a, b, d;
		cin >> a >> b >> d;
		v[a].push_back(b);
		v[b].push_back(a);
		c[a][b] = d;
	}
	maxFlow(1, n);
	cout << result << "\n";
	system("pause");
}