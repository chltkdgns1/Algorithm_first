#include <iostream>
#include <string>
#include <math.h>
using namespace std;

char d[17] = { '0','1','2','3','4','5', '6','7','8','9','A','B' ,'C','D','E','F' };
int main() {
	string s;
	cin >> s;
	long long t = 0;
	for (int i = 0; i < s.length(); i++) {
		for (int k = 0; k < 16; k++) {
			if (s[i] == d[k]) {
				t += k * pow(16, s.length() -1 - i);
				break;
			}
		}
	}
	cout << t << "\n";
}
