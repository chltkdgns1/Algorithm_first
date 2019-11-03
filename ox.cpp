#include <iostream>
#include <string>
using namespace std;

int main() {
	string array;
	int test_case, cnt = 0,cnt_=0;
	cin >> test_case;
	for (int i = 0; i < test_case; i++) {
		cin >> array;
		for (int j = 0; j < array.length(); j++) {
			if (array[j] == 'O') {
				cnt_++;
				cnt += cnt_;
			}
			else {
				cnt_ = 0;
			}
		}
		cout << cnt << endl;
		cnt = 0;
		cnt_ = 0;
	}
}