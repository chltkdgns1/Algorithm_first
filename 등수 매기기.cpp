#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
vector <int> v;
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		v.push_back(a);
	}
	sort(v.begin(), v.end());
	long long t = 0;
	for (int i = 0; i < v.size(); i++) {
		t += abs(v[i] - i - 1);
	}
	cout << t << "\n";
}