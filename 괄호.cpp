#include <iostream>
#include <string>
#include <stack>
using namespace std;
stack <char> d;
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int k = 0; k < s.length(); k++) {
			if (d.empty()) {
				d.push(s[k]);
				continue;
			}
			if (s[k] == ')') {
				if (d.top() == '(') d.pop();
				else d.push(s[k]);
			}
			else d.push(s[k]);
		}
		if (d.size() == 0) cout << "YES" << "\n";
		else {
			while (!d.empty()) d.pop();
			cout << "NO" << "\n";
		}
	}
}