#include <iostream>
using namespace std;

int arr[1000001];
int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	int n, a, b;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	cin >> a >> b;
	long long t = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] - a <= 0) t += 1;
		else {
			if (!((arr[i] - a) % b)) t += (arr[i] - a) / b + 1;
			else t += (arr[i] - a) / b + 2;
		}
	}
	cout << t << "\n";
}