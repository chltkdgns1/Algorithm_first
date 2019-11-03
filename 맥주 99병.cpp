#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	for (int i = n; i >= 0; i--) {
		if (i == 1) {
			cout << i << " bottle of beer on the wall, " << i << " bottle of beer." << "\n";
			cout << "Take one down and pass it around, no more bottles of beer on the wall." << "\n";
		}
		else if (!i) {
			if (n == 1) {
				cout << "No more bottles of beer on the wall, no more bottles of beer." << "\n";
				cout << "Go to the store and buy some more, " << n << " bottle of beer on the wall." << "\n";
			}
			else {
				cout << "No more bottles of beer on the wall, no more bottles of beer." << "\n";
				cout << "Go to the store and buy some more, " << n << " bottles of beer on the wall." << "\n";
			}
		}
		else if (i == 2) {
			cout << i << " bottles of beer on the wall, " << i << " bottles of beer." << "\n";
			cout << "Take one down and pass it around, " << i - 1 << " bottle of beer on the wall." << "\n";
		}
		else {
			cout << i <<" bottles of beer on the wall, "<<i<<" bottles of beer."<<"\n";
			cout<<"Take one down and pass it around, "<<i - 1<<" bottles of beer on the wall."<<"\n";
		}
		cout << "\n";
	}
}