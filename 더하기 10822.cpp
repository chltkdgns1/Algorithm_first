#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	string s, t;
	cin >> s;
	int res = 0;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] != ',' ) t += s[i];
		else res += stoi(t), t.clear();
		if (i == s.length() - 1) res += stoi(t);
	}
	cout << res << "\n";
}