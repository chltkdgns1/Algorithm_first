#include <iostream>
#include <string>
using namespace std;
bool arr[100000001];

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int a, b; cin >> a >> b;
	if (b > 10000000) b = 10000000;
	for (int i = 2; i*i<= b; i++) {
		if (!arr[i]) {
			int k = 2;
			while (i*k <= b) {
				arr[i*k] = 1;
				k++;
			}
		}
	}
	for (int i = a; i <= b; i++) {
		if (!arr[i]) {
		int d = i, t = 0;
			while (d) {
				t *= 10;
				t += d % 10;
				d /= 10;
			}
			if (i == t) cout << i << "\n";
		}
	}
	cout << -1;
}

/*
#include <iostream>
#include <string>
using namespace std;
bool arr[100000001];

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int a, b; cin >> a >> b;
	if (b > 10000000) b = 10000000;
	for (int i = 2; i*i<= b; i++) {
		if (!arr[i]) {
			int k = 2;
			while (i*k <= b) {
				arr[i*k] = 1;
				k++;
			}
		}
	}
	for (int i = a; i <= b; i++) {
		if (!arr[i]) {
			string t = to_string(i);
			int s = 0, e = t.size() - 1; bool ch = 0;
			while (s <= e) {
				if (t[s] != t[e]) {
					ch = 1; break;
				}
				s++, e--;
			}
			if (!ch) cout << i << "\n";
		}
	}
	cout << -1;
}
*/