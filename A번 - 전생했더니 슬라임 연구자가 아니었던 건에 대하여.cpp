#include <iostream>
#include <string>
using namespace std;

int map[201][201];
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, m; cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		for (int k = 0; k < s.length(); k++) {
			map[i][k] = s[i] - 48;
		}
	}


}