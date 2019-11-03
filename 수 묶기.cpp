#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector <int> a, b;
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	int cnt = 0; 
	long long t = 0;
	for (int i = 0; i < n; i++) {
		int c; cin >>c;
		if (c == 1) t += 1;
	    else if (c < 0) b.push_back(c);
		else if(c>0) a.push_back(c);
		else cnt++;
	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	if (!a.empty()) {
		for (int i = a.size() - 1; i > 0; i -= 2) t += a[i] * a[i - 1];
		if (a.size() % 2 == 1) t += a[0];
	}
	if (!b.empty()) {
		for (int i = 0; i < b.size() - 1 ; i += 2) { 
			t += b[i] * b[i + 1];
		}
		if (b.size() % 2 == 1) {
			if (!cnt) t += b[b.size() - 1];
		}
	}
	cout << t << "\n";
}