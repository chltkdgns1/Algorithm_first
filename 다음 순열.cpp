#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector <int> v;
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, a;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a;
		v.push_back(a);
	}
	if (next_permutation(v.begin(), v.end()) == 0) cout << -1 << "\n";
	else for (int i = 0; i < n; i++) cout << v[i] << " ";
}