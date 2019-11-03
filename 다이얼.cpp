#include <iostream>
#include <string>
using namespace std;

int main() {
	char alpa[8][26] ={
	 { 'A','B', 'C' }, {'D', 'E', 'F'}, {'G', 'H', 'I'},
	 {'J','K', 'L' },{'M', 'N', 'O'}, {'P','Q', 'R', 'S'},
	 {'T', 'U', 'V'}, {'W','X','Y', 'Z'} 
	};

	string array;
	int number_array[16];
	int temp = 0;
	cin >> array;
	
	for (int i = 0; i < array.length(); i++) {
		for (int j = 0; j < 8; j++) {
			for (int k = 0; k < 26; k++) {
				if (array[i] == alpa[j][k]) {
					number_array[i] = j + 2;
				}
			}
		}
	}
	for (int i = 0; i < array.length() ; i++) {
		temp += number_array[i] + 1;
	}
	cout << temp << endl;
}