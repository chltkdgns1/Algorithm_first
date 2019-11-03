#include <iostream>
using namespace std;

pair<int, int> a[4]; // a 사각형
pair<int, int> b[4]; // b 사각형의 좌표

int Square() {
	bool br = 0;
	for (int i = 0; i < 4; i++) {
		if (a[0].first<= b[i].first && b[i].first <= a[i].first) {
			bool br_2 = 0;
			for (int k = 0; i < 4; k++) {
				if (a[0].second <= b[k].second  && b[k].second <= a[1].second) {
					br_2 = 1;
					if (b[1].first == a[0].first || b[0].first == a[1].first) {
						return 1;
						// 붙어있는 경우
					}
					if (b[0].second == a[1].second || b[1].second == a[0].second) {
						return 1;
						// 붙어잇는 경우
					}
					return 2;
				}
			}
			br = 1;
			if (!br_2) return -1;
		}
	}
	if (!br) return -1;
}


int checkOnePoint() { 
	int cnt = 0;
	for (int i = 0; i < 4; i++) {
		for (int k = 0; k < 4; k++) {
			if (a[i].first == b[k].first && a[i].second == b[k].second) {
				cnt++;
			}
		}
	}
	return cnt;
}

int main() {
	for (int i = 0; i < 2; i++) {
		cin >> a[i].first >> a[i].second;
	}

	a[2].first = a[0].first, a[2].second = a[1].second;
	a[3].first = a[1].first, a[3].second = a[0].second;

	for (int i = 0; i < 2; i++) {
		cin >> b[i].first >> b[i].second;
	}

	b[2].first = b[0].first, b[2].second = b[1].second;
	b[3].first = b[1].first, b[3].second = b[0].second;

	int same_point = checkOnePoint();
	if (same_point == 1) {
		cout << "POINT" << "\n";
	}
	else {
		int s = Square();
		if (s == -1) cout << "NULL" << "\n";
		else if (s == 1) cout << "LINE" << "\n";
		else cout << "FACE" << "\n";
	}
}