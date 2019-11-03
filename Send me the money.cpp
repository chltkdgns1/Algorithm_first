#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, m; cin >> n >> m;
	string e; cin >> e;
	for (int i = 0; i < m; i++) {
		string s; cin >> s;
		int cnt = 0;
		for (int k = 0; k < s.length(); k++) {
			if (e[cnt] == s[k]) cnt++;
		}
		if (cnt == e.length()) cout << "true" << "\n";
		else cout << "false" << "\n";
	}
}