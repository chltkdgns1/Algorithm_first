#include <iostream>
using namespace std;
bool memo[2000001];
int n , arr[21];
void solve(int index,int data) {
	if (index == n) {
		memo[data] = 1;
		return;
	}
	solve(index + 1,data + arr[index]);
	solve(index + 1,data);
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		memo[arr[i]] = 1;
	}
	solve(0,0);
	for (int i = 1; i <= 2000000; i++) {
		if (!memo[i]) {
			cout << i << "\n";
			break;
		}
	}
	system("pause");
}