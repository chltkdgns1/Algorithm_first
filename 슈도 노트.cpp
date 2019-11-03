#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int pi[200001];
int ppi[200001];
void getpi(string s,int *pi) {
	int c = 0;
	for (int i = 1; i < s.length(); i++) {
		if (s[i] == s[c]) pi[i] = ++c;
		else if (c) {
			c = pi[c - 1];
			i--;
		}
	}
}

int rev(int t,string s) {
	return s.length() - t - 1;
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	string s; cin >> s;
	getpi(s,pi);
	reverse(s.begin(), s.end());
	getpi(s,ppi);


	for (int i = 0; i < s.length(); i++) {
		cout << pi[i] << " ";
	}
	system("pause");
	int h = 0;
	for (int i = s.length() - 2; i >= 0; i--) {
		int a, b, c, d;
		a = 0, b = pi[i] - 1, c = i - pi[i] + 1, d = i;

		for (int t = rev(c,s) + s.length() - 1 - d;t >= rev(c,s) + 1 ; t--) {
			if (ppi[t] == t - rev(c, s)) {
				h = max(h, min(pi[i], ppi[t]));
				break;
			}
		}
	}
	cout << h << "\n";
	system("pause");
}