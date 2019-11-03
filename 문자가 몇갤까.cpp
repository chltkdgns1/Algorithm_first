#include <iostream>
#include <string>
using namespace std;
int check[26];
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	while (1) {
		string s; 
		getline(cin, s);
		if (s == "#") break;
		for (int i = 0; i < s.length(); i++) {
			if (s[i] >= 65 && s[i] <= 90) check[s[i] - 65] = 1;
			else if (s[i] >= 97 && s[i] <= 122) check[s[i] - 97] = 1;
		}
		int cnt = 0;
		for (int i = 0; i < 26; i++) {
			if (check[i]) cnt++;
			check[i] = 0;
		}
		cout << cnt << "\n";
	}
}