#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef pair<int, int> par;
vector <par> v;

char buf[1 << 17];
inline char read()
{
	static int idx = 1 << 17;
	if (idx == 1 << 17)
	{
		fread(buf, 1, 1 << 17, stdin);
		idx = 0;
	}
	return buf[idx++];
}

inline int readInt()
{
	int sum = 0;
	bool flg = 1;
	char now = read();

	while (now == 10 || now == 32) now = read();
	if (now == '-') flg = 0, now = read();
	while (now >= 48 && now <= 57)
	{
		sum = sum * 10 + now - 48;
		now = read();
	}
	return flg ? sum : -sum;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, m, a, b; n = readInt(), m = readInt();
	for (int i = 0; i < n; i++) {
		a = readInt(), b = readInt();
		if (a > b) v.push_back({ a,b });
	}
	sort(v.begin(), v.end());
	int s;
	ll res = 0;
	for (int i = v.size() - 1; i >= 0; i--) {
		if (i == v.size() - 1) s = v[i].second, res = v[i].first - s;
		else {
			if (s >= v[i].first) {
				res += v[i].first - v[i].second;
				s = v[i].second;
			}
			else {
				if (s > v[i].second) {
					res += s - v[i].second;
					s = v[i].second;
				}
			}
		}
	}
	cout << res*2 + m << "\n";
}