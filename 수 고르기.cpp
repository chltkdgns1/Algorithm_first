#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
using namespace std;

multiset <int> s;
int arr[1000001];
vector <int> v;
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++) cin >> arr[i];
	sort(arr, arr + n);
	for (int i = 1; i < n; i++) v.push_back(arr[i] - arr[i - 1]);
	for (int i = 0; i < n - k - 1; i++) s.insert(v[i]);
	int start = 0, end = n - k - 1;
	int m = *s.begin();
	m += arr[end] - arr[start];
	for (; end < n - 1; start++, end++) {
		s.insert(v[end]);
		s.erase(s.find(v[start]));
		m= min(m, arr[end + 1] - arr[start + 1] + *s.begin());
	}
	cout << m << "\n";
}