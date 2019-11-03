#include <iostream>
#include <map>
#include <string>
using namespace std;

map <string, int>  m;
string alpa[26] = { "A","B" ,"C" ,"D" ,"E" ,"F" ,"G" ,"H" ,"I" ,"J" ,"K" ,"L" ,"M",
"N" ,"O" ,"P" ,"Q" ,"R" ,"S" ,"T" ,"U" ,"V" ,"W" ,"X","Y","Z" };
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	for (int i = 0; i < 26; i++) m[alpa[i]] = i + 1;

	string s,t; cin >> s;

	int key = 27;

	for (int i = 0; i < s.length(); i++) {
		t += s[i];
		if (!m[t]) {
			string b;
			for (int i = 0; i < t.length() - 1; i++) b += t[i];
			cout<<
		}
	}

	system("pause");
}