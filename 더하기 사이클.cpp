#include <iostream>
using namespace std;

int main() {
	char array[3] = { NULL };
	char temp_array[3];
	char temp;
	int cnt = 0;
	cin >> array;

	temp_array[0] = array[0];
	if (array[1] == NULL) temp_array[1] = '0';
	else temp_array[1] = array[1];

	if (array[0] == '0' && array[1] == NULL) {
		cout << cnt<< endl;
		return 0;
	}

	while (1) {
		if (array[1] == NULL) {
			array[1] = array[0];
			array[0] = '0';
			cnt++;
		}
		if (array[0] + array[1] - 96 >= 10) {
			temp = array[0] + array[1] - 58;
			array[0] = array[1];
			array[1] = temp ;
		}
		else {
			temp = array[0] + array[1] - 48;
			array[0] = array[1];
			array[1] = temp;
		}
		cnt++;
		if (temp_array[0] == array[0] && temp_array[1] == array[1]) {
			cout << cnt << endl;
			return 0;
		}
	}
}