#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int a[100001], b[100001];
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		int c; cin >> c;
		a[c] = i;
	}
	for (int i = 0; i < n; i++) {
		int c; cin >> c;
		b[i] = a[c];
	}
	int cnt = 0;
	vector <int> v;
	v.push_back(-1);
	for (int i = 0; i < n; i++) {
		if (v.back() < b[i]) {
			v.push_back(b[i]);
			cnt++;
		}
		else v[lower_bound(v.begin(), v.end(), b[i]) - v.begin()] = b[i];
		
	}
	cout << cnt << "\n";
}