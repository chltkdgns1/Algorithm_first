#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector <pair<int, int>> v;
bool cmp(const pair<int, int> &a, const pair<int, int>&b) {
	if (a.first == b.first) return a.second > b.second;
	else return a.first < b.first;
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b; cin >> a >> b;
		v.push_back({ a,b });
	}

	sort(v.begin(), v.end(), cmp);

	int t = 0, day = 1;
	for (int i = 0; i < v.size(); i++) {
		bool br = 0;
		int key = day;
		if (key <= v[i].first) {
			for (int k = i + 1; k < v.size(); k++) {
				if (v[k].second > v[i].second) {
					key++;
					if (v[k].first < key) {
						br = 1;
						break;
					}
				}
			}
			if (!br) {
				t += v[i].second;
				day++;
			}
		}
	}
	cout << t << "\n";
}