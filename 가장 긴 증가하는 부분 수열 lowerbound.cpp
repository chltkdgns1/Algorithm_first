#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector <int> v;
int main() {
	int n;
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n;
	v.push_back(-987654321);
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		if (v.back() < a) {
			v.push_back(a);
			cnt++;
		}
		else {
			v[lower_bound(v.begin(), v.end(), a) - v.begin()] = a;
		}
	}
	cout << cnt << "\n";
}