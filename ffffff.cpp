#include <iostream>
#include <fstream>
using namespace std;

char st[200010]; int L[200010], R[200010], ls[200010], rs[200010];
bool vis[200010];
int main() {
	ifstream in("input.txt");
	ofstream out("output.txt");
	while (1) {
		if (in.eof()) break;
		int n, k;

		in >> n;
		in >> k;
		in >> st + 1;

		for (int i = 1; i <= n; ++i) L[i] = i - 1, R[i] = i + 1;
		L[1] = n, R[n] = 1;
		bool flag = 0;
		for (int i = 1; i <= n; ++i) if (st[i] == st[L[i]] || st[i] == st[R[i]]) {
			vis[i] = 1; flag = 1;
			if (st[i] != st[R[i]]) ls[i] = i;
			else if (st[i] != st[L[i]]) rs[i] = i;
		}
		if (!flag) {
			if (k & 1) for (int i = 1; i <= n; ++i) {
				if (st[i] == 'B') st[i] = 'W';
				else st[i] = 'B';
			}
			std::cout << (st + 1) << '\n';
			return 0;
		}
		for (int i = 1; i <= n; ++i) {
			if (vis[i] && ls[i]) {
				for (int j = R[i]; !vis[j]; j = R[j]) ls[j] = ls[i];
			}
			if (vis[i] && rs[i]) {
				for (int j = L[i]; !vis[j]; j = L[j]) rs[j] = rs[i];
			}
		}
		for (int i = 1; i <= n; ++i) {
			if (!vis[i]) {
				int p = 0, s = 0;
				if ((i + n - ls[i]) % n < (rs[i] + n - i) % n) p = ls[i], s = (i + n - ls[i]) % n;
				else p = rs[i], s = (rs[i] + n - i) % n;
				if (s <= k) st[i] = st[p];
				else if (k & 1) {
					if (st[i] == 'B') st[i] = 'W';
					else st[i] = 'B';
				}
			}
		}
		out << st + 1 << "\n";
	}
	system("pause");
}