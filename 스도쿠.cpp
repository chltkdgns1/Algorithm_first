#include <iostream>
#include <vector>;
using namespace std;
vector <pair<int, int>> v;
int map[9][9];
int dir[3] = { 0,3,6 };
bool check(int x,int y , int num) {
	for (int i = 0; i < 9; i++) {
		if (map[i][x] == num) return false;
		if (map[y][i] == num) return false;
	}
	for (int i = dir[y / 3]; i < dir[y / 3] + 3; i++) {
		for (int j = dir[x / 3]; j < dir[x / 3] + 3; j++) {
			if (map[i][j] == num) return false;
		}
	}
	return true;
}
void dfs(int index) {
	if (index == v.size()) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				cout << map[i][j] << " ";
			}
			cout << "\n";
		}
		exit(0);
	}
	int x = v[index].first;
	int y = v[index].second;
	for (int i = 1; i <= 9; i++) {
		if (check(x,y,i) == true) {
			map[y][x] = i;
			dfs(index + 1);
			map[y][x] = 0;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> map[i][j];
			if(map[i][j] == 0) v.push_back({ j,i });
		}
	}
	dfs(0);
}