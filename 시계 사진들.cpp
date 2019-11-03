#include <iostream>
#include <string>
#include <string.h>
using namespace std;
char arr[360001], brr[720000];
int pi[360000];
void getpi(string s) {
	int a = 0;
	for (int i = 1; i < s.length(); i++) {
		if (s[i] == s[a]) pi[i] = ++a;
		else if (a) i--, a = pi[a - 1];
	}
}
bool kmp(string s) {
	int c = 0;
	for (int i = 0; i<720000; i++) {
		if (brr[i] == s[c]) {
			c++;
			if (c == s.length()) {
				return true;
			}
		}
		else if (c) i--, c = pi[c - 1];
	}
	return false;
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, a; cin >> n;
	int max = -1, min = 987654321;
	bool ch = 0;
	for (int i = 0; i < n; i++) {
		cin >> a; arr[a] = '1';
		if (max < a) max = a;
		if (min > a) min = a;
	}
	string s, e;
	for (int i = 0; i < n; i++) {
		cin >> a, brr[a] = '1';
		brr[a + 360000] = '1';
	}
	for (int k = min; k <= max; k++) s += arr[k];
	getpi(s);
	bool res = kmp(s);
	if (res) cout << "possible" << "\n";
	else cout << "impossible" << "\n";
}