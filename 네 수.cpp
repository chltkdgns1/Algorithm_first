#include <iostream>
#include <math.h>
typedef long long ll;
using namespace std;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ll a, b, c, d, t;
	cin >> a >> b >> c >> d;
	t = b;
	int cnt = 0;
	while (t) {
		t /= 10;
		cnt++;
	}
	a = a * pow(10, cnt) + b;
	t = d;
	cnt = 0;
	while (t) {
		t /= 10;
		cnt++;
	}
	c = c * pow(10, cnt) + d;
	cout << a + c << "\n";
}