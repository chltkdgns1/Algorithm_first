#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Data {
public:
	vector <int> alpa;
	int t;
	Data() {alpa.resize(26);}
};

string ss;
vector <Data> tree(400000);

void update(int node, int s, int e,int d,int q) {
	if (d < s || e < d) return;

	if (s == e) {
		tree[node].alpa[q]++;
		return;
	}
	int m = (s + e) / 2;
	tree[node].alpa[q]++;
	update(node * 2, s, m,d,q), update(node * 2 + 1, m + 1, e,d,q);
}

void change(int node, int s, int e, int d, int q) {
	if (d < s || e < d) return;

	if (s == e) {
		tree[node].alpa[ss[d] - 'a']--;
		tree[node].alpa[q]++;
		return;
	}
	int m = (s + e) / 2;
	tree[node].alpa[ss[d] - 'a']--;
	tree[node].alpa[q]++;
	change(node * 2, s, m, d, q), change(node * 2 + 1, m + 1, e, d, q);
}

vector <int> sum(int node, int s, int e, int l, int r) {
	if (r < s || e < l) {
		vector <int> b;
		return b;
	}

	if (l <= s && e <= r) return tree[node].alpa;

	int m = (s + e) / 2;
	vector <int> a = sum(node * 2, s, m, l,r), b = sum(node * 2 + 1, m + 1, e, l,r);
	vector <int> c;

	if (a.size() && b.size()) {
		for (int i = 0; i < 26; i++) c.push_back(a[i] + b[i]);
		return c;
	}
	else if (a.size()) return a;
	else return b;
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> ss;
	int len = ss.length();
	for (int i = 0; i < len; i++) {
		update(1, 0, len - 1, i, ss[i] - 'a');
	}

	int q; cin >> q;
	while (q--) {
		int a, b, d;
		char c;
		cin >> a >> b;
		if (a == 1) {
			cin >> c;
			change(1, 0, len - 1, b - 1, c - 'a');
			ss[b - 1] = c;
		}
		else {
			cin >> d;
			vector <int> e = sum(1, 0, len - 1, b - 1, d - 1);
			int cnt = 0;
			for (auto a : e) {
				if (a)cnt++;
			}
			cout << cnt << "\n";
		}
	}
}
