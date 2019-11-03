#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string sum(string a, string b) {
	string res;
	int x = a.length() - 1;
	int y = b.length() - 1;

	if (x < y) swap(a, b), swap(x, y);
	int s = 0;

	while (x != -1 && y != -1) {
		int c = a[x] - 48, d = b[y] - 48;
		int w = (c + d + s) % 10;
		s = (c + d + s) / 10;
		res += w + 48;
		x--, y--;
	}

	while (x != -1) {
		if (s) {
			int t = a[x] - 48;
			if (t == 9) res += '0';
			else {
				s = 0, res += a[x] + 1;
			}
		}
		else res += a[x];
		x--;
	}
	if (s) res += '1';
	reverse(res.begin(), res.end());
	return res;
}

string sub(string a, string b) {
	string res;
	int x = a.length() - 1;
	int y = b.length() - 1;

	if (x < y) {
		res += '-';
		return res;
	}
	int s = 0;

	while (x != -1 && y != -1) {
		int c = a[x] - 48 - s, d = b[y] - 48;
		s = 0;
		if (c < 0) c = 9, s = 1;
		if (c >= d) {
			if (!x && !(c - d)) {x--;break;}
			res += c - d + 48;
		}
		else {
			if (!x) {
				string w; w += '-';
				return w;
			}
			res += c - d + 58;
			s = 1;
		}
		x--, y--;
	}

	while (x != -1) {
		if (s) {
			if (a[x] - 48 == 0) s = 1, res += 57;
			else {
				if(!x && a[x] - 1 == '0') break;
				res += a[x] - 1;
			}
		}
		else {
			if (!x && a[x] - 1 == '0') break;
			res += a[x];
		}
		x--;
	}

	if (res.empty()) res += '0';
	reverse(res.begin(), res.end());
	return res;
}

string mul(string a, string b) {
	string res;
	int x = a.length() - 1;
	int y = b.length() - 1;

	if (x < y) swap(a, b), swap(x, y);

	string t[10];
	t[0] += '0', t[1] = a;
	for (int i = 2; i < 10; i++) {
		int s = 0;
		for (int k = x; k >= 0; k--) {
			int d = (a[k] - 48) * i;
			int w = (d % 10 + s) / 10;
			t[i] += (d % 10 + s) % 10 + 48;
			s = d / 10 + w;
		}
		if (s) t[i] += s + 48;
		reverse(t[i].begin(), t[i].end());
	}

	res += '0';
	string z ;
	while (y != -1) {
		int w = b[y] - 48;
		res = sum(res, t[w] + z);
		z += '0';
		y--;
	}
	return res;
}

string divide(string a, string b) {
	string res;
	if (a.length() < b.length()) {
		res += '0';
		return res;
	}
	int x = 0, y = 0, c = a.length(), d = b.length();
	int s = 0, t;
	while (y != d) {
		t = s * 10 + a[x] - 48;
		res += t / (b[x] - 48);
		s %= (b[x] - 48);
		x--, y--;
	}
	reverse(res.begin(), res.end());
	return res;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	string a, b; cin >> a >> b;
	//cout << mul(a, b) << "\n";
	//cout << sum(a, b) << "\n";
	//cout << sub(a, b) << "\n";
	system("pause");
}