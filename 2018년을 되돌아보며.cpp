#include <iostream>
#include <string>
using namespace std;
int d[10];
int main() {
	string s;
	cin >> s;
	for (int i = 0; i < s.length(); i++) d[s[i] - 48]++;
	int check = 0;
	for (int i = 0; i < 10; i++) {
		if (d[i]) {
			if (i != 2 && i != 0 && i != 1 && i != 8) {
				cout << 0;
				return 0;
			}		
		}
	}
	if (d[2] && d[0] && d[1] && d[8]) {
		if (d[2] == d[0] && d[0] == d[1] && d[0] == d[8]) {
			cout << 8;
		}
		else cout << 2;
	}
	else cout << 1;
}