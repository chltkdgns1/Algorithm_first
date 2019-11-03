#include <iostream>
using namespace std;
int main() {
	int t ,r,e,c;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> r >> e >> c;
		if (r < e - c) cout << "advertise" << endl;
		else if (r == e - c) cout << "does not matter" << endl;
		else cout << "do not advertise" << endl;
	}
}