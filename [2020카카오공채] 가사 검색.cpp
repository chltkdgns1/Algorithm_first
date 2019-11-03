#include <iostream>
#include <string>
#include <vector>
#include <string.h>
#include <map>
#include <algorithm>
using namespace std;


int toNum(char a) {
	if (a == '?') return 26;
	return a - 'a';
}

class node {
public:
	node *next[27];
	int cnt;
	node() {
		cnt = 0;
		memset(next, 0, sizeof(next));
	}
	void insert(string &s, int idx) {
		if (s.length() == idx) return;
		int t = toNum(s[idx]);
		if (next[t] == NULL) next[t] = new node();
		next[t]->insert(s, idx + 1);
	}

	void find(string &s, int idx) {
		if (s.size() == idx) {
			cnt++;
			return;
		}
		int a = toNum('?'), b = toNum(s[idx]);
		if (next[a] != NULL) next[a]->find(s, idx + 1);
		if (next[b] != NULL) next[b]->find(s, idx + 1);
	}

	int get(string &s, int idx) {
		if (s.length() == idx) {
			return cnt;
		}

		int t = toNum(s[idx]);
		if (next[t] == NULL) return 0;
		return next[t]->get(s, idx + 1);
	}
};

vector<int> solution(vector<string> v, vector<string> r) {
	node *aa = new node();
	vector<int> ans;
	int d;
	for (auto a : r) aa->insert(a, 0);
	
	for (auto a : v) aa->find(a, 0);
	
	for (auto a : r) ans.push_back(aa->get(a, 0));
	return ans;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, q; cin >> n >> q;
	vector <string> v, r;
	while (n--) {
		string s; cin >> s;
		v.push_back(s);
	}

	while (q--) {
		string s; cin >> s;
		r.push_back(s);
	}

	solution(v, r);
}