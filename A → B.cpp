#include <iostream>
#include <queue>
#include <cmath>
using namespace std;
bool visit[1000000001];
int n, m;
void bfs(int s) {
	visit[s] = 1;
	queue <int> q;
	q.push(s);
	int cnt = 0;
	while (1) {
		int len = q.size();
		if (!len) {
			cout << -1 << "\n";
			break;
		}
		for (int i = 0; i < len; i++) {
			int num = q.front();
			if (num == m) {
				cout << cnt + 1 << "\n";
				return;
			}
			q.pop();
			if (10*num + 1 <= m && !visit[10*num + 1]) {
				visit[10 * num + 1] = 1;
				q.push(10 * num + 1);
			}
			if (num * 2 <= m && !visit[2 * num]) {
				visit[2 * num] = 1;
				q.push(2 * num);
			}
		}
		cnt++;
	}

}
int main() {
	cin >> n >> m;
	bfs(n);
}