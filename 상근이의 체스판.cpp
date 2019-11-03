#include <iostream>
using namespace std;
int main() {
	int r, c, a, b;
	cin >> r >> c;
	cin >> a >> b;
	int cnt = 0;
	for (int i = 0; i < r; i++) {
		for (int x = 0; x < a; x++) {
			for (int j = 0; j < c; j++) {
				if (cnt == 0) {
					for (int y = 0; y < b; y++) {
						cout << "X";
					}
					if (j == c - 1) {
						if (c % 2 != 0) {
							if (x == a - 1) {
								cnt = 1;
							}
							else {
								cnt = 0;
							}
						}
						else {
							if (x == a - 1) {
								cnt = 0;
							}
							else {
								cnt = 1;
							}
						}
						break;
					}
					cnt = 1;
				}
				else {
					for (int y = 0; y < b; y++) {
						cout << ".";
					}
					if (j == c - 1) {
						if (c % 2 != 0) {
							if (x == a - 1) {
								cnt = 0;
							}
							else {
								cnt = 1;
							}
						}
						else {
							if (x == a - 1) {
								cnt = 1;
							}
							else {
								cnt = 0;
							}
						}
						break;
					}
					cnt = 0;
				}
			}
			cout << endl;
		}
	}
}