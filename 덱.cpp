#include <iostream>
#include <deque>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	deque <int> q;
	for (int i = 0; i < n; i++) {
		string s;
		int a;
		cin >> s;
		if (s == "push_back") {
			cin >> a;
			q.push_back(a);
		}
		else if (s == "push_front") {
			cin >> a;
			q.push_front(a);
		}
		else if (s == "pop_front") {
			if (q.empty()) cout << -1 << "\n";
			else {
				cout << q.front() << "\n";
				q.pop_front();
			}
		}
		else if (s == "pop_back") {
			if (q.empty()) cout << -1 << "\n";
			else {
				cout << q.back() << "\n";
				q.pop_back();
			}
		}
		else if (s == "size") {
			cout << q.size() << "\n";
		}
		else if (s == "empty") {
			cout << q.empty() << "\n";
		}
		else if (s == "front") {
			if (q.empty()) cout << -1 << "\n";
			else cout << q.front() << "\n";
		}
		else {
			if (q.empty()) cout << -1 << "\n";
			else cout << q.back() << "\n";
		}
	}
}