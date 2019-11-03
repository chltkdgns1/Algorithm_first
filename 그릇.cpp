#include <iostream>
#include <string>
using namespace std;
int main() {
	string s;
	cin >> s;
	char c;
	int t = 0;
	for (int i = 0; i < s.length(); i++) {
		if (!i) {t += 10;c = s[i];}
		else {
			if (c != s[i]) {t += 10;c = s[i];}
			else t += 5;
		}
	}
	cout << t << "\n";
}