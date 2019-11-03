#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t; cin >> t;
	cin.ignore();
	int cnt = 1;
	while (t--) {
		string s; getline(cin, s);
		string res;
		for (int i = 0; i < s.length(); i++) {
			if (!i) res += s[i] - 32;
			else if (s[i - 1] == ' ') res += s[i] - 32;
		}
		cout << "#"<<cnt++<<" "<<res << "\n";
	}
	system("pause");
}