#include <iostream>
#include <string>
using namespace std;

int arr[53], brr[53];
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	string s, ans;
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		arr[a]++;
	}
	cin.ignore();
	getline(cin, ans);
	for (int i = 0; i < ans.length(); i++) {
		if (ans[i] >= 97 && ans[i] <= 122) brr[ans[i] - 70]++;
		else if (ans[i] == ' ') brr[0]++;
		else brr[ans[i] - 64]++;
	}
	for (int i = 0; i < 53; i++) {
		if (arr[i] != brr[i]) {
			cout << "n" << "\n";
			return 0;
		}
	}
	cout << "y" << "\n";
}