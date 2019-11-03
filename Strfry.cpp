#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	while (n--) {
		bool br = false;
		string s1,s2;
		cin >> s1 >> s2;
		sort(s2.begin(), s2.end());
		sort(s1.begin(), s1.end());
		if (s1 != s2) cout << "Impossible" << "\n";
		else cout << "Impossible" << "\n";
	}
}