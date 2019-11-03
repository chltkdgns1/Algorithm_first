#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>
using namespace std;
string arr[10];
int alpa[26], n, t_alpa[26];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < arr[i].length(); j++) {
			alpa[arr[i][j] - 65] += pow(10,arr[i].length() - j);
		}
	}
	int cnt = 0, num = 9;
	for (int i = 0; i < 26; i++) if (alpa[i]) cnt++;
	for (int i = 0; i < cnt; i++) {
		int max = 0, index = 0;
		for (int j = 0; j < 26; j++) {
			if (max < alpa[j]) {
				max = alpa[j];
				index = j;
			}
		}
		t_alpa[index] = num--;
		alpa[index] = 0;
	}
	int total = 0;
	for (int i = 0; i < n; i++) {
		string t;
		for (int j = 0; j < arr[i].length(); j++) {
			t += t_alpa[arr[i][j] - 65] + 48;
		}
		total += stoi(t);
	}
	cout << total << "\n";
}