#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define INF 987654321
using namespace std;

vector <pair<int, int>> v, r;
int dp[1001][1001], w;

int solve(int a,int b) {
	if (a == w || b == w) return 0;
	int &ref = dp[a][b];
	if (ref) return ref;

	int d = max(a, b) + 1;
	int q = abs(v[d].first - v[a].first) + abs(v[d].second - v[a].second);
	int e = abs(r[d].first - r[b].first) + abs(r[d].second - r[b].second);
	return ref = min(solve(d, b) + q, solve(a, d) + e);
}

void tracing(int a, int b) {
	if (a == w || b == w) return;
	int d = max(a, b) + 1;
	int q = abs(v[d].first - v[a].first) + abs(v[d].second - v[a].second);
	int e = abs(r[d].first - r[b].first) + abs(r[d].second - r[b].second);

	if (dp[a][b] == dp[d][b] + q) {
		cout << 1 << "\n";
		tracing(d, b);
	}
	else if(dp[a][b] == dp[a][d] + e){
		cout << 2 << "\n";
		tracing(a, d);
	}

}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, a, b; cin >> n >> w;
	v.push_back({ 1,1 });
	r.push_back({ n,n });
	for (int i = 0; i < w; i++) {
		cin >> b >> a;
		v.push_back({ a,b });
		r.push_back({ a,b });
	}
	int res = solve(0, 0);
	cout << res << "\n";
	tracing(0, 0);
}