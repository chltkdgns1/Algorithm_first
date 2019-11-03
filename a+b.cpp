#include <iostream>
using namespace std;



int FindXy(int x_1, int y_1, int r_1, int x_2, int y_2, int r_2);
int Distance(int x, int y, int f_x, int f_y);

int x_1, y_1, r_1;
int x_2, y_2, r_2;

int main() {
	int exel_number;
	int collect_index = 0;	
	cin >> exel_number;
	int *collect = new int[exel_number];
	for (int i = 0; i < exel_number; i++) {
		collect[i] = 0;
	}
	for (int i = 0; i < exel_number; i++) {
		cin >> x_1 >> y_1 >> r_1 >> x_2 >> y_2 >> r_2;
		if (x_1 >= -10000 && y_1 >= -10000 && x_2 >= -10000 && y_2 >= -10000 && x_1 <= 10000 && y_1 <= 10000 && x_2 <= 10000 && y_2 <= 10000) {
			collect[collect_index] = FindXy(x_1, y_1, r_1, x_2, y_2, r_2);
		}
		collect_index++;
		//free(collect);
	}
	for (int i = 0; i < exel_number; i++) {
		cout << collect[i] << endl;
	}
	system("pause");
}

int FindXy(int x_1, int y_1, int r_1, int x_2, int y_2, int r_2) {
	int cnt = 0;
	for (int i = -r_1; i <= r_1; i++) {
		for (int j = -r_1; j <= r_1; j++) {
			if (r_1 == Distance(x_1, y_1, x_1 - i, y_1 - j)) {
				for (int k = -r_2; k <= r_2; k++) {
					for (int m = -r_2; m <= r_2; m++) {
						if (r_2 == Distance(x_2, y_2, x_2 - k, y_2 - m)) {
							if (x_1-i ==x_2-k && y_1-j == y_2-m) {
								
								cnt++;
							}
						}
					}
				}
			}
		}
	}
	return cnt;
}

int Distance(int x, int y, int f_x, int f_y) {
	int total;
	if (x < f_x) {
		total = f_x - x;
	}
	else {
		total = x - f_x;
	}
	if (y < f_y) {
		total += f_y - y;
	}
	else {
		total += y - f_y;
	}
	return total;
}


