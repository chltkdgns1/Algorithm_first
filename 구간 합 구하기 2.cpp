#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;
typedef long long ll;
vector <ll> tree(5000001);
ll lazy[5000001];
int v[1000000];

char buf[1 << 17];
inline char read()
{
	static int idx = 1 << 17;
	if (idx == 1 << 17)
	{
		fread(buf, 1, 1 << 17, stdin);
		idx = 0;
	}
	return buf[idx++];
}
inline ll readInt()
{
	ll sum = 0;
	bool sig = 1;
	char now = read();

	while (now == 10 || now == 32) now = read();
	if (now == '-') sig = 0, now = read();
	while (now >= 48 && now <= 57)
	{
		sum = sum * 10 + now - 48;
		now = read();
	}
	return sig ? sum : -sum;
}

ll init(int s, int e, int node) {
	if (s == e) return tree[node] = v[s];
	int m = (s + e) / 2;
	return tree[node] = init(s, m, node * 2) + init(m + 1, e, node * 2 + 1);
}
void calLazy(int s, int e, int node) {
	if (lazy[node]) {
		tree[node] += lazy[node] * (e - s + 1);
		if (s != e) {
			lazy[node * 2] += lazy[node];
			lazy[node * 2 + 1] += lazy[node];
		}
		lazy[node] = 0;
	}
}
ll updata(int s, int e, int node, int le, int re, ll d) {
	calLazy(s, e, node);
	if (e < le || re < s) return tree[node];
	if (le <= s && e <= re) {
		tree[node] += d * (e - s + 1);
		if (s != e) {
			lazy[node * 2] += d;
			lazy[node * 2 + 1] += d;
		}
		return tree[node];
	}
	int m = (s + e) / 2;
	return tree[node] = updata(s, m, node * 2, le, re, d) + updata(m + 1, e, node * 2 + 1, le, re, d);
}
ll query(int s, int e, int node, int le, int re) {
	calLazy(s, e, node);
	if (e < le || re < s) return 0;
	if (le <= s && e <= re) return tree[node];
	int m = (s + e) / 2;
	return query(s, m, node * 2, le, re) + query(m + 1, e, node * 2 + 1, le, re);
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, m, k; n = readInt(), m = readInt(), k = readInt();
	for (int i = 0; i < n; i++) v[i] = readInt();
	init(0, n - 1, 1);
	ll a, b, c, d;
	for (int i = 0; i < m + k; i++) {
		a = readInt(), b = readInt(), c = readInt();
		if (a == 1) {
			d = readInt();
			updata(0, n - 1, 1, b - 1, c - 1, d);
		}
		else cout << query(0, n - 1, 1, b - 1, c - 1) << "\n";
	}
}