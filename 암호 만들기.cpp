#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector <char> v;
char alpa[5] = { 'a','e','i','o','u' };
int d[16];
int n, m;
bool check() {
	int a = 0, b = 0;
	for (int i = 0; i < m; i++) {
		if (d[i] != 0) {
			bool br = 0;
			for (int j = 0; j < 5; j++) {
				if (v[i] == alpa[j]) { a++; br = 1; break; }
			}
			if (!br) b++;
		}
	}
	if (a >= 1 && b >= 2) return true;
	else return false;
}
void dfs(int index,int cnt) {
	if (cnt == n) {
		if (check() == true) {
			for (int i = 0; i < m; i++) {
				if (d[i] != 0) {
					cout << v[i];
				}
			}
			cout << "\n";
		}
		return;
	}
	if (index == m) return;
	d[index] = 1;
	dfs(index + 1, cnt + 1);
	d[index] = 0;
	dfs(index + 1,cnt);
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	char c;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> c;
		v.push_back(c);
	}
	sort(v.begin(), v.end());
	dfs(0, 0);
}