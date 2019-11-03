#include <iostream>
using namespace std;

int main() {
	int x, y;
	int day[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	int temp_cnt = 0;
	cin >> x >> y;
	for (int i = x - 2; i >= 0; i--) {
		temp_cnt += day[i];
	}
	temp_cnt = temp_cnt + y;
	if (temp_cnt % 7 == 1)cout << "MON" << endl;
	if (temp_cnt % 7 == 2)cout << "TUE" << endl;
	if (temp_cnt % 7 == 3)cout << "WED" << endl;
	if (temp_cnt % 7 == 4)cout << "THU" << endl;
	if (temp_cnt % 7 == 5)cout << "FRI" << endl;
	if (temp_cnt % 7 == 6)cout << "SAT" << endl;
	if (temp_cnt % 7 == 0)cout << "SUN" << endl;
}