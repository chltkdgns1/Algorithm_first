#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector <pair<int, double>> e;
int d[502], dp[502];

bool cmp(pair<int, double> &a, pair<int, double> &b) {
	if (a.second == b.second) return a.first < b.first;
	return a.second > b.second;
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n,st; cin >> n >> st;
	int max = 0;
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		max = max < a ? a : max;
		d[a]++;
	}

	dp[1] = d[1];

	for (int i = 2; i <= max; i++) {
		dp[i] = dp[i - 1] + d[i];
	}

	for (int i = 1; i <= st; i++) {
		if (i == 1) {
			if (!d[i]) e.push_back({ i,0 });
			else e.push_back({ i,double(d[i]) / dp[max] });
		}
		else {
			if (!d[i]) e.push_back({ i,0 });
			else e.push_back({ i,double(d[i]) / (dp[max] - dp[i - 1]) });
		}
	}

	sort(e.begin(), e.end(), cmp);

	for (auto a : e) {
		cout << a.first << " ";
	}
	system("pause");
}