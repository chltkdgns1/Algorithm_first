#include <iostream>
#include <map>
#include <string>
using namespace std;
map <string, int> m;
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	string s;
	map <string, int>::iterator it;
	int cnt = 0;
	while (getline(cin, s)) {
		cnt++;
		m[s]++;
	}
	cout.precision(4);
	for (auto a : m) {
		cout << a.first << " " << fixed << 100.0*a.second / cnt << "\n";
	}
}