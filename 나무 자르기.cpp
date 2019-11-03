#include <iostream>
#include <algorithm>
using namespace std;

int arr[1000000];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m , cut = 0;
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> arr[i];
	sort(arr, arr + n);
	if (arr[0] == arr[n - 1]) {
		if (m % n > 0) {
			cout << arr[0] - (m / (n  + 1)) << endl;
		}
		else cout << arr[0] - (m / (n)) << endl;
	}
	else {
		int cnt = 0; // 총 겹치는 트리
		int i_cnt ; // int i 의 위치 선정
		for (int i = n - 1 ; i > 0; i -= i_cnt) {
			i_cnt = 1;
			cnt++;
			for (int j = i - 1; j >= 0; j--) {
				if (arr[i] == arr[j]) {
					cnt++;
					i_cnt++;
				}
				else break;
			}
			if (m <= cnt * (arr[i] - arr[i - i_cnt])) {
				if (m % cnt > 0) { 
					cout << arr[n - 1] - ((m / cnt) + 1) - cut << endl;
				}
				else {
					cout << arr[n - 1] - ((m / cnt)) - cut << endl;
				}
				break;
			}
			else {
				m -= cnt  * (arr[i] - arr[i - i_cnt]);
				cut += arr[i] - arr[i - i_cnt];
			}
		}
	}
}