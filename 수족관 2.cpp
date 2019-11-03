#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector <pair<int, int>> v;
vector <pair<int, int>> e;

bool cmp(const pair<int, int>&a, const pair<int, int>&b) {
	return a.second < b.second;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, k;
	cin >> n;
	int a, b, c, d;

	cin >> a >> b;
	int deep = 0;
	for (int i = 0; i < (n - 2) / 2; i++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		for (k = a; k < c; k++) v.push_back({ b,b });
	}
	cin >> c >> d;
	cin >> k;

	for (int i = 0; i < k; i++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		e.push_back({ a,b });
	}
	
	sort(e.begin(), e.end(), cmp);

	for (int i = 0; i < e.size(); i++) {
		int x = e[i].first, y = e[i].second;
		while (x >= 0) {
			if (v[x].first - y > 0) v[x].second = min(v[x].second, v[x].first - y);
			else {
				y = v[x].first;
				v[x].second = 0;
			}
			x--;
		}
		y = e[i].second;
		x = e[i].first;
		while (x < c) {
			if (v[x].first - y > 0) v[x].second = min(v[x].second, v[x].first - y);
			else {
				y = v[x].first;
				v[x].second = 0;
			}
			x++;
		}
	}
	int t = 0;
	for(int i=0;i<v.size();i++){
		t += v[i].second;
	}
	cout << t << "\n";
}