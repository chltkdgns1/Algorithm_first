#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	vector <int> v; int s = 0;
	for (int i = 0; i < 5; i++) {
		int a; cin >> a;
		s += a;
		v.push_back(a);
	}
	sort(v.begin(), v.end());
	cout << s / 5 << "\n"<<v[2] << "\n";
}