#include <iostream>
#include <string>
#include <string.h>
#include <vector>
using namespace std;

int pi[1000001];
void getpi(string s) {
	int m = s.length();
	for (int i = 1, mat = 0; i < m; ++i) {
		if (s[i] == s[mat]) {
			pi[i] = ++mat;
		}
		else if (mat != 0) {
			--i;
			mat = pi[mat - 1];
		}
	}
}

int kmp(string a, string b, vector <int> &v) {
	int n = a.length(), m = b.length(), j = 0; 
	for (int i = 0; i < n; i++) { 
		while (j > 0 && a[i] != b[j]) j = pi[j - 1];
		if (a[i] == b[j]) { 
			if (j == m - 1) { 
				v.push_back(i - m + 1);
				j = pi[j];
			}
			else j++; 
		}
	}	
	return v.size();
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	vector <int> v;
	string a, b; getline(cin, a); getline(cin, b);
	getpi(b); 
	cout << kmp(a, b,v) << "\n";
	for (auto a : v)cout << a + 1 << "\n";
}