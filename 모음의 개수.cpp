#include <iostream>
#include <string>
using namespace std;

char d[10] = { 'a','e','i','o','u','A','E','I','O','U' };
int main() {
	string s;
	while (1) {
		getline(cin, s);
		if (s == "#") break;
		int cnt = 0;
		for (int i = 0; i < s.length(); i++) {
			for (int k = 0; k < 10; k++) {
				if (s[i] == d[k]) {
					cnt++;
					break;
				}
			}
		}
		cout << cnt << "\n";
	}
}