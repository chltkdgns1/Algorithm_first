#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	vector <int> v;
	for (int i = 0; i < 50; i++) {
		int a; cin >> a;
		v.push_back(a);
	}

	sort(v.begin(), v.end());
	int a,res; cin >> a;
	for (int i = 0; i < 50; i++) {
		if (v[i] == a) {
			res = 50 - i;
			break;
		}
	}
	if (res >= 1 && res <= 5) cout << "A+";
	else if (res >= 6 && res <= 15) cout << "A0";
	else if (res >= 16 && res <= 30) cout << "B+";
	else if (res >= 31 && res <= 35) cout << "B0";
	else if (res >= 36 && res <= 45) cout << "C+";
	else if (res >= 46 && res <= 48) cout << "C0";
	else cout << "F";
}