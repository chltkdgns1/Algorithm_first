#include <iostream>
#include <string>
#include <map>
using namespace std;

map <string, char> m;
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, p; cin >> n >> p;
	int a, b, c; cin >> a >> b >> c;
	int t = 0; // 현재 점수
	bool q = 0;
	for (int i = 0; i < p; i++) {
		string s; char a;
		cin >> s >> a;
		m[s] = a;
	}
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		if (m[s] == 'W') {
			t += a;
			if (t >= c) q = 1;
		}
		else {
			if (t - b < 0) t = 0;
			else t -= b;
		}
	}
	if (q) cout << "I AM NOT IRONMAN!!" << "\n";
	else cout << "I AM IRONMAN!!" << "\n";
}