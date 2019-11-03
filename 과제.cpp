#include <iostream>
#include <algorithm>
using namespace std;

pair<int, int> d[1001];
int dir[1001];
bool check[1001];
int n, max_day, max_score;

bool cmp(const pair<int, int>&a, const pair<int, int>&b) {
	if (a.first == b.first) return a.second < b.second;
	else return a.first < b.first;
}
void dfs(int day) {
	bool br = 0;
	for (int i = n; i >= 1; i--) {
		if (d[i].first > day ) {
			if (!check[i]) {
				dir[day] = i;
				check[i] = 1;
				dfs(day + 1);
				check[i] = 0;
				dir[day] = 0;
				br = 1;
			}
		}
		else break;
	}
	if (!br) {
		int t = 0;
		for (int i = 0; i < day; i++) t += d[dir[i]].second;
		if (max_score < t) max_score = t;
		return;
	}
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> d[i].first >> d[i].second;
	sort(d + 1, d + 1 + n, cmp);
	dfs(0);
	cout << max_score << "\n";
}
