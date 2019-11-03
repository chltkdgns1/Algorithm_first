#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector <pair<int, int>> v;
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
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n, a, b; n = readInt();
	for (int i = 0; i < n; i++) {
		a = readInt(), b = readInt();
		v.push_back({min(a,b),max(a,b)});
	}
	sort(v.begin(), v.end());
	int s;
	long long res = 0;
	for (int i = 0; i < n; i++) {
		if (!i) s = v[i].second, res += s - v[i].first;
		else {
			if (s <= v[i].first) {
				res += v[i].second - v[i].first;
				s = v[i].second;
			}
			else {
				if (s < v[i].second) {
					res += v[i].second - s;
					s = v[i].second;
				}
			}
		}
	}
	cout << res << "\n";
}