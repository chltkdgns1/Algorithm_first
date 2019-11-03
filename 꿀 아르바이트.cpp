#include <iostream>
#include <queue>
using namespace std;
deque <int> q;
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, m;
	cin >> n >> m;
	long long t = 0, max = 0;
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		if (i < m) {
			t += a;
			q.push_back(a);
		}
		else {
			t -= q.front();
			t += a;
			q.pop_front();
			q.push_back(a);
		}
		if (max < t) max = t;
	}
	cout << max << "\n";
}