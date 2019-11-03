#include <iostream>
#include <queue>
#define MAX 100000
using namespace std;
int a, b, n, m;
bool visit[100001];
int d[6] = { 1,-1 };
void bfs() {
	queue <pair<int,int>> q;
	q.push({ n,0 });
	visit[n] = 1;
	while (!q.empty()) {
		int s = q.front().first;
		int c = q.front().second;
		if (s == m) {
			cout << c << "\n";
			return;
		}
		q.pop();
		for (int i = 0; i < 6; i++) {
			if (s + d[i] >= 0 && s + d[i] <= MAX && !visit[s + d[i]]) {
				q.push({ s + d[i],c + 1 });
				visit[s + d[i]] = 1;
			}
		}
		for (int i = 2; i < 4; i++) {
			if (s * d[i] <= MAX && !visit[s*d[i]]) {
				q.push({ s*d[i],c + 1 });
				visit[s*d[i]] = 1;
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> a >> b >> n >> m;
	d[2] = a, d[3] = b;
	d[4] = -a, d[5] = -b;
	bfs();
}