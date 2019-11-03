#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
#define inf 987654321
using namespace std;

vector <vector<int>> v;
vector <int> e;
int dp[201][101];

int solve(int s, int u) {
	if (u == e.size() - 1) {
		if (s == e[u]) return 0;
		return inf;
	}
	
	int &ref = dp[s][u];
	if (ref) return ref;

	int t = (s != e[u]);

	ref = inf;
	for (auto a : v[s]) {
		ref = min(ref, solve(a, u + 1) + t);
	}

	return ref;
}

int solution(int n, int m, vector<vector<int>> a, int k, vector<int> b) {
	v.resize(n + 1);

	for (auto c : a) {
		v[c[0]].push_back(c[1]);
		v[c[1]].push_back(c[0]);
	}

	e = b;

	memset(dp, 0, sizeof(dp));
	int t = solve(b[0], 0);
	return  t == inf ? -1 : t;
}



int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);


}