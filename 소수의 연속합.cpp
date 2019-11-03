#include <iostream>
#include <vector>
using namespace std;
bool arr[4000001];
vector <int> v;
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	arr[1] = 1;
	for (int i = 2; i <= 4000000; i++) {
		if (!arr[i]) {
			v.push_back(i);
			int k = 2;
			while (i*k <= 4000000) {
				arr[i*k] = 1;
				k++;
			}
		}
	}
	int s = 0, e = 0, t = 0, n, cnt = 0;;
	cin >> n;
	while (s <= e && e < v.size()) {
		if (e - s == 1 && t > n) break;
		if (t < n) t += v[e],e++;
		else if (t > n)t -= v[s], s++;
		else cnt++, t += v[e], e++;
	}
	cout << cnt << "\n";
}