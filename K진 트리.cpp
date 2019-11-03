#include <iostream>
#include <math.h>
#include <map>
using namespace std;
typedef long long ll;
map <ll,int> s1;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	ll n, k, q,a,b,t1,t2,c,d;
	cin >> n >> k >> q;
	while (q--) {
		cin >> a >> b;
		if (k == 1) cout << abs(a - b) << "\n";
		else {
			t1 = a, t2 = b;
			c = 0, d = 0;
			while (t1 != 1) {
				s1.insert({ -t1,c });
				c++;
				t1 = (t1 - 2) / k + 1;
			}
            s1.insert({ -1, c });
			map <ll, int>::iterator it;
			bool br = 0;
			while (t2 != 1) {
				it = s1.find(-t2);
				if (it != s1.end()) {
					cout << (*it).second + d << "\n";
					br = 1;
					break;
				}
				d++;
				t2 = (t2 - 2) / k + 1;
			}
			if (!br) {
				it = s1.find(-1);
				cout << (*it).second + d << "\n";
			}
			s1.clear();
		}
	}
}