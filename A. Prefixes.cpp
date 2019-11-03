#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	string s; cin >> s;
	int a = 0, b = 0, c, d, cnt = 0;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == 'a') a++, c = i;
		else b++, d = i;

		if ((i % 2)) {
			if (a > b) s[c] = 'b',cnt++;
			else if (a < b) s[d] = 'a',cnt++;
			a = 0, b = 0;
		}
	}
	cout << cnt << "\n";
	cout << s << "\n";
	system("pause");
}