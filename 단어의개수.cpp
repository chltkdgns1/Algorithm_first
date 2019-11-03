#include <iostream>
#include <string>
using namespace std;

int main() {
	string array;
	int cnt = 0;
	getline(cin,array);
	for (int i = 0; i<array.length(); i++) {
		if (array[i] != ' ') {
			if (array[i + 1] == ' ' || array[i + 1] == NULL) {
				cnt++;
			}
		}
	}
	cout << cnt << endl;
}