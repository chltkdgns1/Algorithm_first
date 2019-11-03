#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int cnt = 0;
	while (1) {
		int a, b; string c;
		cin >> a >> c >> b;
		if (c == "E") break;
		cout << "Case " << ++cnt << ": ";
		if (c == ">") {
			if (a > b) cout << "true\n";
			else cout << "false\n";
		}
		else if (c == "<") {
			if (a < b) cout << "true\n";
			else cout << "false\n";
		}
		else if (c == ">=") {
			if (a >= b) cout << "true\n";
			else cout << "false\n";
		}
		else if (c == "<=") {
			if (a <= b) cout << "true\n";
			else cout << "false\n";
		}
		else if (c == "==") {
			if (a == b) cout << "true\n";
			else cout << "false\n";
		}
		else if (c == "!=") {
			if (a != b) cout << "true\n";
			else cout << "false\n";
		}
	}
}