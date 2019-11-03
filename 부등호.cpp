#include <iostream>
using namespace std;

char arr[10];
bool check[10];
int str[10];
int main() {
	int n, cnt = 1, big_number = 9, min_number = 0, index = 0;
	char c;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	c = arr[0];
	for (int i = 0; i < n; i++) {
		if (c == arr[i + 1]) cnt++;
		else {  // 수를 채워넣기 시작함.
			if (c == '<') {
				int index_ = 0;
				for (int i = index; i <index + cnt + 1; i++) {
					str[i] = big_number - cnt + index_ ;
					index_++;
					//cout << str[i] << " ";
				}
				//cout << endl;
				big_number -= cnt + 1;
				index += cnt + 1;
				//cout << index << endl;
				//system("pause");
				c = '>';
			}
			else {
				int index_ = 0;
				for (int i = index; i <index + cnt; i++) {
					str[i] = big_number - index_;
					index_++;
				}
				big_number -= cnt ;
				index += cnt;
				c = '<';
			}
			cnt = 1;
		}
	}
	for (int i = 0; i < n + 1; i++) cout << str[i];
	cout << endl;
	system("pause");
}

/*
for (int i = 0; i < n; i++) {
		cin >> arr[i];
		if (i==0) {
			c = arr[i];
			cnt++;
		}
		else {
			if (c == arr[i]) cnt++;
			else {  // 수를 채워넣기 시작함.
				if (c == '<') {
					for (int i = 0; i < cnt + 1; i++) {
						str[i] = big_number - cnt + i;
					}
					c = '>';
				}
				else {
					for (int i = 0; i < cnt; i++) {
						str[i] = big_number - i;
					}
					c = '<';
				}
				cnt = 0;
			}
		}
	}
		for (int i = 0; i < n; i++) cout << str[i];
	cout << endl;
*/