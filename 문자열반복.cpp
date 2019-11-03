#include <iostream>
#include <string>
using namespace std;

int main() {
	int test, number;
	string array;
	string temp;
	string Null;
	cin >> test;
	for (int i = 0; i < test; i++) {
		cin >> number;
		cin >> array;
		for (int j = 0; j < array.length(); j++) {
			for (int i = 0; i < number; i++) {
				temp += array[j];
			}
		}
		cout << temp << endl;
		temp = Null;
		array = Null;
	}
}