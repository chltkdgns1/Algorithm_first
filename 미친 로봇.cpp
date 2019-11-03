#include <iostream>
using namespace std;
int map[100][100];
bool check[100][100];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
double per[4];
int n;
int b_cnt;
int c_cnt;
double total_p = 0;
void dfs(int xpos, int ypos,int time,double p) {
	if (time == n) {
		total_p += p;
		return;
	}
	for (int i = 0; i < 4; i++) {
		int x = xpos + dx[i];
		int y = ypos + dy[i];
		double q = p * per[i];
		if (check[y][x] == false) {
			check[ypos][xpos] = true;
			dfs(x, y, time + 1, q);
			check[ypos][xpos] = false;
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	double e, w, s, no;
	cin >> e >> w >> s >> no;
	e = e / 100; w = w / 100; s = s / 100; no = no / 100;
	per[0] = s, per[1] = no, per[2] = e, per[3] = w;
	check[50][50] = true;
	dfs(50, 50,0 , 1);
	printf("%.10lf", total_p);
}