#include <iostream>
using namespace std;
int arr[1000001];
int n, m, res;
void check(int s) {
	if (s == 0) {
		if (s + 1 < n && !arr[s + 1]) res++;
	}
	else if (s == n - 1) {
		if (s - 1 >= 0 && !arr[s - 1]) res++;
	}
	else {
		if (!arr[s + 1] && !arr[s - 1]) res++;
		else if (arr[s + 1] && arr[s - 1]) res--;
	}
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		if (arr[i] == 1) check(i);
	}
	for (int i = 0; i < m; i++) {
		int a; cin >> a;
		if (!a) cout << res << "\n";
		else {
			int x; cin >> x;
			if (!arr[x - 1]) {
				arr[x - 1] = 1;
				check(x - 1);
			}
		}
	}
}