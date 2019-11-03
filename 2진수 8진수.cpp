#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string d[9] = { "000","001","010","011","100","101","110","111" };
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	string s, t, res;
	cin >> s;
	int cnt = 0;
	if (s.length() % 3 == 1) s.insert(0,"00");
	if (s.length() % 3 == 2) s.insert(0, "0");
	for (int i = s.length() - 1; i >= 0; i--) {
		cnt++;
		t += s[i];
		if (cnt == 3) {
			cnt = 0;
			reverse(t.begin(), t.end());
			for (int i = 0; i < 8; i++) {
				if (d[i] == t) {res += i + 48;break;}
			}
			t.clear();
		}
	}
	reverse(res.begin(), res.end());
	cout << res << "\n";
}