#include <iostream>
#include <string>
using namespace std;
int pi[1000000];
void getpi(string s) {
	int a = 0;
	for (int i = 1; i < s.length(); i++) {
		if (s[i] == s[a]) pi[i] = ++a;
		else if (a) i--, a = pi[a - 1];
	}
}
int main(){
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n; string s; cin >> n >> s;
	getpi(s);
	cout << n - pi[n - 1] << "\n";
}