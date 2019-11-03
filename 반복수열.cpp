#include <iostream>
#include <math.h>
using namespace std;
int d[300000];
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int a, p; cin >> a >> p;
	d[a]++;
	int res = a;
	while (1) {
		int t = res;
		res = 0;
		while (t) {
			res += pow(t % 10,p);
			t /= 10;
		}
		d[res]++;
		if (d[res] == 3) break;
	}
	int cnt = 0;
	for (int i = 1; i <= 300000; i++) {
		if (d[i] == 1) cnt++;
	}
	cout << cnt << "\n";
}