#include <iostream>
#include <set>
#include <string>
using namespace std;
int map[5][5];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
set <string> s;
string d;
void dfs(int x, int y ,int index) {
	if (index == 6) {
		s.insert(d);
		return;
	}
	for (int i = 0; i < 4; i++) {
		int xpos = x + dx[i];
		int ypos = y + dy[i];
		if (xpos >= 0 && xpos < 5 && ypos >= 0 && ypos < 5) {
			d += map[ypos][xpos] + 48;
			dfs(xpos, ypos, index + 1);
			d.pop_back();
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) cin >> map[i][j];
	}
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			d += map[i][j] + 48;
			dfs(j, i, 1);
			d.pop_back();
		}
	}
	cout << s.size() << "\n";
}