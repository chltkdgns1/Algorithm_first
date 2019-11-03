#include <iostream>
#include <algorithm>
using namespace std;
int a[51];
int b[51];
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) cin >> a[i] >> b[i];
	sort(a, a + m);
	sort(b, b + m);
	if (b[0] * 6 < a[0]) { 
		cout << b[0] * n << endl;
	} 
	else { // 아닐경우
		if ((n / 6) * a[0] + (n % 6) * b[0] < (n / 6 + 1) * a[0]) 
			cout << (n / 6) * a[0] + (n % 6) * b[0] << endl;	
		else cout << (n / 6 + 1) * a[0] << endl;
	}
}

/*
if (n < 6) { // 6개보다 적을 때 낱개보다 세트 1개가 쌀 경우
			if (b[0] * n <= a[0]) cout << b[0] * n << endl;
			else cout << a[0] << endl;
		}
		else { // 아닐 경우
			cout << (n / 6) * a[0] + (n % 6) * b[0] << endl;
		}
*/