#include <iostream>
#include <string>
#include <list>
#include <algorithm>
using namespace std;
list <string> s;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while (t--) { 
		s.clear();
		int e;
		string p, n, t;
		cin >> p >>e>> n;
		for (int i = 0; i < n.length(); i++) {
			if (n[i] != '[' && n[i] != ']' && n[i] != ',') {
				t += n[i];
			}
			else {
				if (!t.empty()) {
					s.push_back(t);
					t.clear();
				}
			}
		}
		int fb = 0; //  0 이면 앞부터 읽기 1 이면 뒤부터 읽기
		bool br = 0;
		for (int i = 0; i < p.length(); i++) {
			if (p[i] == 'R') fb = fb ^1;
			if (p[i] == 'D') {
				if (s.empty()) {
					cout << "error\n";
					br = 1;
					break;
				}
				if (!fb) s.pop_front();
				else s.pop_back();
				
			}
		}
		if (br) continue;
		int i = 0;
		if (s.empty()) {
			cout << "[]\n";
			continue;
		}
		if (fb) reverse(s.begin(), s.end());
		for (auto a : s) {
			if (!i) cout << "[";
			if (i == s.size() - 1) cout << a << "]\n";
			else cout << a << ",";
			i++;
		}
	}
}