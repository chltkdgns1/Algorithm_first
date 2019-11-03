#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	string s; cin >> s;
	int c = 0, d = 0;
	for (auto a : s) {
		if (a == 'A') c++;
		else d++;
	}
	if (c > d) cout << "A";
	else if (c < d) cout << "B";
	else cout << "Tie";
}