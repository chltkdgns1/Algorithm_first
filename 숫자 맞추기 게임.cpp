#include <iostream>
using namespace std;
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int cnt = 1;
	while (1) {
		int n,n1,n2,n3,n4; cin >> n;
		if (!n) break;
		bool ch = 0;
		if(!(n % 2)) ch = 1; // n1 이 짝수라는 뜻
		n1 = 3 * n;
		if (ch) n2 = n1 / 2;
		else n2 = (n1 + 1) / 2;
		n3 = 3 * n2;
		n4 = n3 / 9;
		if (ch) cout << cnt++ << ". even " << n4 << "\n";
		else cout << cnt++ << ". odd " << n4 << "\n";
	}
}