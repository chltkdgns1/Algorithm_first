#include <iostream>
#include <algorithm>
using namespace std;
int dx[] = { 0,1,0,-1 };
int dy[] = { 1,0,-1,0 };
int vis[55][55];
char board[55][55];
int dp[55][55];
int n, m;
bool cycle;

void dfs(int x, int y)
{
	vis[x][y] = -1;
	if (board[x][y] == 'H') {
		vis[x][y] = 1;
		return;
	}
	for (int i = 0; i < 4; ++i) {
		int k = board[x][y] - '0';
		int nx = x + dx[i] * k;
		int ny = y + dy[i] * k;
		if (0 <= nx && nx < n && 0 <= ny && ny < m) {
			if (vis[nx][ny] == -1) {
				cycle = true;
				return;
			}
			else if (!vis[nx][ny]) {
				dfs(nx, ny);
			}
		}
	}
	vis[x][y] = 1;
}

int rec(int x, int y)
{
	if (x < 0 || x >= n || y < 0 || y >= m || board[x][y] == 'H')return 0;
	int& ret = dp[x][y];
	if (ret)return ret;
	ret = 1;
	for (int i = 0; i < 4; ++i) {
		int k = board[x][y] - '0';
		int nx = x + dx[i] * k;
		int ny = y + dy[i] * k;
		ret = max(ret, 1 + rec(nx, ny));
	}
	return ret;
}

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i)scanf("%s", board[i]);
	dfs(0, 0);
	if (cycle) {
		puts("-1");
		return 0;
	}
	printf("%d",rec(0,0));
}