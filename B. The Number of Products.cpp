#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
const int N = 200 * 1000 + 13;
int n;
int a[N];

inline void solve() {
	int cnt1 = 0, cnt2 = 0;
	int bal = 0;
	ll ansP = 0;
	for (int i = 0; i < n; i++) {
		if (bal % 2 == 0) cnt1++;
		else cnt2++;
		if (a[i] < 0) bal++;
		if (bal % 2 == 0) ansP += cnt1;
		else ansP += cnt2;
	} 
	cout << n * 1ll * (n + 1) / 2 -  ansP << ' ' << ansP << "\n";
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	solve();
	system("pause");
}