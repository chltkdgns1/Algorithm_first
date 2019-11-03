#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	while (n--) {
		vector <int> v;
		for (int i = 0; i < 10; i++) {
			int a; cin >> a;
			v.push_back(a);
		}
		sort(v.begin(), v.end());
		cout << v[v.size() - 3] << "\n";
	}
}