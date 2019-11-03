#include <iostream>
#include <algorithm>
using namespace std;
int a[300001];
bool cmp(const int &x, const int &y)
{
	return x > y;
}
int main() {
	int n; 
	int ans = 0; 
	int need = 0; 
	cin >> n;
	for (int i = 0; i < n; i++)cin >> a[i];
	sort(a, a + n, cmp); 
	for (int i = 0; i < n; i++)	{
		ans += (a[i] + n >= need);
		need = max(need, a[i] + i + 1);
	}
	cout << ans;
	return 0;
}

