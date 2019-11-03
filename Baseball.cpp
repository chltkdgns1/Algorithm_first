#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t; cin >> t;
	while (t--) {
		int c = 0, d = 0;
		for (int i = 0; i < 9; i++) {
			int a, b;
			cin >> a >> b;
			if (a < b) d++;
			else if (a > b) c++;
		}
		if (c < d) cout << "Korea" << "\n";
		else if (c > d) cout << "Yonsei" << "\n";
		else cout << "Draw" << "\n";
	}
}