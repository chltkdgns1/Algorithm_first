#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

string s;
typedef long long ll;
vector <int> v;
ll res;
void get(int index,int cnt) {
	if (cnt == 0) {
		ll t = 0, c = 1;
		int a = max(v[0], v[1]);
		int b = min(v[0], v[1]);
		for (int i = a; i >= b; i--,c*=2) {
			if (s[i] == '1') {
				t += c;
				if (t > a - b + 1) return;
			}
		}
		if (t == a - b + 1) res++;
		return;
	}
	if (index == s.length()) return;
 	v.push_back(index);
	get(index + 1, cnt - 1);
	v.pop_back();
	get(index + 1, cnt);
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s;
		for (auto a : s) if (a == '1') res++;
		get(0, 2);
		cout << res << "\n";
		res = 0;
	}
}