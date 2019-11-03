#include <iostream>
using namespace std;
int arr[500];
int main() {
	int h, w;
	cin >> h >> w;
	for (int i = 0; i < w; i++) cin >> arr[i];
	int cnt = 0;
	int total = 0;
	for (int i = 0; i < w; i++) total += h - arr[i];
	int w_cnt = 0;
	for (int j = h; j >= 0; j--) {
		for (int i = 0; i < w; i++) {
			if (j > arr[i] ) cnt++;
			else {
				if (w_cnt == 0) {
					total -= cnt;
				}
				cnt = 0;
				w_cnt++;
			}
		}
		if (cnt != 0 ) {
			total -= cnt;
		}
		cnt = 0;
		w_cnt = 0;
	}
	cout << total << endl;
}