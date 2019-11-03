#include <iostream>
#include <algorithm>
using namespace std;

class xy {
public:
	int x, y;
};
int arr[5] = { 5,5,5,5,5 };
xy map[10][10];

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int cnt = 0;
	for (int i = 0; i < 10; i++) {
		for (int k = 0; k < 10; k++) {
			int a; cin >> a;
			map[i][k].x = map[i][k].y = a;
			if (map[i][k].x) cnt++;
		}
	}
	int res = 0;
	while (cnt) {
		for (int i = 0; i < 10; i++) {
			for (int k = 0; k < 10; k++) {
				if (map[i][k].x) {
					if (k && map[i][k - 1].x) map[i][k].x = map[i][k - 1].x + 1;
					if (i && map[i - 1][k].y) map[i][k].y = map[i - 1][k].y + 1;
				}
			}
		}

		int a = 0, b, c;
		for (int i = 0; i < 10; i++) {
			for (int k = 0; k < 10; k++) {
				if (map[i][k].x ) {
					int t = min(map[i][k].x, map[i][k].y);
					if (a < t) a = t, b = k, c = i;
				}
			}
		}
		cnt -= a * a;

		for (int i = c; i > c - a; i--) {
			for (int k = b; k > b - a; k--) {
				map[i][k].x = map[i][k].y = 0;
			}
		}
		res++;
	}
	cout << res << "\n";
	system("pause");
}