#include <iostream>
#include <algorithm>
using namespace std;
#define SIZE 105 // 105

struct point {
	int x, y;
	int dir;
};
point robot[SIZE];

struct command {
	int num;
	char com;
	int rep;
};
command store[SIZE];

int x, y, nx, ny;
char input_dir;
int dir;
int A, B, N, M;
int dx[] = { 0,1,0,-1 }; // 동 남 서 북
int dy[] = { 1,0,-1,0 };
int map[SIZE][SIZE];



void problemIn() {
	cin >> A >> B; // B 가 행 A가 열 입니다.
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> robot[i].y >> robot[i].x >> input_dir;
		robot[i].x = (B - robot[i].x);
		robot[i].y = (robot[i].y - 1);
		if (input_dir == 'E') robot[i].dir = 0;
		else if (input_dir == 'S') robot[i].dir = 1;
		else if (input_dir == 'W') robot[i].dir = 2;
		else if (input_dir == 'N') robot[i].dir = 3;
		map[robot[i].x][robot[i].y] = i;
	}
	for (int i = 1; i <= M; i++) {
		cin >> store[i].num >> store[i].com >> store[i].rep;
	}
}

void solve() {

	for (int i = 1; i <= M; i++) {
		int rep_num = store[i].rep;

		while (rep_num--) {
			if (store[i].com == 'F') {
				x = robot[store[i].num].x;
				y = robot[store[i].num].y;
				dir = robot[store[i].num].dir;
				nx = x + dx[dir];
				ny = y + dy[dir];

				if (nx < 0 || ny < 0 || nx >= B || ny >= A) {
					cout << "Robot " << store[i].num << " crashes into the wall" << endl;
					return;
				}
				else if (map[nx][ny] != 0) {
					cout << "Robot " << store[i].num << " crashes into robot " << map[nx][ny] << endl;
					return;
				}
				else if (nx >= 0 && ny >= 0 && nx < B && ny < A) {
					map[x][y] = 0;
					robot[store[i].num].x = nx;
					robot[store[i].num].y = ny;
					map[nx][ny] = store[i].num;
				}
			}
			else if (store[i].com == 'L') {
				dir = robot[store[i].num].dir;
				robot[store[i].num].dir = (dir + 3) % 4;
			}
			else if (store[i].com == 'R') {
				dir = robot[store[i].num].dir;
				robot[store[i].num].dir = (dir + 1) % 4;
			}
		}
	}

	cout << "OK" << endl;
}

int main() {
	problemIn();
	solve();


}