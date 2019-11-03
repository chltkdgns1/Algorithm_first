#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector <int> v[8];
bool visit[8];
int d[8]; // 현재 이새키가 갖고 있는 숫자
bool check[7][7]; // 갯수
int res;
void solve(int s, int key, int cnt,vector <int> e) {
	e.push_back(key);
	for (auto a : e) cout << a << " ";
	cout << "\n";
	cout << cnt << "\n";
	cout << check[6][3] << "\n";
	cout << "\n";
	visit[s] = 1;
	for (auto a : v[s]) {
		if (visit[a]) {
			if (!check[key][d[a]] && !check[d[a]][key]) {
				check[key][d[a]] = 1;
				check[d[a]][key] = 1;
				e.push_back(a);
				cnt++;
			}
		}
	}
	for (auto a : v[s]) {
		if (!visit[a]) {
			for (int k = 1; k <= 6; k++) {
				if (!check[key][k]) {
					check[key][k] = 1;
					check[k][key] = 1;
					solve(a, k, cnt + 1,e);
					check[key][k] = 0;
					check[k][key] = 0;
				}
			}
		}
	}

	for (auto a : e) {
		check[key][d[a]] = 0;
		check[d[a]][key] = 0;
	}
	e.pop_back();
	visit[s] = 0;
	res = max(res, cnt);
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, m; cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	vector <int> e;
	d[1] = 3;
	solve(1, 3, 0,e);
	d[1] = 0;

	cout << res << "\n";
	system("pause");
}