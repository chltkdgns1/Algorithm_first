#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
class Data {
public:
	int left, right;
	long long cnt;
	Data() { cnt = 0, left = -1, right = -1; }
};
map <int, Data> m;int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	long long n, t = 0, c; cin >> n;
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		if (m.empty()) {
			m[a].cnt = 0;
			cout << t << "\n";
		}
		else {
			auto b = m.lower_bound(a);
			if (b == m.end() || (*b).second.left != -1) {
				b--;
				(*b).second.right = a;
				c = m[a].cnt = (*b).second.cnt + 1;
				t += c;
				cout << t << "\n";
			}
			else if ((*b).second.left == -1) {
				(*b).second.left = a;
				c = m[a].cnt = (*b).second.cnt + 1;
				t += c;
				cout << t << "\n";
			}
		}
	}
}