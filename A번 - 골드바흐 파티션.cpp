#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

int arr[1000001];
bool dp[1000001];
vector <int> v;
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	arr[1] = 1;
	for (int i = 2; i <= 1000000; i++) {
		int k = 2;
		if (!arr[i]) {
			v.push_back(i);
			while (i*k<=1000000) {
				arr[i*k] = 1;
				k++;
			}
		}
	}
	int t;
	cin >> t;
	while (t--) {
		int n, k = 0;
		cin >> n;
		int cnt = 0;
		while (1) {
			if (v[k] > n / 2) break;
			if (!arr[(n - v[k])]) {
				cnt++;
				dp[n - v[k]] = 1;
			}
			k++;
		}
		cout << cnt << "\n";
	}
}