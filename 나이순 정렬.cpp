#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class p {
public:
	int a, t;
	string name;
};
p d[100000];

bool cmp(const p &a, const p&b) {
	if (a.a == b.a) return a.t < b.t;
	else return a.a < b.a;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> d[i].a >> d[i].name;
		d[i].t = i;
	}
	sort(d, d + n, cmp);
	for (int i = 0; i < n; i++) {
		cout << d[i].a << " " << d[i].name << "\n";
	}
}