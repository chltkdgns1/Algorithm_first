#include <iostream>
#include <algorithm>
using namespace std;
typedef long long int ll;
#define MAX 10000000
int map[1001][1001];
int n;
ll cal(int mid) {
	ll t = 0;
	for (int i = 0; i < n; i++) {
		for (int k = 0; k < n; k++) {
			if (mid <= map[i][k])
				t += mid;
			else
				t += map[i][k];
		}
	}
	return t;
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n;
	ll s = 0;
	for (int i = 0; i < n; i++) {
		for (int k = 0; k < n; k++) {
			cin >> map[i][k];
			s += map[i][k];
		}
	}
	int left = 0, right = MAX;
	int res = MAX;
	while (left <= right) {
		int mid = (left + right) / 2;
		ll t = cal(mid);
		if (s <= t * 2) {
			res = min(res, mid);
			right = mid - 1;
		}
		else left = mid + 1;
	}
	cout << res << "\n";
}