#include <iostream>
#include <math.h>
typedef long long ll;
using namespace std;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t; cin >> t;
	while(t--){
		ll a, b, c, res;
		cin >> a >> b;
		if (a == b) cout << 0 << "\n";
		else if (a < b) {
			c = a;
			for (int i = 0; i < c; i++) {
				a *= a;
				a %= b;
				cout << a << "\n";
			}
		}
		else cout << a % b << "\n";
	}	
	system("pause");
}