#include <iostream>
#include <string>
using namespace std;
int arr[26];
string t = "UCPC";
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	string s; getline(cin, s);
	int cnt = 0;
	string res;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] >= 65 && s[i] <= 90) {
			if (s[i] == t[cnt]) {
				res += s[i];
				cnt++;
				if (cnt == 4) break;
			}
		}
	}
	if (t == res) cout << "I love UCPC";
	else cout << "I hate UCPC";
}