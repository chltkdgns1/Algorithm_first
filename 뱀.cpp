#include <iostream>
#include <vector>
using namespace std;

int map[100][100];
vector <pair<int, char>> v;
vector <pair<int, int>> xy;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int n, k, l;

int changeDir(char d, int dir) {
	if (d == 'L') {
		switch (dir) {
		case 0:    
			dir = 2;
			break;
		case 1:   
			dir = 3;
			break;
		case 2:
			dir = 1;
			break;
		case 3:
			dir = 0;
			break;
		}
	}
	else if(d == 'D'){
		switch (dir) {
		case 0:
			dir = 3;
			break;
		case 1:
			dir = 2;
			break;
		case 2:
			dir = 0;
			break;
		case 3:
			dir = 1;
			break;
		}
	}
	return dir;
}
int Go(int len,int time,int dir) {
	int x = xy[0].first + dx[dir];
	int y = xy[0].second + dy[dir];
	if (x >= 0 && y >= 0 && x < n && y < n) {
		for (int i = 1; i < len; i++) {
			if (xy[i].first == x && xy[i].second == y) {
				return time; // Áö ¸ö¿¡ ºÎµ÷Çô¼­ µðÁü.
			}
		}
		if (map[y][x] == 2) { // »ç°ú¸¦ ¸ÔÀ½
			map[y][x] = 0;
			xy.push_back({ 0,0 });
			len++;
		}
		for (int i = len - 1; i > 0; i--) {
			xy[i].first = xy[i - 1].first;
			xy[i].second = xy[i - 1].second;
		}
		xy[0].first = x;
		xy[0].second = y;
		for (int i = 0; i < l; i++) {
			if (v[i].first == time) {
				dir = changeDir(v[i].second, dir);
				break;
			}
		}
		Go(len, time + 1, dir);
	}
	else {
		return time; // º®¿¡ ºÎµ÷Çô¼­ µðÁü
	}
}
int main() {
	cin >> n >> k;
	for (int i = 0; i < k; i++) {
		int a, b;
		cin >> a >> b;
		map[a - 1][b - 1] = 2;
	}
	cin >> l;
	for (int i = 0; i < l; i++) {
		int a; char c;
		cin >> a >> c;
		v.push_back({ a,c });
	}
	xy.push_back({ 0,0 });
	cout<<Go(1,1, 2) <<endl;
}