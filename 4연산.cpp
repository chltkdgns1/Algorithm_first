#include <iostream>
#include <queue>
#include <string>
#include <set>
using namespace std;
int n, m;
void bfs(int s) {
	set <int> r;
	r.insert(s);
	queue <pair<long long, string>> q;
	q.push({ s,"" });
	while (!q.empty()) {
		long long e = q.front().first;
		string sr = q.front().second;
		q.pop();
		if (e > 1000000000) continue;
		for (int i = 0; i < 4; i++) {
			switch (i) {
			case 0:
				if (e * e <= 1000000000) {
					if(r.find(e * e) == r.end()){
						r.insert(e * e);
						q.push({ e * e,sr + '*' });
						if (m == e*e) {
							cout << sr + '*' << "\n";
							exit(0);
						}
					}
				}
			case 1:
				if (e + e <= 1000000000) {
					if (r.find(e + e) == r.end()) {
						r.insert(e + e);
						q.push({ e + e,sr + '+' });
						if (m == e+e) {
							cout << sr + '+' << "\n";
							exit(0);
						}
					}
				}
				break;
			case 2:
				if (r.find(0) == r.end()){
					r.insert(0);
					q.push({ 0,sr + '-' });
					if (m == 0) {
						cout << sr + '-' << "\n";
						exit(0);
					}
				}
				break;
			case 3:
				if (e != 0) {
					if (r.find(e/e) == r.end()) {
						r.insert(e / e);
						q.push({ e / e,sr + '/' });
						if (m == e/e) {
							cout << sr + '/' << "\n";
							exit(0);
						}
					}
				}
				break;
			}
		}
	}
}
int main() {
	cin >> n >> m;
	if (n == m) {cout << 0; return 0;}
	bfs(n);
	cout << -1 << "\n";
}