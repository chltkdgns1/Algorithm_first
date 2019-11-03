#include <iostream>
using namespace std;

int d[4];
int arr[4];
bool res;
void solve(int index) {
	if (index == 4) {
		int a = 0, b = 0;
		for (int i = 0; i < index; i++) {
			if (d[i] == 1) a += arr[i];
			else b += arr[i];
		}
		if (a == b) res = 1;
		return;
	}
	d[index] = 1;
	solve(index + 1);
	d[index] = 2;
	solve(index + 1);

}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	for (int i = 0; i < 4; i++) {
		cin >> arr[i];
	}

	solve(0);
	if (res) cout << "YES" << "\n";
	else cout << "NO" << "\n";
}