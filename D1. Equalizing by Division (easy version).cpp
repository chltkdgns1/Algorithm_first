#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;
typedef long long ll;

char cmap[51][51];
int Map[51][51];
bool visit[51][51];
int dx[8] = { 0,0,1,-1,1,1,-1,-1};
int dy[8] = { 1,-1,0,0,1,-1,1,-1};
int n, cnt;
vector <int> v;

bool check(int x, int y) {
	if (x >= 0 && x < n && y >= 0 && y < n) return true;
	return false;
}

int solve(int x, int y,int a,int b) {
	if (visit[y][x] || !check(x, y) || Map[y][x] < a || Map[y][x] > b) return 0;
	int cnt = 0;
	visit[y][x] = 1;
	if (cmap[y][x] == 'K') cnt++;

	for (int i = 0; i < 8; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		cnt += solve(nx, ny, a, b);
	}
	return cnt;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n;
	int x, y;
	for (int i = 0; i < n; i++) cin >> cmap[i];
	for (int i = 0; i < n; i++) {
		for (int k = 0; k < n; k++) {
			if (cmap[i][k] == 'P') x = k, y = i;
			if (cmap[i][k] == 'K') cnt++;
			cin >> Map[i][k];
			v.push_back(Map[i][k]);
		}
	}
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());

	int e = 0, res = 987654321;
	for (int i = 0; i < v.size(); i++) {
		while (1) {
			memset(visit, 0, sizeof(visit));
			if (solve(x, y, v[e], v[i]) != cnt) break;
			res = min(res, v[i] - v[e]);
			e++;
		}
	}
	cout << res << "\n";
}