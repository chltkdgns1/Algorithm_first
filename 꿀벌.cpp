#include <iostream>
#include <string>
using namespace std;

string r[7] = { "Re","Pt","Cc","Ea","Tb","Cm","Ex" };
int arr[7];
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	string s;
	int n = 0;
	while (getline(cin, s)) {
		string e;
		for (int i = 0; i < s.length(); i++) {
			if (s[i] != ' ') e += s[i];
			if (s[i] == ' ' || i == s.length() - 1) {
				n++;
				for (int k = 0; k < 7; k++) {
					if (e == r[k]) {
						arr[k]++;
						break;
					}
				}
				e.clear();
			}
		}
	}
	int t = 0;
	cout.precision(2);
	for (int i = 0; i < 7; i++) t += arr[i];
	for (int i = 0; i < 7; i++) {
		cout << r[i] << " " << arr[i] << " " << fixed << double(arr[i]) / n << "\n";
	}
	cout << "Total " << n << " " << "1.00" << "\n";
}
