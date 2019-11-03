#include <iostream>
#include <string>
#include <map>
#include <set>
using namespace std;

map <string, set<string>> m;
map <string, int> s;
bool dfs(string e,string par,int ch) {
	s[e] = ch;
	for (auto a : m[e]) {
		if (a == par) continue;
		if (!s[a]) {
			if (ch == 1) {
				if (!dfs(a, e, 2)) {
					return false;
				}
			}
			else {
				if (!dfs(a, e, 1)) {
					return false;
				}
			}
		}
		else {
			if (ch == s[a]) return false;
		}
	}
	return true;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t, c = 1; cin >> t;
	string root;
	while (t--) {
		int n; cin >> n;
		for (int i = 0; i < n; i++) {
			string a, b; cin >> a >> b;
			if (m.empty()) root = a;
			m[a].insert(b);
			m[b].insert(a);
		}
		bool a = dfs(root, "", 1); s.clear();
		bool b = dfs(root, "", 2); s.clear();
		cout << "#" << c++ << " ";
		if (a || b) cout << "Yes" << "\n";
		else cout << "No" << "\n";
		m.clear();
	}
	return 0;
}