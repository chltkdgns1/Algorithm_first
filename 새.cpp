#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	int i = 1;
	int cnt = 0;
	while (n > 0) {
		if (i <= n) {
			n -= i;
			i++;
			cnt++;
		}
		else i = 1;
	}
	cout << cnt << "\n";
}

/*

14
1 2 3 4 1 2 1 

*/