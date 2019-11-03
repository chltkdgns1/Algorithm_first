#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector <int> v;

bool cmp(const int &a, const int &b) {
	return a > b;
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	for (int i = 10; i >= 0; i--) v.push_back(i);
	int d =lower_bound(v.begin(), v.end(), 10,cmp) - v.begin();
	cout << d << "\n";
	system("pause");
}