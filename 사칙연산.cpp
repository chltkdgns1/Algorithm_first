#include <iostream>
using namespace std;
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		long long a, b, c;
		bool flag = 0;
		char d, e;
		cin >> a >> d >> b >> e >> c;
		switch (d) {
		case '+':
			if (a + b == c) flag = 1;
			break;
		case '*':
			if (a * b == c) flag = 1;
			break;
		case '-':
			if (a - b == c) flag = 1;
			break;
		case '/':
			if (a / b == c) flag = 1;
			break;
		}
		if (flag) cout << "correct" << "\n";
		else cout << "wrong answer" << "\n";
	}
}