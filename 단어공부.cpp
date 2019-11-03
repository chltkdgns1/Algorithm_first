#include <iostream>
#include <string>
using namespace std;

int main() {
	int data[26] = {-1};
	char alpa[26] = { 'a','b','c','d','e','f','g','h','i','j','k',
		'l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };
	string array;
	cin >> array;
	int cnt = 0;
	int temp = 0;
	int same_data=-1;
	for (int j = 0; j < 26; j++) {
		for (int i = 0; i < array.length(); i++) {
			if (alpa[j] == array[i] || alpa[j] - 32 == array[i]) {
				cnt++;
			}
		}
		if (temp < cnt) { 
			temp = cnt; 
			data[j] = temp;
		}
		else if (temp == cnt) {
			same_data = temp;
			data[j] = temp;
		}
		cnt = 0;
	}
	if (temp == same_data) cout << "?" << endl;
	else {
		for (int i = 0; i < 26; i++) {
			if (data[i] == temp) printf("%c\n", alpa[i] - 32);
		}
	}
}