#include <iostream>
using namespace std;
int n, chk[26];
char name[151][31];
bool flag = true;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> name[i];
		chk[(int)name[i][0] - 97]++;
	}
	for (int i = 0; i < 26; i++) {
		if (chk[i] >= 5) {
			cout << (char)(i + 97);
			flag = false;
		}
	}
	if (flag)
		cout << "PREDAJA";
	return 0;
}