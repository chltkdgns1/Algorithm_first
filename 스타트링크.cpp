#include <iostream>
#include <queue>
using namespace std;
int f, s, g, u, d;
int map[1000001];
bool check[1000001];
void bfs(int number) {
	queue <int> q;
	q.push(number);
	check[number] = true;
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		for (int i = 0; i < 2; i++) {
			int nx;
			if (i == 0) nx = x + u;
			else nx = x - d;
			if (nx >= 1 && nx <= f) {
				if (check[nx] == false) {
					check[nx] = true;
					map[nx] = map[x] + 1;
					q.push(nx);
				}
			}
		}
	}
}
int main() {
	cin >> f >> s >> g >> u >> d;
	bfs(s);
	if (map[g] == 0) cout << "use the stairs" << endl;
	else cout << map[g] << endl;
}