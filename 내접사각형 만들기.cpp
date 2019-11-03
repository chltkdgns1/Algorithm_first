#include <iostream>
#include <math.h>
using namespace std;
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	double a, b, c,ac,db,res;
	cin >> a >> b >> c;
	ac = sqrt(a*a - b * b);
	db = sqrt(a*a - c * c);
	res = (ac*db - b * c) / a;
	if (res <= 0) cout << -1 << "\n";
	else cout << res << "\n";
}