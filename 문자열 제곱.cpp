#include <iostream>
#include <string>
#include <string.h>
using namespace std;

int getpi[1000001];
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	string s;
	while(1){
		cin >> s;
		if (s == ".") break;

		int c = 0, n = s.length();

		bool ch = 0;
		for (int i = 2; i*i <= n; i++) {
			if (!(n % i)) {
				ch = 1;
				break;
			}
		}
		if (!ch) {
			bool cch = 0;
			for (int i = 1; i < n; i++) {
				if (s[i] != s[i - 1]) {
					cch = 1;
					break;
				}
			}
			if(cch) cout << 1 << "\n";
			else cout << n << "\n";
			continue;
		}

		for (int i = 1; i < n; i++) {
			if (s[i] == s[c]) getpi[i] = ++c;
			else if (c) {
				c = getpi[c - 1];
				i--;
			}
		}
		
		cout << n / (n - getpi[n - 1]) << "\n";
		memset(getpi, 0, sizeof(getpi));
	}
}