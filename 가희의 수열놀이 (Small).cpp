#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
vector <int> v;
int d[1000001], total[1000001];
int s, e, n, m, cnt;
bool ch, flag;
unordered_set <int> y;
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	if (m > 1000000) flag = 1;
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		if (a == 1) {
			int b, q; cin >> b;
			if (flag) continue;
			q = b % m;
			v.push_back(q);
			y.insert(q);
			total[q]++;
			e++; d[q]++;
			while (d[v[s]] >= 2) d[v[s]]--, s++;
		}
		else if (a == 2) {
			if (flag) continue;
			if (!v.empty()) {
				int w = v.back() % m;
				v.pop_back();
				total[w]--; d[w]--; e--;
				if (!d[w] && total[w]) {
					for (int i = s - 1; i >= 0; i--) {
						if (v[i] == w) {
							for (int k = i; k <= s - 1; k++) d[v[k]]++;
							s = i;
							break;
						}
					}
				}
				else if (!d[w] && !total[w]) {
					y.erase(w);
				}
			}
		}
		else {
			if (flag) {cout << -1 << "\n"; continue;}
			if (y.size() == m) cout << e - s << "\n";
			else cout << -1 << "\n";
		}
	}
}