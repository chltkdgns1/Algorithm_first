#include <iostream>
#include <string>
using namespace std;
int d[11];
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		if (s == "6174") {
			cout << 0 << "\n";
			continue;
		}
		int cnt = 0;
		while (1) {
			string a, b;
			for (int i = 0; i < s.length(); i++) d[s[i] - 48]++;
			for (int i = 0,r = 9; i < 10; i++,r--) {
				for (int k = 0; k < d[i]; k++) a += i + 48;
				for (int k = 0; k < d[r]; k++) b += r + 48;
			}
			cnt++;
			int e = stoi(b) - stoi(a);
			string t1,t2 = to_string(e);
			for (int i = 0; i < 4 - to_string(e).length(); i++) t1 += '0';
			t2.insert(0, t1);
			for (int i = 0; i < 10; i++) d[i] = 0;
			if (e == 6174) {
				cout << cnt << "\n";
				break;
			}
			s = t2;	
		}
	}
}