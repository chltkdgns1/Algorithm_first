#include <iostream>
using namespace std;

int main() {
	int i;
	int n;
	cin >> n;
	int sun_room = 1;
	for (i = 1; sun_room < n; i++) {
		sun_room = sun_room + (6 * i);
	}
	cout << i << endl;
}
// 1 6 12 18 23 29 35 40 46 52
// 1 7 19 37 60 89 124 
// 5 6 6 5 6 6
