#include <iostream>
#include <vector>
#include <string.h>
#include <unordered_map>
#include <queue>
#include <string>
using namespace std;

int arr[30][30];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

unordered_map < string, bool> m;

string getst(vector<vector<int>> e) {
	string s;
	for (int i = 0; i < e.size(); i++) {
		for (int k = 0; k < e[0].size(); k++) {
			s += e[i][k] + 48;
		}
	}
	return s;
}

void cycle(vector<vector<int>> &a) {
	int c = a.size(), d = a[0].size();
	for (int i = 0; i < c; i++) {
		for (int k = 0; k < d; k++) {
			arr[k][c - 1 - i] = a[i][k];
		}
	}
	for (int i = 0; i < c; i++) {
		for (int k = 0; k < d; k++) {
			a[i][k] = arr[i][k];
		}
	}
	memset(arr, 0, sizeof(arr));
}

bool solve(vector<vector<int>> e, vector<vector<int>> lock) {

	string s;
	int aa = e.size(), bb = e[0].size();
	int cc = lock.size(), dd = lock[0].size();

	s = getst(e);
	m[s] = 1;
	queue <string> q;
	q.push(s);
	while (!q.empty()) {
		string s = q.front();
 		q.pop();
		int cnt = 0;
		for (int i = 0; i < aa; i++) {
			for (int k = 0; k < bb; k++) {
				e[i][k] = s[cnt] - 48;
				cnt++;
			}
		}

		for (int i = 0; i <= cc - aa; i++) {
			for (int k = 0; k <= dd - bb;k++) {

				int	cnt = 0, dnt = 0;
				bool ch = 0;

				for (int z = 0; z < aa; z++) {
					for (int w = 0; w < bb; w++) {

						int y = z + i;
						int x = w + k;
						if (!lock[y][x]) {
							cnt++;
							if (e[z][w]) dnt++;
						}
						else if (lock[y][x] && e[z][w]) {
							ch = 1;
							break;
						}
					}
					if (ch) break;
				}

				if (cnt == dnt && !ch) {
					return 1;
				}
			}
		}

		vector<vector<int>> r;

		r.resize(e.size()); 
		for (int i = 0; i < e.size(); i++) r[i].resize(e.size());


		for (int i = 0; i < 4; i++) {
			for (int z = 0; z < aa; z++) {
				for (int k = 0; k < bb; k++) {
					if (e[z][k] == 1) {
						int c = z + dy[i];
						int d = k + dx[i];

						if (c >= 0 && c < aa && d >= 0 && d < bb) {
							r[c][d] = 1;
						}
					}
				}
			}
			string e = getst(r);
			if (!m[e]) q.push(e), m[e] = 1;
		}

		r = e;
		for (int i = 0; i < 4; i++) {
			cycle(r);
			string e = getst(r);
			if (!m[e]) q.push(e), m[e] = 1;
		}
	}
	return 0;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
	bool answer = solve(key, lock);
	return answer;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, m; cin >> n >> m;
	vector<vector<int>> a, b;
	a.resize(n), b.resize(n);
	for (int i = 0; i < n; i++) {
		for (int k = 0; k < n; k++) {
			int c; cin >> c;
			a[i].push_back(c);
		}
	}

	for (int i = 0; i < n; i++) {
		for (int k = 0; k < n; k++) {
			int c; cin >> c;
			b[i].push_back(c);
		}
	}

	cout<<solution(a, b);
	system("pause");
}