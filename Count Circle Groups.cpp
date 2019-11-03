#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

class Data {
public:
	int x, y, r;
	Data(int x,int y,int r):x(x),y(y),r(r){}
};
vector <Data> v;
vector <int> e[3001];
bool visit[3001];
void dfs(int s) {
	visit[s] = 1;
	for (int i = 0; i < e[s].size(); i++) {
		int y = e[s][i];
		if (!visit[y]) {
			dfs(y);
		}
	}
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) {
			int x, y, r;
			cin >> x >> y >> r;
			Data d(x, y, r);
			v.push_back(d);
		}
		for (int i = 0; i < n; i++) {
			for (int k = i + 1; k < n; k++) {
				double dis = sqrt(double((v[i].x - v[k].x)*(v[i].x - v[k].x) + (v[i].y - v[k].y) *(v[i].y - v[k].y)));
				if (dis <= double(v[i].r + v[k].r)) {
					e[i].push_back(k);
					e[k].push_back(i);
				}
			}
		}
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			if (!visit[i]) {
				dfs(i);
				cnt++;
			}
		}
		cout << cnt << "\n";
		v.clear();
		for (int i = 0; i < n; i++) {
			e[i].clear();
			visit[i] = 0;
		}
	}
}