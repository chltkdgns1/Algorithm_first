#include <iostream>
#include <string>
#include <vector>
using namespace std;
vector <string> v;
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	string s,t; cin >> s;
	int sz = 0;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '*') {
			if(!t.empty()) sz += t.length(),v.push_back(t);
			v.push_back("*");
			t.clear();
		}
		else {
			t += s[i];
			if (i == s.length() - 1) sz += t.length(),v.push_back(t);
		}	
	}
	int n; cin >> n;
	int len = v.size() - 1;
	for (int i = 0; i < n; i++) {
		int cnt = 0, check = 0;
		string a; cin >> a;
		if (a.length() < sz) continue;
		bool br = 0;
		int start = 0, end = a.length() - 1;
		if (v[0] != "*") {
			for (int k = 0; k < v[0].size(); k++) {
				if (v[0][k] != a[k]) { br = 1; break;}
			}
			if (br) continue;
			start = v[0].size();
			cnt++;
		}
		if (v[len] != "*") {
			for (int k = 0; k < v[len].size(); k++) {
				if (v[len][v[len].size() - 1 - k] != a[a.length() - 1 - k]) {br = 1; break;}
			}
			if (br) continue;
			end -= (v[len].size());
			check = 1;
		}
		bool b = 0;
		for (int i = cnt; i < v.size() - 1 - check; i++) {
			if (v[i] == "*") continue;
			for (int k = start; k <= end; k++) {
				if (v[i][0] == a[k]) {
					bool br = 0;
					for (int z = 0; z < v[i].size(); z++) {
						if (v[i][z] != a[k + z]) { br = 1; break; }
					}
					if (!br) {
						start = k + v[i].size() - 1;
						break;
					}
				}
				if (k == end) { b = 1; break;}
			}
			if (b) break;
		}
		if (b) continue;
		cout << a << "\n";
	}
}