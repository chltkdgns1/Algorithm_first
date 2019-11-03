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

	for (int i = 0; i < v.size(); i++) { // �� ó�� �ѹ� ���� 
		// �ƹ��͵� ���� ���¿��� �ִ� ����� ũ�⸦ �˱� ���ؼ���
		int x = v[i].first, y = v[i].second;
		if (!visit[y][x]) { // ó������ ��� ������ �κ��� �����������
			int s = dfs(x, y, 1);
			if (max1 < s) max1 = s;
		}
	}

	memset(visit, 0, sizeof(visit));
	// �ִ� ���� �˰ԵǾ���

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

// ���� 1�� ��ǥ ��ó�� 0�� ��ǥ�� �ε������� ������ ã��
// �� �ε������� 1�� �ϳ��� �������� ����鼭 dfs ������
// �׸��� ���� ��ü�� dfs �� �ʿ䰡 ���� ���� 1�� ���� �κ� ���� dfs �� 
// ������ �׸��� �� ó���� �ѹ� dfs �� ������ϴµ�
// ��� ���� ���� ���� 1�� ���� �κк��� dfs�� �ϱ� ������
// �񱳸� ����� �ϴµ� �� ó���� ���� ū ���� ���� ���� ����� ũ�⸦
//�����ֱ� ���ؼ��� 