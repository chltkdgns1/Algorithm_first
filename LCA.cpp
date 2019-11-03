#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <fstream>
using namespace std;

vector <int> v[50001];
int deep[50001], d[50001][18];
bool visit[50001];
inline void dfs(int s, int deeps) {
	deep[s] = deeps;
	visit[s] = 1;
	for (int i = 0; i < v[s].size(); i++) {
		int y = v[s][i];
		if (!visit[y]) {
			d[y][0] = s;
			dfs(y,deeps + 1);
		}
	}
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, m;
	ifstream st("text.txt");
	
	st >> n;
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		st >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	memset(d, -1, sizeof(d));
	dfs(1,0);
	for (int i = 0; i < 18; i++) {
		for (int k = 1; k <= n; k++) {
			if (d[k][i] != -1) {
				d[k][i + 1] = d[d[k][i]][i];
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int k = 0; k < 18; k++) {
			cout << d[i][k] << " ";
		}
		cout << "\n";
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		if (deep[a] < deep[b]) swap(a, b);
		for (int i = 17; i >= 0; i--) {
			if (deep[a] - deep[b] >= (1 << i)) {
				//cout <<"before : "<< i << " " <<a << "\n";
				a = d[a][i];
				//cout << "after : " << a << "\n";
			}
		}
		if (a != b) {
			for(int i =  17; i>=0;i--){
				if (d[a][i] != -1 && d[a][i] != d[b][i]) {
					a = d[a][i];
					b = d[b][i];
				}
			}
			a = d[a][0];
		}
		cout << a << "\n";
	}
}