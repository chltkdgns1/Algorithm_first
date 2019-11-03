#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool map[40001][40001];
vector <pair<int, int>> v;
//
bool cmp(const pair<int, int> &a, const pair<int, int> &b) {
	return a.second < b.second;
}
//
void deleteWater(int x, int y) {
	for (int i = y; i >= 0; i--) {
		if (!map[i][x]) break;
		map[i][x] = 0;
	}
}

int find(int x, int y) {
	for (int i = y; i >= 0; i--) {
		if (map[i][x] == 1) return i;
	}
	return -1;
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, k;
	cin >> n;
	int a, b, c, d;

	cin >> a >> b;
	int deep = 0;
	for (int i = 0; i < (n - 2) / 2; i++) {
		int a, b,c,d;
		cin >> a >> b >> c >> d;
		if (deep < b) deep = b;
		for (int i = 0; i < b; i++) {
			for (k = a; k < c; k++) {
				map[i][k] = 1;
			}
		}
	}
	cin >> c >> d;	
	cin >> k;
	for (int i = 0; i < k; i++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		v.push_back({ a,b - 1});
	}
	//
	sort(v.begin(), v.end(), cmp);
	//
	for (int i = 0; i < v.size(); i++) {
		int a = v[i].first;
		int b = v[i].second;
		for (int k = a; k >= 0; k--) {
			if (map[b][k] == 1) deleteWater(k, b);
			else {
				int s = find(k, b);
				if (s == -1) break;
				b = s;
				deleteWater(k, b);
			}
		}
		b = v[i].second;
		for (int k = a + 1; k < c; k++) {
			if (map[b][k] == 1) deleteWater(k, b);
			else {
				int s = find(k, b);
				if (s == -1) break;
				b = s;
				deleteWater(k, b);
			}
		}
	}

	int cnt = 0;
	for (int i = 0; i < deep; i++) {
		for (int k = 0; k < c; k++) {
			if (map[i][k]) cnt++;
		}
	}
	cout << cnt << "\n";
	// y °ªÀ» ÇÏ³ª »©ÁÜ
}