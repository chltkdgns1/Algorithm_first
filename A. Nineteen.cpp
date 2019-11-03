#include <iostream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

map <char, int> m;
int arr[4], brr[4] = { 3,1,3,1 };
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	string s,e = "nineteen"; cin >> s;
	for (int i = 0; i < s.length(); i++) m[s[i]]++;
	int cnt = 0, res = 987654321;
	for (auto a : e) {
		if (!m[a]) continue;
		arr[cnt++] = m[a];
		m[a] = 0;
	}
	if (arr[0] <= 3) res = arr[0] / 3;
	else res = (arr[0] - 1) / 2 ;
	for (int i = 1; i < 4; i++) {
		res = min(res,arr[i] / brr[i]);
	}
	cout << res << "\n";
}