#include <iostream>
#include <string>
#include <stack>
using namespace std;
int main() {
	stack <int> s;
	string e;
	cin >> e;
	for (int i = 0; i < e.length(); i++) {
		int t = 0;
		if (e[i] == '(') s.push(-1);
		else if (e[i] == '[') s.push(-3);
		else if (e[i] == ')') {
			if (s.empty()) {cout << 0;return 0;}
			while (s.top() != -1) {
				t += s.top();
				s.pop();
				if (s.empty()) {cout << 0;return 0;}
			}
			if (!t) t = 2;
			else t *= 2;
			s.pop();
			s.push(t);
		}
		else {
			if (s.empty()) {cout << 0;return 0;}
			while (s.top() != -3) {
				t += s.top();
				s.pop();
				if (s.empty()) {cout << 0;return 0;}
			}
			if (!t) t = 3;
			else t *= 3;
			s.pop();
			s.push(t);
		}
	}
	int t = 0;
	while (!s.empty()) {
		if (s.top() == -1 || s.top() == -3) {
			cout << 0; return 0;
		}
		t += s.top();
		s.pop();
	}
	cout << t << "\n";
}