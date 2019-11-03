#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n, w, h;
	int len;
	cin >> n >> w >> h;
	for (int i = 0; i < n; i++) {
		cin >> len;
		if (len <= max(w, h) || w * w + h * h >= len * len) cout << "DA" << endl;
		else cout << "NE" << endl;
	}
	system("pause");
}