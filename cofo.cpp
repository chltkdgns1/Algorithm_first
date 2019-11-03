#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

int ans[200001], v[200001], visit[200001];

int solve(int s,int d) {
	visit[s] = 1;
	if (visit[v[s]]) return ans[s] = d;
	else return ans[s] = solve(v[s], d + 1);
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int q; cin >> q;
	while (q--) {
		int n; cin >> n;

		memset(visit, 0, sizeof(visit));
		memset(ans, 0, sizeof(ans));
		for (int i = 1; i <= n; i++) cin >> v[i];

		for (int i = 1; i <= n; i++) {
			if (!visit[i]) solve(i, 1);
		}
		for (int i = 1; i <= n; i++) {
			cout << ans[i] << " ";
		}
		cout << "\n";
	}
}