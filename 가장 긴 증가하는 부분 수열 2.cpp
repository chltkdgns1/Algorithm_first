#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;
int arr[1000001];
pair <int, int> p[1000001];
vector <long long> v;
stack <pair<int, int>> st;
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	v.push_back(-9876543210);
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		if (v.back() < arr[i]) {
			v.push_back(arr[i]);
			cnt++;
			p[i] = { cnt,arr[i] };
		}
		else {
			int idx = lower_bound(v.begin(), v.end(), arr[i]) - v.begin();
			v[idx] = arr[i];
			p[i] = { idx ,arr[i] };
		}
	}
	int key = cnt;
	for (int i = n - 1; i >= 0; i--) {
		if (key == p[i].first) {
			st.push(p[i]);
			key--;
			if (key < 0) break;
		}
	}
	cout << cnt << "\n";
	while (!st.empty()) {
		cout << st.top().second << " ";
		st.pop();
	}
}