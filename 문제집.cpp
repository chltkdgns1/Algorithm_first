#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector <int> v[32001];
int d[32001];
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < k; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		d[b]++;
	}
	priority_queue <int> q;
	for (int i = 1; i <=n; i++) {
		if (!d[i])q.push(-i);
	}
	while (!q.empty()) {
		int s = q.top();
		cout <<-s << " ";
		q.pop();
		for (int i = 0; i < v[-s].size(); i++) {
			int y = v[-s][i];
			d[y]--;
			if (!d[y]) q.push(-y);
		}
	}
}