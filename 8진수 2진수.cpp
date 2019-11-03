#include <iostream>
#include <string>
using namespace std;
string d[8] = { "000","001","010","011","100","101","110","111" };
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	string s, t;
	cin >> s;
	if (s == "0") {
		cout << 0 << "\n";
		return 0;
	}
	for (int i = 0; i < s.length(); i++) t += d[s[i] - 48];
	for (int i = 0; i < t.length(); i++) {
		if (t[i] != '0') break;
		t.erase(i, 1);
		i--;
	}
	cout << t << "\n";
	system("pause");
}