#include <iostream>
using namespace std;

int main() {
	int test_case;
	int x, y;
	cin >> test_case;
	for (int i = 0; i < test_case; i++) {
		int cnt = 3;
		int cnt_cnt = 0;
		cin >> x >> y;
		if (y - x == 1) {
			cout << "1" << endl;
			continue;
		}
		else if (y - x == 2) {
			cout << "2" << endl;
			continue;
		}
		for (int i = x + 1; i <= y; i++) {
			if (i - x == 1) {
				continue;
			}
			else if (i - x == 2) {
				continue;
			}
			if (cnt_cnt == cnt - 1) {
				cnt++;
				cnt_cnt = 0;
			}
			cnt_cnt++;
		}
		cout << cnt << endl;
	}
	//system("pause");
}