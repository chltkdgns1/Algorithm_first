#include <iostream>
using namespace std;

int main() {
	char alpa[27] = { 'a','b','c','d','e','f','g'
		,'h','i','j','k','l','m','n','o','p','q'
		,'r','s','t','u','v','w','x','y','z' };
	char array[100];
	int cnt = 0;
	cin >> array;
	for (int i = 0; i < 26; i++) {
		for (int j = 0; array[j] != NULL; j++) {
			if (alpa[i] == array[j]) {
				cout << j << " ";
				cnt = 1;
				break;
			}
		}
		if (cnt != 1) cout << "-1 ";
		cnt = 0;
	}
}