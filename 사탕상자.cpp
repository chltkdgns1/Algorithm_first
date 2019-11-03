#include <iostream>
using namespace std;

int arr[10000001];
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	int th = 0;
	for (int i = 0; i < n; i++) {
		int a, b, c;
		cin >> a;
		if (a == 1) {
			cin >> b;
			if (!th) {arr[b] = 1;	th = b;}
			else {

			}
		}
		else if (a == 2) {
			cin >> b >> c;
		}
	}
}