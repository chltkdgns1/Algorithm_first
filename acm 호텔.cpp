#include <iostream>
using namespace std;

int CheckRoom(int h, int w, int n);
int main() {
	int test_case;
	int h, w, n;
	cin >> test_case;
	for (int i = 0; i < test_case; i++) {
		cin >> h >> w >> n;
		cout << CheckRoom(h, w, n) << endl;
	}
}

int CheckRoom(int h, int w, int n) {
	int cnt = 0;
	for (int i = 1; i <= w; i++) {
		for (int j = 1; j <= h; j++) {
			cnt++;
			if (cnt == n) {
				return j * 100 + i;
			}
		}
	}
}