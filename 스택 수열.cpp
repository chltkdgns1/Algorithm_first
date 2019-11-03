#include <iostream>
#include <stack>
#include <vector>
using namespace std;
int arr[100001];
int brr[100001];
vector <char> v;
stack <int> s;
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		brr[i] = i + 1;
	}
	int idx1 = 0, idx2 = 0;
	while (idx2 != n ) {
		if (s.empty()) {
			s.push(brr[idx1++]);
			v.push_back('+');
		}
		else {
			if (s.top() < arr[idx2]) {
				s.push(brr[idx1++]);
				v.push_back('+');
			}
			else if (s.top() == arr[idx2]) {
				s.pop();
				v.push_back('-');
				idx2++;
			}
			else {
				cout << "NO" << "\n";
				return 0;
			}
		}
	}
	for (int i = 0; i < v.size(); i++) cout << v[i] << "\n";
}