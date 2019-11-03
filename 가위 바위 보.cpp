#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		int a = 0, b = 0;
		for (int i = 0; i < n; i++) {
			char x, y; cin >> x >> y;
			if (x == 'R' && y == 'S') a++;
			else if (y == 'R' && x == 'S') b++;
			else if (x == 'S' && y == 'P') a++;
			else if (y == 'S' && x == 'P') b++;
			else if (x == 'P' && y == 'R') a++;
			else if (x == 'R' && y == 'P') b++;
		}
		if (a > b) cout << "Player 1" << "\n";
		else if (a < b) cout << "Player 2" << "\n";
		else cout << "TIE" << "\n";
	}
}