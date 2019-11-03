#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
using namespace std;

unordered_map<string, int> e;
string s[500001];
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> s[i];
		e[s[i]]++;
	}
	int cnt = 0;
	vector <string> r;
	for (int i = 0; i < m; i++) {
		if (e[s[i]] >= 2) e[s[i]]--;
		else {
			e[s[i]]--, cnt++;
			r.push_back(s[i]);
			if (cnt == n) break;
		}
	}
	for (int i = 0; i < r.size(); i++) cout << r[i] << "\n";
}