#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Data {
public:
	int x, y;
};
vector <Data> v;

int dis(int a,int b,int c,int d) {
	return (a - c)*(a - c) + (b - d)*(b - d);
}

bool cmp(const Data&a, const Data&b) {
	return a.x < b.y;
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		Data a; cin >> a.x >> a.y;
		v.push_back(a);
	}
	sort(v.begin(), v.end(),cmp);
	int min = 987654321;
	for (int i = 1; i < v.size(); i++) {
		if (min > v[i].x - v[i - 1].x) min = v[i].x - v[i - 1].x;
	}
	int res = 987654321;
	for (int i = 0; i < v.size(); i++) {
		for (int k = i + 1; k < v.size(); k++) {
			if (v[k].x - v[i].x <= min) {
				int a = dis(v[k].x, v[k].y, v[i].x, v[i].y);
				if (res > a) res = a;
			}
			else break;
		}
	}
	cout << res << "\n";
}