#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector <int> v;
int dp[100001][2];

int solve(int s, bool c) {
	if (s >= v.size()) return 0;

	int &ref = dp[s][c];
	if (ref) return ref;

	ref = 0;

	if (s == v.size() - 1 && c) return 0;
	if (!s) ref = max(ref, solve(s + 2, 1) + v[s]);
	else ref = max(ref, solve(s + 2, c) + v[s]);
	ref = max(ref, solve(s + 1, c));
	return ref;
}

int solution(vector<int> r){
	v = r;
	return solve(0, 0) ;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	vector <int> v;
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		v.push_back(a);
	}

	solution(v);
}