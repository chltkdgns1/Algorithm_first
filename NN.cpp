#include <iostream>
#include <string>
using namespace std;int main() {
	int n,m; cin >> n>>m;
	string s;
	for (int i = 0; i < n; i++) s += to_string(n);
	if (s.length() <m) cout << s << "\n";
	else for (int i = 0; i < m; i++) cout << s[i];
}