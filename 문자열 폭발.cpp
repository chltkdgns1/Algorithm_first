#include <iostream>
#include <string>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	string ans;
	string arr;
	cin >> ans;
	cin >> arr;
	int cnt = 0;
	for (int i = 0; i < ans.length(); i++) {
		if (ans[i] == arr[0]) {
			int br = 0;
			int j = 0;
			for (; j < arr.length(); j++) {
				if (ans[i + j] != arr[j]) {
					br = 1;
					break;
				}
			}
			if (br) continue;
			ans.erase(i, j);
			i -= arr.length();
			if (i < 0) i = -1;
		}
	}
	if (ans.empty()) cout << "FRULA" << "\n";
	else cout << ans << "\n";
}

