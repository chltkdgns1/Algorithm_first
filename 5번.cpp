#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
using namespace std;

int map[1001][6][2];
class Data {
public:
	int a, b, c;
};

bool cmp(Data &a, Data &b) {
	if (a.a == b.a) {
		if (a.b == b.b) {
			return a.c < b.c;
		}
		return a.b < b.b;
	}
	return a.a < b.a;
}


vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
	memset(map, -1, sizeof(map));

	vector<vector<int>> answer;
	answer.resize(1001);
	for (auto a : build_frame){
		int x = a[0], y = a[1];
		int c = a[2], d = a[3];
		if (d) {
			if (!c) { // 0 Àº ±âµÕ 1 Àº ½ÄÅ¹º¸
				if (!y) map[y][x][0] = 1;
				else if (map[y - 1][x][0]) map[y][x][0] = 1;
				else if (x - 1 >= 0 && map[y][x - 1][1]) {
					if (map[y][x][1] != 1) {
						map[y][x][0] = 1;
					}
				}
				else if (map[y][x][1]) {
					if (x - 1 >= 0 && map[y][x - 1][1] != 1) map[y][x][0] = 1;
				}
			}
			else {
				if (!y) continue;
				else if (map[y - 1][x][0]) {
					map[y][x][1] = 1;
				}
				else if (x + 1 <= 5 && map[y - 1][x + 1][0]) {
					map[y][x][1] = 1;
				}
				else if (x - 1 >= 0 && x + 1 <= 5 && map[y][x + 1][1] && map[y][x - 1][1]) {
					map[y][x][1] = 1;
				}
			}
		}
		else {
			if (!c) { // 0 Àº ±âµÕ 1 Àº ½ÄÅ¹º¸
				if (map[y + 1][x][0]) continue;
				else { // À§¿¡ ÀÖ´Â°Ô ±âµÕÀÌ ¾Æ´Ò °æ¿ì 
					if (x - 1 >= 0 && x + 1 <= 5 &&
						map[y + 1][x - 1][1] && map[y + 1][x + 1][1]) {
						continue;
					}
				}
			}
			else {
				if (x + 1 <= 5 && map[y][x + 1][1]) {
					if (!map[y - 1][x + 1][0]) continue;
				}
				if (x - 1 >= 0 && map[y][x - 1][1]) {
					if (!map[y - 1][x - 1][0]) continue;
				}
			}
			map[y][x][c] = -1;
		}
	}
	int cnt = 0;
	vector <Data> aa;
	for (int i = 0; i <= 5; i++) {
		for (int k = 0; k <= 1000; k++) {
			for (int z = 0; z < 2; z++) {
				if (map[k][i][z] != -1) {
					aa.push_back({ i,k,z });
				}
			}
		}
	}

	sort(aa.begin(), aa.end(), cmp);
	int i = 0;
	for (auto a : aa) {
		answer[i].push_back(a.a);
		answer[i].push_back(a.b);
		answer[i].push_back(a.c);
		i++;
	}
	return answer;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int a, b, c, d, n; cin >> n;
	vector <vector<int>> v;
	v.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> a >> b >> c >> d;
		v[i].push_back(a);
		v[i].push_back(b);
		v[i].push_back(c);
		v[i].push_back(d);
	}
	solution(n, v);
	system("pause");
}