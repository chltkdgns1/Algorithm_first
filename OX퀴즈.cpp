#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		int score = 0, seri = 1;
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == 'O') {
				score += seri;
				seri++;
			}
			else seri = 1;
		}
		cout << score << "\n";
	}
}