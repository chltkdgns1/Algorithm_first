#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

vector <int> tr[12];
vector <int> v;

void dfs(int s,int e,int deep) {
	int m = (s + e) / 2;
	tr[deep].push_back(v[m]);
	if (s == m) return;
	dfs(s, m, deep + 1);
	dfs(m + 1, e, deep + 1);
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t,c = 1; cin >> t;
	while (t--) {
		int n; cin >> n;
		for (int i = 0; i < pow(2, n) - 1; i++) {
			int a; cin >> a; v.push_back(a);
		}
		cout << "#" << c++ << " ";
		dfs(0, pow(2, n) - 2, 1);
		for (int i = 1; i <= 11; i++) {
			if (!tr[i].empty()) {
				for (auto a : tr[i]) {
					cout << a << " ";
				}
				cout << "\n";
			}
			else break;
		}
		v.clear();
		for (int i = 1; i <= 11; i++) tr[i].clear();
	}
}