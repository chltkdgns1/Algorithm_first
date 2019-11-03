#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

int map[1001][1001];
bool visit[1001][1001];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int n, m;
vector <pair<int, int>> v, e;

bool check(int x, int y) {
	if (x >= 0 && x < m && y >= 0 && y < n) return true;
	return false;
}

int max1;
int dfs(int x, int y, int cnt) {
	int t = 1;
	visit[y][x] = 1;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (check(x, y)) {
			if (!visit[ny][nx] && map[ny][nx]) {
				t += dfs(nx, ny, cnt + 1);
			}
		}
	}
	return t;
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int k = 0; k < m; k++) {
			cin >> map[i][k];
			if (map[i][k]) v.push_back({ k,i });
		}
	}

	for (int i = 0; i < v.size(); i++) {
		for (int k = 0; k < 4; k++) {
			int nx = v[i].first + dx[k];
			int ny = v[i].second + dy[k];
			if (check(nx, ny)) {
				if (!map[ny][nx] && !visit[ny][nx]) {
					visit[ny][nx] = 1;
					e.push_back({ nx,ny });
				}
			}
		}
	}

	memset(visit, 0, sizeof(visit));

	for (int i = 0; i < v.size(); i++) { // 맨 처음 한번 해줌 
		// 아무것도 안한 상태에서 최대 모양의 크기를 알기 위해서임
		int x = v[i].first, y = v[i].second;
		if (!visit[y][x]) { // 처음에는 모든 자잘한 부분은 다해줘야하함
			int s = dfs(x, y, 1);
			if (max1 < s) max1 = s;
		}
	}

	memset(visit, 0, sizeof(visit));
	// 최대 값을 알게되었음

	for (int i = 0; i < e.size(); i++) {
		int x = e[i].first, y = e[i].second;
		map[y][x] = 1;
		int s = dfs(x, y, 1);
		if (max1 < s) max1 = s;
		map[y][x] = 0;
		memset(visit, 0, sizeof(visit));
	}

	cout << max1 << "\n";
}

// 먼저 1의 좌표 근처의 0인 좌표의 인덱스들을 모조리 찾음
// 그 인덱스들을 1로 하나씩 차근차근 만들면서 dfs 진행함
// 그리고 굳이 전체를 dfs 할 필요가 없음 새로 1을 만든 부분 부터 dfs 를 
// 시작함 그리고 맨 처음에 한번 dfs 를 해줘야하는데
// 방금 전에 말한 새로 1을 만든 부분부터 dfs를 하기 때문임
// 비교를 해줘야 하는데 맨 처음에 가장 큰 모양과 새로 나온 모양의 크기를
//비교해주기 위해서임 