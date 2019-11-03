#include <iostream>
#include <string>
using namespace std;
int main() {
	string s,a; cin >> s;
	if (s == "0") { cout << 1; return 0; }
	for (int i = 0; i < s.length(); i++) a += '1';
	if (stoi(s) >= stoi(a)) cout << s.length();
	else cout << s.length() - 1;
}