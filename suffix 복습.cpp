#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

char arr[500001];
int g[500001], tg[500001], idx[500001];
int lcp[500001], ranks[500001];
int t;
bool cmp(int a, int b) {
	if (g[a] == g[b]) {
		return g[a + t] < g[b + t];
	}
	return g[a] < g[b];
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> arr;

	int n = strlen(arr);
	for (int i = 0; i < strlen(arr); i++) {
		g[i] = arr[i] - 'a';
		idx[i] = i;
	}


	t = 1;
	g[n] = -1;
	while (t <= n) {

		sort(idx, idx + n, cmp);
		tg[idx[0]] = 0;

		for (int i = 1; i < n; i++) {
			if (cmp(idx[i - 1], idx[i])) {
				tg[idx[i]] = tg[idx[i - 1]] + 1;
			}
			else tg[idx[i]] = tg[idx[i - 1]];
		}

		for (int i = 0; i < n; i++) g[i] = tg[i];
		t <<= 1;
	}

	int len = 0;

	for (int i = 0; i < n; i++) ranks[idx[i]] = i;
 	
	for (int i = 0; i < n; i++) {
		int k = ranks[i];

		if (k) {
			int z = idx[k - 1];

			while (arr[i + len] == arr[z + len])
				len++;

			lcp[k] = len;
			if (len) len--;
		}
	}

	for (int i = 0; i < n; i++) {
		cout << idx[i] + 1 << " ";
	}
	cout<<"\n";

	for (int i = 0; i < n; i++) {
		if (!i) cout << "x" << " ";
		else cout << lcp[i] << " ";
	}
}