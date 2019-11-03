#include <iostream>
#include <stack>
#include <vector>
using namespace std;

char map[16];
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, t, m, p; cin >> n >> t >> m >> p;
	int cnt = 1;
	stack <int> s;
	vector <int> res;
	for (int i = 10; i <= 15; i++) {
		map[i] = 'A' - 10 + i;
	}
	for (int i = 0; i <= 1000; i++) {
		int q = i;
		while (q) {
			s.push(q % n);
			q /= n;
		}
		if (!i) s.push(0);
		while (!s.empty()) {
			if (cnt == p) res.push_back(s.top());
			if (res.size() == t) break;
			s.pop();
			cnt++;
			if (cnt == m + 1) cnt = 1;
		}
		if (res.size() == t) break;
	}
	for (auto a : res) {
		if (a >= 10) cout << map[a];
		else cout << a;
	}
	cout << "\n";
	system("pause");
}