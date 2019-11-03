#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

pair<int, int> d[10];
bool visit[3][3];
vector <int> v;
int n;
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n;
	int cnt = 1;
	for (int i = 0; i < 3; i++) {
		for (int k = 0; k < 3; k++) {
			d[cnt] = { k,i };
			cnt++;
		}
	}
	pair<int, int> e;
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		if (!i) {
			visit[d[a].second][d[a].first] = 1;
			e = d[a];
		}
		else {
			int x = abs(e.first - d[a].first), y = abs(e.second - d[a].second);
			if (visit[d[a].second][d[a].first]) {
				cout << "NO";
				return 0;
			}
			else if (x == y && x == 2) {
				if (!visit[d[5].second][d[5].first]) {
					cout << "NO";
					return 0;
				}
			}
			else if (x == 0 && y == 2) {
				if (!visit[1][e.first]) {
					cout << "NO";
					return 0;
				}
			}
			else if (x == 2 && y == 0) {
				if (!visit[e.second][1]) {
					cout << "NO";
					return 0;
				}
			}
			visit[d[a].second][d[a].first] = 1;
			e = d[a];
		}
	}
	cout << "YES" << "\n";
}