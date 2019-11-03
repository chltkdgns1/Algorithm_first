#include <iostream>
#include <vector>
using namespace std;

char map[13][7];
bool check[12][6];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
vector <pair<int, int>> v;
int dfs(int xpos,int ypos,char c,int cnt) {
	check[ypos][xpos] = true;
	v.push_back({ xpos,ypos });
	for (int i = 0; i < 4; i++) {
		int x = xpos + dx[i];
		int y = ypos + dy[i];
		if (x >= 0 && y >= 0 && x < 6 && y < 12) {
			if (map[y][x] == c && check[y][x] == false) {
				return dfs(x, y, c, cnt + 1);
			}
		}
	}
}

bool checkSky(int xpos,int ypos) {
	if (map[xpos][ypos + 1] != '.') return true;
	return false;
}

void makeSky(int xpos, int ypos) {
	for (int i = ypos + 1; i < 12; i++) {
		if (map[i][xpos] != '.') {
			map[i - 1][xpos] = map[ypos][xpos];
			map[ypos][xpos] = '.';
			break;
		}
	}
}
int main() {
	int key = 0;
	for (int i = 0; i < 12; i++) cin >> map[i];
	while (1) {
		for (int i = 0; i < 12; i++) {
			for (int j = 0; j < 6; j++) {
				if (map[i][j] != '.') {
					if (checkSky(j,i) == false) { // 공중에 있는지 체크
						makeSky(j, i);
					}
					else {
						if (dfs(j, i, map[i][j], 1) >= 4) {
							key++;
							for (int i = 0; i < v.size(); i++) {
								map[v[i].second][v[i].first] = '.';
								check[v[i].second][v[i].first] = false;
							}
							v.clear();
							for (int i = 0; i < 12; i++) {
								for (int j = 0; j < 6; j++) {
									cout << map[i][j];
								}
								cout << endl;
							}
							system("pause");
						}
					}
				}
			}
		}
	}
	system("pause");
}