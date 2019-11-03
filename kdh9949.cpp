#include <iostream>
#include <string>
#include <vector>
#include <string.h>
#include <algorithm>
using namespace std;


vector <int> v[200001];
vector <int> e;
string ss;
bool visit[200001];
int res = -1;

int solve(int s,char k,int len) {
	visit[s] = 1;
	int cnt = 0;
	for (auto a : v[s]) {
		if (k == 'K') {
			if (ss[a - 1] == 'D' && visit[a])return -1;
			else if (ss[a - 1] == 'D') {
				cnt++;
				if (solve(a, 'D', len + 1) == -1) return -1;
			}
		}
		else if (k == 'D') {
			if (ss[a - 1] == 'H' && visit[a]) return -1;
			else if (ss[a - 1] == 'H') {
				cnt++;
				if (solve(a, 'H', len + 1) == -1) return -1;
			}
		}
		else {
			if (ss[a - 1] == 'K' && visit[a]) return -1;
			else if (ss[a - 1] == 'K') {
				cnt++;
				if (solve(a, 'K', len + 1) == -1) return -1;
			}
		}
	}
	visit[s] = 0;
	if (!cnt && !(len % 3)) res = max(res, len);
	return 0;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, m; cin >> n >> m;
	cin >> ss;
	for (int i = 0; i < ss.length(); i++) {
		if (ss[i] == 'K') e.push_back(i + 1);
	}
	int a, b;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	for (auto a : e) {
		if (solve(a, 'K', 1) == -1) {
			res = -1;
			break;
		}
		memset(visit, 0, sizeof(visit));
	}
	cout << res << "\n";
}