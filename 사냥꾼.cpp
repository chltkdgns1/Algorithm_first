#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
vector <int> v; // 발사대의 좌표
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, m, r; // 발사대수 동물수 사거리
	cin >> n >> m >> r;
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		v.push_back(a);
	}
	sort(v.begin(), v.end());
	int cnt = 0, size = v.size();
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		if (v[0] >= a) { // x 좌표
			if (abs(v[0] - a) + b <= r) cnt++;
 		}
		else if (v[size - 1] <= a) {
			if (abs(v[size - 1] - a) + b <= r) cnt++;
		}
		else {
			int index = lower_bound(v.begin(), v.end(), a) - v.begin();
			if (v[index] == a) {
				if (b <= r) cnt++;
			}
			else {
				if (abs(v[index - 1] - a) < abs(v[index] - a)) {
					if (abs(v[index - 1] - a) + b <= r) cnt++;
				}
				else {
					if (abs(v[index] - a) + b <= r) cnt++;
				}
			}
		}
	}
	cout << cnt << "\n";
}