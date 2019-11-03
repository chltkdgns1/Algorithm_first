#include <cstdio>
#include <queue>
using namespace std;
#define INF    987654321
struct Point {
	int y, x;
};
int n;
int map[101][101];
int visit[101][101] = { 0, };
int lo = INF, hi = 0;
queue<Point > que;
void init()
{
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			visit[i][j] = 1;
		}
	}
	while (!que.empty())        que.pop();
}
int bfs(int limit)
{
	int dy[4] = { -1, 0, 0, 1 };
	int dx[4] = { 0, -1, 1, 0 };
	Point current;
	// 범위에 맞는 배열을 만들어 놓고 길이 있는지 보자
	for (int l = lo; l <= hi; l++) {
		init();
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (map[i][j] < l)        visit[i][j] = 1;
				else if (map[i][j] >= l && map[i][j] <= l + limit)
					visit[i][j] = 0;
				else visit[i][j] = 1;
			}
		}
		if (visit[1][1])    continue;

		visit[1][1] = 1;
		current.y = current.x = 1;
		que.push(current);

		while (!que.empty()) {
			current = que.front();
			que.pop();
			if (current.y == n && current.x == n)    return 1;
			for (int i = 0; i < 4; i++) {
				Point next;
				next.y = current.y + dy[i];
				next.x = current.x + dx[i];

				if (next.y > 0 && next.y <= n && next.x > 0 && next.x <= n
					&& visit[next.y][next.x] == 0) {
					visit[next.y][next.x] = 1;
					que.push(next);
				}
			}
		}
	}
	return 0;
}
int solve(int end)
{
	int start = 0;
	int middle;
	int res;
	while (start <= end) {
		middle = (start + end) / 2;
		if (bfs(middle))    end = middle - 1;
		else                start = middle + 1;
	}
	return end + 1;
}
int main()
{
	int i, j;
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] < lo)    lo = map[i][j];
			if (map[i][j] > hi)    hi = map[i][j];
		}
	}
	printf("%d\n", solve(hi - lo));
	return 0;
}
