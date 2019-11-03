#include <iostream>
#include <string>
using namespace std;

int arr[13];
int check[11];
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	string s; cin >> s;
	int t = 0, set = 1, cnt = 0, sum = 0;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == 'S') {
			arr[set] = 10;
			if (set < 10) check[set + 1]++, check[set + 2]++;
			set++; cnt = 0;
			sum = 0;
		}
		else if (s[i] == 'P') {
			arr[set] = 10;
			if (set < 10) check[set + 1]++;
			set++; cnt = 0;
			sum = 0;
		}
		else if (s[i] >= 48 && s[i] <= 57) {
			sum += s[i] - 48;
			cnt++;
		}
		else if (s[i] == '-') cnt++;

		if (cnt == 2) {
			cnt = 0;
			arr[set] += sum;
			set++;
			sum = 0;
		}
	}
	for (int i = 1; i <= 12; i++) {
		if (check[i]) t += arr[i] * check[i];
		t += arr[i];
		cout << t << "\n";
	}
	cout << t << "\n";
	system("pause");
}