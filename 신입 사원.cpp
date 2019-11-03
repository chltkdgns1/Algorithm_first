#include <iostream>
#include <algorithm>
using namespace std;

class Score {
public:
	int a, b;
};
Score s[100000];
Score null;
bool cmp1(const Score &a, const Score &b) {
	return a.a > b.a;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t, n;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int cnt = 0;
		cin >> n;
		for (int j = 0; j < n; j++) cin >> s[j].a >> s[j].b;
		sort(s, s + n, cmp1);
		for (int i = 0; i < n - 1; i++) {
			for (int j = i + 1; j < n; j++) {
				if (s[i].b > s[j].b) {
					cnt++;
					break;
				}
			}
		}
		cout <<n - cnt << endl;
		for (int i = 0; i < n; i++) s[i] = null;
	}
}