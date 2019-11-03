#include <iostream>
#include <unordered_set>
#include <string>
using namespace std;

unordered_set <string> s;
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int a, b; cin >> a >> b; 
	string e;
	for (int i = 0; i < a; i++) {
		cin >> e;
		s.insert(e);
	}
	int cnt = 0;
	for (int i = 0; i < b; i++) {
		cin >> e;
		if (s.find(e) != s.end()) cnt++;
	}
	cout << cnt << "\n";
}