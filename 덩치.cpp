#include <iostream>
int mod = 1000000009;
using namespace std;
long long d[1001][4];
int main() {
	int n; cin >> n;
	d[1][1] = d[1][2] = d[1][3] = 1;
	for (int i = 2; i <= n; i++) {
		d[i][1] = d[i][2] = d[i][3] = d[i - 1][1] + d[i - 1][2] + d[i - 1][3];

		for (int j = 1; j < i - 1; j++) {
			d[i][1] += d[j][3];
			d[i][3] += d[j][1];
		}

		d[i][1] %= mod;
		d[i][2] %= mod;
		d[i][3] = (d[i][3] + 1) % mod;
	}
	printf("%lld\n", d[n][3]);
	return 0;
}

