#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
	string a;
	stack <char> s;
	while (1) {
		ios::sync_with_stdio(false); cin.tie(NULL);
		getline(cin, a);
		if (a == ".") break;
		for (int i = 0; i < a.length(); i++) {
			if (a[i] == '[' || a[i] == '(') s.push(a[i]);
			else if (a[i] == ']' || a[i] == ')') {
				if (!s.empty()) {
					if ((s.top() == '(' && a[i] == ')') || s.top() == '[' && a[i] == ']') s.pop();
					else s.push(a[i]);
				}
				else s.push(a[i]);
			}
		}
		if (s.empty()) cout << "yes" << "\n";
		else {
			while (!s.empty()) s.pop();
			cout << "no" << "\n";
		}
	}
}