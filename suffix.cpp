#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

char s[1001];
int t, g[1001], tg[1001], idx[1001];

bool cmp(int x, int y) {
	if (g[x] == g[y]) {
		return g[x + t] < g[y + t];
	}
	return g[x] < g[y];
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> s;

	int n = strlen(s);

	for (int i = 0; i < n; i++) {
		g[i] = s[i] - 'a';
		idx[i] = i;
	}

	t = 1;
	g[n] = -1;
	while(t <= n){
		sort(idx, idx + n, cmp);
		tg[idx[0]] = 0;

		for (int i = 1; i < n; i++) {
			if (cmp(idx[i - 1], idx[i])) {
				tg[idx[i]] = tg[idx[i - 1]] + 1;
			}
			else
				tg[idx[i]] = tg[idx[i - 1]];
		}

		for (int i = 0; i < n; i++) {
			g[i] = tg[i];
		}

		t <<= 1;
	}

	for (int i = 0; i < n; i++) {
		cout << s + idx[i] << "\n";
	}
	system("pause");
}