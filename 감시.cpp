#include <iostream>
using namespace std;

class dir {
public:
	int xpos, ypos;
	int data;
	int d[4];
	int idex;
	dir() { for (int i = 0; i < 4; i++) d[i] = 0; idex = 0; }
	void fresh() {
		xpos = ypos = data = idex = 0;
		for (int i = 0; i < 4; i++) d[i] = 0;
	}
};
int dx[5] = {0,1,-1,0,0 };
int dy[5] = {0,0,0,1,-1 };
dir d[65];
dir d_temp[65];
int d_index;
int n, m;
int map[8][8];
int min1 = 10000;
void Go(int index,dir c[]) {
	if (index == d_index) {
		int temp_map[8][8];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) temp_map[i][j] = map[i][j];
		}
		for (int i = 0; i < index; i++) {
			for (int j = 0; j < c[i].idex; j++) {
				int x = c[i].xpos;
				int y = c[i].ypos;
				while (1) {
					x += dx[c[i].d[j]];
					y += dy[c[i].d[j]];
					if (x >= 0 && y >= 0 && x < m && y < n) {
						if (temp_map[y][x] != 6) {
							temp_map[y][x] = -1;
						}
						else break;
					}
					else break;
				}
			}
		}
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (temp_map[i][j] == 0) cnt++;
			}
		}
		if (min1 > cnt) min1 = cnt;
		return;
	}
	int n;
	switch (d[index].data) {
	case 1:
		c[index] = d[index];
		n = c[index].idex;
		c[index].d[n] = 1;
		c[index].idex++;
		Go(index + 1, c);
		c[index].d[n] = 2;
		Go(index + 1, c);
		c[index].d[n] = 3;
		Go(index + 1, c);
		c[index].d[n] = 4;
		Go(index + 1, c);
		break;
	case 2:
		c[index] = d[index];
		n = c[index].idex;
		c[index].d[n] = 1;
		c[index].d[n + 1] = 2;
		c[index].idex += 2;
		Go(index + 1, c);
		c[index].d[n] = 3;
		c[index].d[n + 1] = 4;
		Go(index + 1, c);
 		break;
	case 3:
		c[index] = d[index];
		n = c[index].idex;
		c[index].d[n] = 4;
		c[index].d[n + 1] = 1;
		c[index].idex += 2;
		Go(index + 1, c);
		c[index].d[n] = 1;
		c[index].d[n + 1] = 3;
		Go(index + 1, c);
		c[index].d[n] = 3;
		c[index].d[n + 1] = 2;
		Go(index + 1, c);
		c[index].d[n] = 2;
		c[index].d[n + 1] = 4;
		Go(index + 1, c);
		break;
	case 4:
		c[index] = d[index];
		n = c[index].idex;
		c[index].d[n] = 1;
		c[index].d[n + 1] = 3;
		c[index].d[n + 2] = 2;
		c[index].idex += 3;
		Go(index + 1, c);
		c[index].d[n] = 3;
		c[index].d[n + 1] = 2;
		c[index].d[n + 2] = 4;
		Go(index + 1, c);
		c[index].d[n] = 2;
		c[index].d[n + 1] = 4;
		c[index].d[n + 2] = 1;
		Go(index + 1, c);
		c[index].d[n] = 4;
		c[index].d[n + 1] = 1;
		c[index].d[n + 2] = 3;
		Go(index + 1, c);
		break;
	case 5:
		c[index] = d[index];
		for (int i = 0; i <= 3; i++) c[index].d[i] = i + 1;
		c[index].idex += 4;
		Go(index + 1, c);
		break;
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] >= 1 && map[i][j] <= 5) {
				d[d_index].xpos = j;
				d[d_index].ypos = i;
				d[d_index].data = map[i][j];
				d_index++;
			}
		}
	}
	Go(0, d_temp);
	cout << min1 << endl;
}