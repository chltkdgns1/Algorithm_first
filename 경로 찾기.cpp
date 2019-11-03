#include <iostream>
#include <queue>
using namespace std;
int n;
int map[100][100];
bool check[100];
bool key[100][100];

void bfs(int x, int y) {
	queue <int> q;
	q.push(x);
	check[x] = true;
	while (!q.empty()) {
		int data_x = q.front();
		q.pop();
		for (int i = 0; i < n; i++) {
			if (map[data_x][i] == 1 && check[i] == false) {
				check[i] = true;
				q.push(i);
			}
			if (i == y && map[data_x][i] == 1) {
				key[x][y] = 1;
				for (int i = 0; i < n; i++) check[i] = 0;
				return;
			 }
		}
	}
	for (int i = 0; i < n; i++) check[i] = 0;
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			bfs(i, j);
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << key[i][j] << " ";
		}
		cout << endl;
	}
}