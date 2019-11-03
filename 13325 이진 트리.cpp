#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef long long ll;
int v[1 << 21];
ll dp[1 << 21];
static char buf[65536];
static inline char getch()
{
	static int p = 65536;
	if (p == 65536)
	{
		fread(buf, 1, 65536, stdin);
		p = 0;
	}
	return buf[p++];
}
static inline void get(int &r)
{
	register int t;
	r = getch() & 15;
	while ((t = getch()) > 40) r = r * 10 + (t & 15);
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, d; get(n);
	d = (1 << (n + 1)) - 2;
	for (int i = 2; i <= d + 1; i++) get(v[i]);
	int z = 0, u = d + 1, q = 0;
	while (1) {
		if (!(u - (1 << z))) break;
		u -= (1 << z);
		z++;
	}
	int s = d + 2 - (1 << (z));
	for (int i = s; i <= d + 1; i++) dp[i] = -1;
	for (int i = d + 1; i >= 2; i--) {
		if (dp[i]) {
			if (dp[i] == -1) dp[i] = 0;
			int q = i / 2;
			if (!dp[q]) dp[q] = dp[i] + v[i];
			else {
				ll p = dp[i] + v[i];
				if (i % 2) {
					if (dp[q] < p) v[q * 2] += p - dp[q];
					if (dp[q] > p) v[q * 2 + 1] += dp[q] - p;
				}
				else {
					if (dp[q] < p) v[q * 2 + 1] += p - dp[q];
					if (dp[q] > p) v[q * 2] += dp[q] - p;
				}
				dp[q] = max(dp[q], p);
			}
		}
	}
	ll res = 0;
	for (int i = 2; i <= d + 1; i++) res += v[i];
	cout << res << "\n";
}