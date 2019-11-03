#include <iostream>
using namespace std;
typedef unsigned long long ll;
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ll n, c = 0; cin >> n;
	while (n) {
		if (n % 3LL == 2) return !printf("NO\n");
		c += n % 3LL;
		n /= 3LL;
	}
	puts(c ? "YES" : "NO");
	return 0;
}