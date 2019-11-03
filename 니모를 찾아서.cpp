#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector <string> v;
void dfs(int index,string s) {
	if (index == s.length()) {
		v.push_back(s);
		return;
	}
	s[index] -= 32;
	dfs(index + 1, s);
	s[index] += 32;
	dfs(index + 1, s);
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	dfs(0, "nemo");
	while (1) {
		string s,e; getline(cin, s);
		if (s == "EOI") break; 
		bool ch = 0;
		for (int i = 0; i < v.size(); i++) {
			if (s.find(v[i]) != string::npos) {
				ch = 1; break;
			}
		}
		if (ch) cout << "Found" << "\n";
		else cout << "Missing" << "\n";
	}
}