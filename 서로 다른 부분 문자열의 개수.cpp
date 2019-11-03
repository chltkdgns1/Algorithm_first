#include <iostream>
#include <string>
#include <set>
using namespace std;

set <string> e;
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	string a; cin >> a; 
	int cnt = 0;
	for (int i = 0; i < a.length(); i++) {
		string s; s += a[i];
		if (e.find(s) == e.end()) e.insert(s), cnt++;
		for (int k = i + 1; k < a.length(); k++) {
			s += a[k];
			if (e.find(s) == e.end()) e.insert(s), cnt++;
		}
	}
	cout << cnt << "\n";
}