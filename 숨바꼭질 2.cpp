#include <iostream>
#include <queue>
using namespace std;
int n, m, key;
bool check[100001];
void bfs(int s) {
	check[s] = 1;
	queue <pair<int,int>> q;
	q.push({ s,0 });
	int cnt = 0;
	while(1){
		int len = q.size();
		if (!len) break;
		for (int i = 0; i < len; i++) {
			int p = q.front().first;
			int r = q.front().second;
			check[p] = 1;
			if (p == m) {
				while (!q.empty()) {
					if (q.front().first == m && q.front().second == r) key++;
					q.pop();
				}
				cout << cnt << "\n" << key << "\n";
				return;
			}
			q.pop();
			if (p + 1 <= 100000 &&!check[p + 1]) q.push({ p + 1,r + 1});
			if (p - 1 >= 0&&!check[p - 1]) q.push({ p - 1,r  + 1});
			if (2 * p <= 100000 &&!check[2 * p]) q.push({ 2 * p,r + 1 });
		}
		cnt++;
	}
}
int main() {
	cin >> n >> m;
	bfs(n);
}