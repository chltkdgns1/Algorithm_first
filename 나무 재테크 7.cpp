#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maps[10][10];
int n, m, k;
int dx[8] = { 0,0,1,-1,1,1,-1,-1 };
int dy[8] = { 1,-1,0,0,1,-1,1,-1 };
class tree {
public:
	vector <int> v;
	int g;
};

tree map[11][11];

bool check(int x, int y) {
	if (x >= 0 && x < n && y >= 0 && y < n) return true;
	return false;
}

void sortingTree() { // 같은 공간에 나무들 나이순 정렬
	for (int i = 0; i < n; i++) {
		for (int k = 0; k < n; k++) {
			if(map[i][k].v.size()) sort(map[i][k].v.begin(), map[i][k].v.end());
		}
	}
}

void springSummer() { // 봄 여름
	for (int i = 0; i < n; i++) {
		for (int k = 0; k < n; k++) {
			int len = map[i][k].v.size();
			if (len) {
				int t = map[i][k].g, store_g = 0;
				for (int z = 0; z < len; z++) {
					int y = map[i][k].v[z];
					if (t - y >= 0) {
						t -= y;
						map[i][k].v[z] += 1;
					}
					else {
						len--;
						store_g += map[i][k].v[z] / 2;
						map[i][k].v.erase(map[i][k].v.begin() + z);
						z--;
					}
				}
				map[i][k].g = t + store_g;
			}
		}
	}
}

void fall() { // 가을
	for (int i = 0; i < n; i++) {
		for (int k = 0; k < n; k++) {
			int len = map[i][k].v.size();
			if (len) {
				for (int z = 0; z < len; z++) {
					if (map[i][k].v[z] % 5 == 0) {
						for (int q = 0; q < 8; q++) {
							int nx = k + dx[q];
							int ny = i + dy[q];
							if (check(nx, ny)) {
								map[ny][nx].v.push_back(1);
							}
						}
					}
				}
			}
		}
	}
	sortingTree(); // 나무가 추가되었으니 정렬
}

void winter() { // 겨울
	for (int i = 0; i < n; i++) {
		for (int k = 0; k < n; k++) {
			map[i][k].g += maps[i][k]; // 양분 추가
		}
	}
}


int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		for (int k = 0; k < n; k++) {
			cin >> maps[i][k]; 
			map[i][k].g = 5; 
		}
	}
	for (int i = 0; i < m; i++) {
		int x, y, age;
		cin >> y >> x >> age;
		map[y - 1][x - 1].v.push_back(age);
	}

	sortingTree();
	for (int i = 0; i < k ; i++) {
		springSummer();
		fall();
		winter();
	}
	long long t = 0;
	for (int i = 0; i < n; i++) {
		for (int k = 0; k < n; k++) {
			t += map[i][k].v.size();
		}
	}
	cout << t << "\n";
}