#include <iostream>
using namespace std;
#define inf 1000000007
typedef long long ll;

ll dp[5000][(1 << 3)];

ll solve(int s, int t) {
	if (s < 0) return 0;
	if (!s && !t) return 1;

	ll &ref = dp[s][t];
	if (ref) return ref;

	ref = 0;
	if (!t) {
		ref = (ref + solve(s - 2, 0)) % inf;
		ref = (ref + solve(s - 1, 4)) % inf;
		ref = (ref + solve(s - 1, 1)) % inf;
	}
	else if (t == 1) {
		ref = (ref + solve(s - 1, 0)) % inf;
		ref = (ref + solve(s - 1, 6)) % inf;
	}
	else if (t == 4) {
		ref = (ref + solve(s - 1, 0)) % inf;
		ref = (ref + solve(s - 1, 3)) % inf;
	}
	else if (t == 3) ref = (ref + solve(s - 1, 4)) % inf;
	else if (t == 6) ref = (ref + solve(s - 1, 1)) % inf;
	return ref;
}

int solution(int n) {
	int answer = 0;
	answer =  solve(n, 0);
	return answer;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n; cin >> n;

	solution(n);
}