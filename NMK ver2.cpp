#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector <int> v;
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, m, k;
	cin >> n >> m >> k;
	if (m + k - 1 <= n && n <= m * k) {
		for (int i = 0; i < n; i++) 
			v.push_back(i + 1);

		int idx = 0;

		reverse(v.begin(), v.begin() + k);
		idx += k;

		for (int i = 1; i < m; i++) {
			int temp = idx;

			if ((n - idx) / (m - i) < k) 
				idx += (n - idx) / (m - i);

			else 
				idx += k;
			
			reverse(v.begin() + temp, v.begin() + idx);
		}

		for (int i = 0; i < n; i++) 
			cout << v[i] << " ";
	}
	else cout << -1;
}