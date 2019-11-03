#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
int map[11][11];
vector <pair<int, int>> v1,v2,h1,h2;
int n;
bool check1(int x,int y) {
	for (int i = 0; i < h1.size(); i++) {
		int xpos = h1[i].first;
		int ypos = h1[i].second;
		if (xpos == x && ypos == y) return false;
		if (abs(xpos - x) == abs(ypos - y)) return false;
	}
	return true;
}
bool check2(int x, int y) {
	for (int i = 0; i < h2.size(); i++) {
		int xpos = h2[i].first;
		int ypos = h2[i].second;
		if (xpos == x && ypos == y) return false;
		if (abs(xpos - x) == abs(ypos - y)) return false;
	}
	return true;
}
int max1,max2;
void dfs1(int index,int cnt) {
	if (index == v1.size()) {
		if (max1 < cnt) max1 = cnt;
		return;
	}
	int x = v1[index].first;
	int y = v1[index].second;
	if (check1(x, y)) {
		h1.push_back({ x,y });
		dfs1(index + 1, cnt + 1);
		h1.pop_back();
	}
	dfs1(index + 1, cnt);
}
void dfs2(int index, int cnt) {
	if (index == v2.size()) {
		if (max2 < cnt) max2 = cnt;
		return;
	}
	int x = v2[index].first;
	int y = v2[index].second;
	if (check2(x, y)) {
		h2.push_back({ x,y });
		dfs2(index + 1, cnt + 1);
		h2.pop_back();
	}
	dfs2(index + 1, cnt);
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1) {
				if((i + j) % 2 == 0)v1.push_back({ j,i });
				else v2.push_back({ j,i });
			}
		}
	}
	dfs1(0,0);
	dfs2(0, 0);
	cout << max1 + max2<< "\n";
}