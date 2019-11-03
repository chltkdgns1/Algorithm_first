#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;


class Data {
public:
	int a, b, c;
};
vector <pair<int, int>> v;
vector <Data> e, q;


bool cmp(Data &a, Data&b) {
	return a.b > b.b;
}
bool cmp2(Data &a, Data &b) {
	return a.a < b.a;
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, r; cin >> n >> r;

	int ms = 0;
	for (int i = 0; i < n; i++) {
		int a, b; cin >> a >> b;
		if(b >= 0) v.push_back({ a,b });
		else {
			e.push_back({ a,b ,i }), q.push_back({ a,b,i });
			ms += b;
		}
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < v.size(); i++) {
		if (v[i].first <= r) r += v[i].second;
		else {
			cout << "NO" << "\n";
			return 0;
		}
	}

	if (r + ms < 0) {
		cout << "NO" << "\n";
		return 0;
	}

	if (!e.size()) {
		cout << "YES" << "\n";
		return 0;
	}

	sort(e.begin(), e.end(),cmp);
	sort(q.begin(), q.end(), cmp2);

	bool check[101];
	memset(check, 0, sizeof(check));

	int ref = 0;
	for (int i = 0; i < e.size(); i++) {

		bool ch = 0;
		int rr = r;

		for (int k = q.size() - 1; k >= 0; k--) {
			if (check[q[k].c]) continue;
			if (q[k].a <= rr) rr += q[k].b;
			else {
				ch = 1;
				break;
			}
		}

		if (!ch) {
			cout << "YES" << "\n";
			return 0;
		}

		check[e[i].c] = 1;
		if (r >= e[i].a) r += e[i].b;
		else break;
	}
	cout << "NO" << "\n";
}