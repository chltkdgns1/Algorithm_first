#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	string s; cin >> s;
	int d = 0;
	for (int i = 1; i < s.length(); i++) {
		int e = s[i] - 48 - (s[i - 1] - 48);
		if (i == 1) d = e;
		else {
			if (d != e) {
				cout<<"흥칫뿡!! <(￣ ﹌ ￣)>";
				return 0;
			}
		}
	}
	cout << "◝(⑅•ᴗ•⑅)◜..°♡ 뀌요미!!";
}