#include <iostream>
#include <algorithm>
using namespace std;

pair<int, int> v[1001];
bool cmp(const pair<int, int>&a, const pair<int, int>&b) {
	if (a.first == b.first) return a.second < b.second;
	else return a.first < b.first;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	int t = 0;
	for (int i = 0; i < n; i++) cin >> v[i].first >> v[i].second;
	sort(v, v + n, cmp);
	for (int i = 0; i < n; i++) {
		bool br = 0;
		int x = v[i].first;
		for (int k = i + 1; k < n; k++) {
			if (v[i].second < v[k].second) {
				x++;
				if (x > v[k].second) {
					br = 1;
					break;
				}
			}
		}
		if (!br) t += v[i].second;
	}
	cout << t << "\n";
	system("pause");
}