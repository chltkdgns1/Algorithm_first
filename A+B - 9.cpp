#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int Len(string a) {
	if (a[0] == '-') return a.length() - 1;
	return a.length();
}
string bigSum(string a, string b) {
	string t, s1, s2;
	bool c = 0, d = 0;
	if (Len(a) > Len(b)) s1 = a, s2 = b;
	else s1 = b, s2 = a;
	if (s1[0] == '-') {s1.erase(0, 1);c = 1;}
	if (s2[0] == '-') {s2.erase(0, 1);d = 1;}
	if (s1.length() == s2.length()) {
		for (int i = 0; i < s1.length(); i++) {
			if (s1[i] < s2[i]) {
				bool e_temp = c;
				c = d;
				d = e_temp;
				string e = s1;
				s1 = s2;
				s2 = e;
				break;
			}
			else if (s1[i] > s2[i]) break;
		}
	}
	int num = 0, mcnt = 0;
	while (!s1.empty() || !s2.empty()) {
		if ((c && !d) || (!c && d)) {
			if (s2.empty()) num = s1.back() - 48 - mcnt;
			else num = s1.back() - 48 - (s2.back() - 48) - mcnt;
			mcnt = 0;
			if (num < 0) { 	num += 10;	mcnt++;}
			t += num + 48;
			s1.pop_back();
			if (!s2.empty()) s2.pop_back();
			num = 0;
		}
		else {
			if (s2.empty()) num += s1.back() - 48;
			else num += s1.back() - 48 + s2.back() - 48;
			t += num % 10 + 48; 
			s1.pop_back(); 
			if (!s2.empty()) s2.pop_back();
			num /= 10;
		}
	}
	if (num) t += num + 48;
	reverse(t.begin(), t.end());
	for (int i = 0; i < t.length(); i++) {
		if (t[i] == '0') {
			t.erase(i, 1);
			i--;
		}
		else break;
	}
	if ((c == d && !c) || (c != d && !c)) {
		if (t.empty()) t += '0';
		return t;
	}
	else if ((c == d && c) || c != d && c) {
		if(!t.empty()) t.insert(0, "-");
		else t += '0';
		return t; 
	}
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	string a, b;
	cin >> a >> b;
	cout << bigSum(a, b) << "\n";
}