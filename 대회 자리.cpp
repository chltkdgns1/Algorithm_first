#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t; cin >> t;
	while (t--) {
		int a, b; cin >> a >> b;
		bool visit[501] = { 0 };
		int cnt = 0;
		for (int i = 0; i < a; i++) {
			int c; cin >> c;
			if (!visit[c]) visit[c] = 1;
			else cnt++;
		}
		cout << cnt << "\n";
	}
}