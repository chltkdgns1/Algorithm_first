#include <iostream>
#include <map>
using namespace std;
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, a, d; cin >> n;
	map <int,int> m;
	int s = 0, e = 0; // 같은 것들의 인덱스들 
	for (int i = 1; i <= n; i++) {
		cin >> a;
		m[a]++;
		if (i == 1) d = a, cout << d << "\n";
		else {
			if (i % 2) {
				if (d > a) {
					s++, e++;
					if (s <= i / 2 && i / 2 <= e);
					else {
						auto b = m.lower_bound(d);
						b--; d = (*b).first;
						e = s - 1; s = e - (*b).second + 1;
					}			
				}
				else if (d == a) e++;
				else {
					if (s <= i / 2 && i / 2 <= e);
					else {
						auto b = m.lower_bound(d);
						b++; d = (*b).first;
						s = e + 1; e = s + (*b).second - 1;
					}
				}
			}
			else {
				if (d > a) {
					s++, e++;
					if (s <= i / 2 - 1 && i / 2 - 1 <= e);
					else {
						auto b = m.lower_bound(d);
						b--; d = (*b).first;
						e = s - 1; s = e - (*b).second + 1;
					}
				}
				else if (d == a) e++;
			}
			cout << d << "\n";
		}
	}
}