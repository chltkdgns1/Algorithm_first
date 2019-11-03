#include <iostream>
#include <algorithm>
using namespace std;
double sc[101];
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, m, z; cin >> n >> m >> z;
	for (int k = 0; k < m; k++) {
		for (int i = 0; i < n; i++) {
			int a; double b;
			cin >> a >> b;
			sc[a] = sc[a] < b ? b : sc[a];
		}
	}
	double s = 0;
	sort(sc + 1, sc + n + 1);
	for (int i = n; i> n - z; i--) s += sc[i];
	printf("%.1lf", s);
}