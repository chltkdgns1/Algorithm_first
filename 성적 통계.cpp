#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t,cnt = 1; cin >> t; 
	while (t--) {
		vector <int> v;
		int n; cin >> n;
		for (int i = 0; i < n; i++) {
			int c; cin >> c; 
			v.push_back(c);
		}
		sort(v.begin(), v.end());
		int max = 0;
		for (int i = 1; i < v.size(); i++) {
			if (max < v[i] - v[i - 1]) max = v[i] - v[i - 1];
		}
		cout << "Class " << cnt++ << "\n";
		cout << "Max " << v.back() << ", Min " << v[0] << ", Largest gap " << max << "\n";
	}
}