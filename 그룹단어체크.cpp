#include <iostream>
#include <string>
#include <math.h>
using namespace std;

int main() {
	int test, index,break_=0;
	char temp;
	string array;
	cin >> test;
	int total_cnt = test;
	for (int i = 0; i < test; i++) {
		cin >> array;
		for (int i = 0; i < array.length(); i++) {
			index = i;
			for (int j = i + 1 ; j < array.length(); j++) {
				if (array[i] == array[j]) {
					if (abs(index - j) > 1) {
						total_cnt--;
						break_ = 1;
						break;
					}
					index = j;
				}
			}
			if (break_ == 1) break;
		}
		break_ = 0;
	}
	cout << total_cnt << endl;
}

