#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
string sir[1000];
bool cmp(const string &a, const string &b) {
	if (a.length() == b.length()) {
		int acnt = 0, bcnt = 0;
		for (int i = 0; i < a.length(); i++) {
			if(a[i]>=48 && a[i]<=57) acnt += a[i] - 48;
		}
		for (int i = 0; i < b.length(); i++) {
			if (b[i] >= 48 && b[i] <= 57) bcnt += b[i] - 48;
		}
		if (acnt == bcnt) return a < b;
		else return acnt < bcnt;
	}
	else return a.length() < b.length();
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> sir[i];
	}
	sort(sir, sir + n, cmp);
	for (int i = 0; i < n; i++) {
		cout << sir[i] << "\n";
	}
}