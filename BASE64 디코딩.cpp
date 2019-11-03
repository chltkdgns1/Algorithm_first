#include <iostream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;
map <char, char> m;

string input(int a) {
	int b = 1, re = 0, c = 0;
	string d;
	while (a) {
		if (a & 1) {
			re += b;
		}
		b *= 2; a >>= 1; c++;
		if (c == 8) {
			if (re)d += re;
			c = 0, b = 1;
			re = 0;
		}
	}
	d += re;
	reverse(d.begin(), d.end());
	return d;
}

int main() {
	string s, res; cin >> s;
	for (char i = 65; i <= 90; i++) m[i] = i - 65;
	for (char i = 97; i <= 122; i++) m[i] = i - 71;
	for (char i = 48; i <= 57; i++) m[i] = i + 4;
	m['+'] = 62, m['/'] = 63;

	long long  cnt = 0, a = 0;
	for (int i = 0; i < s.length(); i++) {
		a <<= 6; 
		if (s[i] != '=') a += m[s[i]];
		cnt++;
		if (cnt == 4) {
			res += input(a); cnt = 0, a = 0;
		}
	}
	cout << res << "\n";
}
