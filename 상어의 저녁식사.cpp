#include <iostream>
#include <vector>
using namespace std;

class shark {
public:
	int s, p, t;
};
shark s[51];
bool check[51];
int d[51];
int die[51];
vector <int> v[51];
int dfs(int s) {
	if (check[s] ) return false;
	check[s] = 1;
	for (int i = 0; i < v[s].size(); i++) {
		int e = v[s][i];
		if (!d[e] || dfs(d[e])) {
			d[e] = s;
			return true;
		}
	}
	return false;
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		s[i].s = a, s[i].t = b, s[i].p = c;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i != j) {
				if (s[i].s == s[j].s && s[i].p == s[j].p && s[i].t == s[j].t) {
					if (i < j) v[i].push_back(j);
					continue;
				}
				if (s[i].s >= s[j].s && s[i].p >= s[j].p && s[i].t >= s[j].t) {
					v[i].push_back(j);
				}
			}
		}
	}
	int c = 0;
	for (int i = 1; i <= n; i++) {
		for (int k = 0; k < 2; k++) {
			fill(check + 1, check + 1 + n, 0);
			if (dfs(i)) c++;
		}
	}
	cout << n - c << "\n";
}