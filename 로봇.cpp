#include <iostream>
#include <string>
using namespace std;

int n, m;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	int x = 0, y = 0, dir = 0;
	bool flag = 0;
	for (int i = 0; i < m; i++) {
		string s; int a; cin >> s >> a;
		if (s == "TURN") {
			if (!a) dir++;
			else dir--;
			if (dir == 4) dir = 0;
			if (dir == -1) dir = 3;
		}
		else {
			x = x + dx[dir] * a;
			y = y + dy[dir] * a;
			if (x < 0 || x > n || y < 0 || y > n) flag = 1;
		}
		
	}
	if (!flag) cout << x << " " << y << "\n";
	else cout << -1 << "\n";
}