#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t; cin >> t;
	while (t--) {
		bool visit[10] = { 0 };
		string s; cin >> s;
		for (int i = 0; i < s.length(); i++) {
			visit[s[i] - 48] = 1;
		}
		int cnt = 0;
		for (int i = 0; i < 10; i++) if (visit[i]) cnt++;
		cout << cnt << "\n";
	}
}