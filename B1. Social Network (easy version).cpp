#include <iostream>
#include <set>
#include <queue>
using namespace std;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, k; cin >> n >> k;
	deque <int> s;
	set <int> t;
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		if (s.empty()) s.push_back(a), t.insert(a);
		else {
			if (t.find(a) != t.end()) continue;
			s.push_front(a); t.insert(a);
			if (s.size() > k) {
				t.erase(s.back());
				s.pop_back();
			}
		}
	}
	cout << s.size() << "\n";
	for (auto a : s) cout << a << " ";
}
