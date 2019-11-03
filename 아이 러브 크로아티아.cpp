#include <iostream>
using namespace std;
int e_time = 210;
int main() {
	int k, n , index ;
	cin >> k >> n;
	index = k;
	for (int i = 0; i < n; i++) {
		int t;
		char ans;
		cin >> t >> ans;
		if (e_time - t <= 0) {
			cout << index << endl;
			break;
		}
		if (ans == 'T') {
			e_time -= t;
			index = (index + 1);
			if (index == 9) index = 1;
		}
		else e_time -= t;	
	}
}