#include <iostream>
#include <vector>
#include <string.h>
#define inf 1000000007
using namespace std;

typedef long long ll;
vector <int> v, e;
int map[1001][1001];


int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int a, b,c; cin >> a >> b;

	memset(map, -1, sizeof(map));

	for (int i = 0; i < a; i++) {
		cin >> c;
		v.push_back(c);
		if (!c) map[i][0] = 0;
		else {
			for (int k = 0; k < c; k++) map[i][k] = 1;
			map[i][c] = 0;
		}
	}
	for (int i = 0; i < b; i++) {
		cin >> c;
		e.push_back(c);
		if (!c) map[0][i] = 0;
		else {
			for (int k = 0; k < c; k++) {
				if (!map[k][i]) {
					cout << 0 << "\n";
					return 0;
				}
				map[k][i] = 1;
			}
			if (map[c][i] == 1) {
				cout << 0 << "\n";
				return 0;
			}
			map[c][i] = 0;
		}
	}

	ll res = 1;
	for (int i = 0; i < a; i++) {
		for (int k = 0; k < b; k++) {
			if (map[i][k] == -1) res = (res * 2) % inf;
		}
	}
	cout << res << "\n";
}