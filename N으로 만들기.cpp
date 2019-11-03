#include <iostream>
#include <set>
#include <string>
#include <queue>
using namespace std;
deque <char> q;
string s;
int res;
set <string> r;
void dfs(int left, int right, string w) {
	if (left == -1 && right == s.length()) {
		if (r.find(w) == r.end()) res++,r.insert(w);
		return;
	}
	string e = w;
	if (right < s.length()) {
		q.push_back(s[right]);
		for (auto a : q) e += a;
		dfs(left, right + 1,e);
		q.pop_back();
	}
	e = w;
	if (left >= 0) {
		q.push_front(s[left]);
		for (auto a : q) e += a;
		dfs(left - 1, right,e);
		q.pop_front();
	}
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> s;
	for (int i = 0; i < s.length(); i++) {
		q.push_back(s[i]);
		string e; e += s[i];
		dfs(i - 1,i + 1,e);
		q.pop_back();
	}
	cout << res << "\n";
}