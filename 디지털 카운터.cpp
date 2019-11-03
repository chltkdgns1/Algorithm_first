#include <iostream>
#include <string>
#include <math.h>
typedef long long ll;
using namespace std;

int arr[10] = { 6,2,5,5,4,5,6,3,7,5 };
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	string s; cin >> s;
	int t = 0,n = s.length();
	for (int i = 0; i < n; i++) t += arr[s[i] - 48];
	int r = stoi(s);
	ll a = pow(10, n);
	for (int i = 1; i <= a; i++) {
		ll d = ((r + i) % a);
		cout << d << "\n";
		string e = to_string(d);
		int q = 0;
		for (int i = 0; i < (n - e.length()); i++) q += arr[0];
		for (int i = 0; i < e.length(); i++) q += arr[s[i] - 48];
		if (q == t) {
			cout << i << "\n";
			break;
		}
	}
	system("pause");
}