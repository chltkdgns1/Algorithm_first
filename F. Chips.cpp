#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <string.h>
#include <fstream>
using namespace std;

int check[201];
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	ifstream in("input.txt");
	ofstream out("output.txt");
	if (in.is_open()) {
		int cnt = 0;
		while (1) {
			if (in.eof()) break;

			memset(check, 0, sizeof(check));
			int n, m;
			in >> n;
			in >> m;
			string s; in >> s;
			int cnt = 0;
			for (int i = 0; i < n; i++) {
				if (!i) {
					if (s[i] != s[i + 1] && s[i] != s[n - 1]) check[i] = s[i] - 65, cnt++;
				}
				else if (i == n - 1) {
					if (s[i] != s[i - 1] && s[i] != s[0]) check[i] = s[i] - 65, cnt++;
				}
				else {
					if (s[i] != s[i + 1] && s[i] != s[i - 1]) check[i] = s[i] - 65, cnt++;
				}
			}

			if (cnt == n) {
				if ((m % 2)) {
					for (int i = 0; i < n; i++) s[i] = (s[i] == 'W' ? 'B' : 'W');
				}
				cout << s << "\n";
				return 0;
			}

			int idx = 0, st = -1, e = -1;
			bool ch = 0;
			vector <pair<int, int>> v;

			for (int i = 0; i < n; i++) {
				if (check[i]) {
					idx = i;
					break;
				}
			}

			for (int i = 0; i < n; i++) {
				if (check[idx] && !ch) {
					ch = 1;
					st = idx;
				}
				if (!check[idx] && ch) {
					e = idx - 1;
					e = e < 0 ? n - 1 : e;
					v.push_back({ st,e });
					st = -1, e = -1;
					ch = 0;
				}
				idx++;
				idx %= n;
			}

			for (auto aa : v) {
				int st = aa.first, e = aa.second;
				if(st != e) st--, e++;
				st = st < 0 ? (n - 1) : st, e %= n;

				int t = (abs(e - st) - 1) / 2 + (abs(e - st) - 1) % 2;
				if (e < st) t = (n - 1 - st + e) / 2 + (n - 1 - st + e) % 2;

		
				int a = (st == n - 1 ? 0 : st + 1), b = (e <= 0 ? n - 1 : e - 1);
				int q = st + m + 1;

				if (t <= m) {
					for (int i = 0; i < t; i++) {
						s[a] = s[st];
						s[b] = s[e];
						a++, b--;
						a %= n;
						b = b < 0 ? (n - 1) : b;
					}
				}
				else {
					for (int i = 0; i < m; i++) {
						s[a] = s[st];
						s[b] = s[e];
						a++, b--;
						a %= n;
						b = b < 0 ? (n - 1) : b;
					}
					for (int i = 0; i < t - 2 * m; i++) {
						if (s[q] == s[q - 1]) {
							s[q] = s[q] == 'W' ? 'B' : 'W';
							q++; q %= n;
						}
					}
				}
			}
			out << s << "\n";
		}
	}
	system("pause");
}