#include <iostream>
#include <algorithm>
using namespace std;

char s[200001];
int idx[200001], g[200001], tg[200001], t, r[200001];

bool cmp(int x, int y) {
	if (g[x] == g[y]) {
		return g[x + t] < g[y + t];
	}
	return g[x] < g[y];
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	cin >> s;

	for (int i = 0; i < n; i++) {
		idx[i] = i;
		g[i] = s[i] - 'a';
	}

	g[n] = -1;
	t = 1;
	while (t <= n) {
		sort(idx, idx + n, cmp);
		tg[idx[0]] = 0;

		for (int i = 1; i < n; i++) {
			if (cmp(idx[i - 1], idx[i])) tg[idx[i]] = tg[idx[i - 1]] + 1;
			else tg[idx[i]] = tg[idx[i - 1]];
		}

		for (int i = 0; i < n; i++) g[i] = tg[i];
		t <<= 1;
	}

	int len = 0, res = 0;

	for (int i = 0; i < n; i++) r[idx[i]] = i;
	
	for (int i = 0; i < n; i++) {
		int k = r[i];

		if (k) {
			int t = idx[k - 1];
			while (s[i + len] == s[t + len]) len++;
			res = max(res, len);
			if(len) len--;
		}
	}
	cout << res << "\n";
}