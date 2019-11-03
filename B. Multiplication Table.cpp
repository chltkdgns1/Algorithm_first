#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
typedef long long ll;

ll map[1001][1001];
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		for (int k = 0; k < n; k++) cin >> map[i][k];
	}
	int a = 1, b = 2, c = 0, d = 1;
	vector <ll> v;
	for (int i = 1; i < n - 1; i++) {
		v.push_back(sqrt(map[c][a] * map[d][b] / map[c][b]));
		a++, b++, c++, d++;
	}
	cout << map[0][1] / v[0] << " ";
	for (auto a : v) cout << a << " ";
	cout << map[n - 2][n - 1] / v.back() << "\n";
}