#include <iostream>
#include <vector>
using namespace std;

pair<int, int> d[9];
int dx[4] = { 0,0,1,-1 }, dy[4] = { 1,-1,0,0 };
vector <int> v;
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		v.push_back(a);
	}
	int cnt = 0;
	for (int i = 0; i < 3; i++) {
		for (int k = 0; k < 3; k++) {
			d[cnt] = { k,i };
			cnt++;
		}
	}
	pair<int, int> e;
	for (int i = 0; i < v.size(); i++) {
		if (!i) e = d[v[0]];
		else {
			bool ch = 0;
			for (int k = 0; k < 4; k++) {
				int nx = e.first + dx[k];
				int ny = e.second + dy[k];
				if (nx >= 0 && nx <= 2 && ny >= 0 && ny <= 2) {
					if (nx == d[v[i]].first && ny == d[v[i]].second) {
						ch = 1;
						break;
					}
				}
			}
			if (!ch) {
				cout << "NO";
				system("pause");
				return 0;
			}
		}
	}
	cout << "YES" << "\n";
	system("pause");
}