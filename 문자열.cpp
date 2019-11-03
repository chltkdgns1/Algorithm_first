#include <iostream>
#include <string>
using namespace std;
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	while (n--) {
		string s; cin >> s;
		cout << s[0] << s.back() << "\n";
	}
}