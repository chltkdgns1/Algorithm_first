#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Data {
public:
	int ax, bx;
};
bool cmp(const Data&a, const Data&b) {
	if (a.ax == b.ax) return a.bx > b.bx;
	else return a.ax < b.ax;
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int m;
	while (cin >> m) {
		vector <Data> v;
		while (1) {
			int a, b;
			cin >> a >> b;
			if (!a && !b) break;
			if (a <= 0 && b <= 0) continue;
			if (a < 0) a = 0;
			else if (b < 0) b = 0;
			int c = min(a, b), e = max(a, b);
			Data d; d.ax = c, d.bx = e;
			v.push_back(d);
		}
		sort(v.begin(), v.end(), cmp);
		int start = 0, cnt = 0, keep1 = -1, keep2 = -1;
		bool br = 0;
		for (int i = 0; i < v.size(); i++) {
			if (!i) {
				if (start != v[i].ax) break;
				start = v[i].bx;
				cnt++;
				if (m <= start) { br = 1; break; }
			}
			else {
				if (start < v[i].ax || (start >= v[i].ax && i == v.size() - 1)) {
					if (keep1 == -1 || keep2 == -1 || start > keep2) break;
					start = keep2;
					keep1 = keep2 = -1;
					cnt++;
					if (m <= start) { br = 1; break; }
				}
				if (keep1 < v[i].ax) keep1 = v[i].ax;
				if (keep2 < v[i].bx) keep2 = v[i].bx;
			}
		}
		if (br) cout << cnt << "\n";
		else cout << 0 << "\n";
	}
}