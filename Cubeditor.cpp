#include <iostream>
#include <string>
#include <string.h>
using namespace std;
int pi[5000];
void getpi(string a) {
	int b = 0;
	for (int i = 1; i < a.length(); i++) {
		pi[i] = 0;
		if (a[i] == a[b]) pi[i] = ++b;
		else if (b) i--, b = pi[b - 1];
	}
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	string a; cin >> a;
	int max = 0;
	for (int i = 0; i < a.length(); i++) {
		string b; b += a[i];
		for (int k = i + 1 ; k < a.length(); k++) b += a[k];
		getpi(b);
		for (int i = 0; i < b.length(); i++) {
			if (max < pi[i]) max = pi[i];
		}
	}
	cout << max << "\n";
}