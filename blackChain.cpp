#include <iostream>
using namespace std;


int P_go(long long int number, int first, long long int second);
int main() {
	long long int n;
	long long int p;
	cin >> n;
	if (3 <= n && n <= 1000000000000000000) {
		for (long long int i = 2; i <= n; i++) {
			int number = P_go(n, 1, i);
			if (number != -1) {
				cout << number << endl;
				break;
			}
		}
		system("pause");
	}
}

int P_go(long long int number, int first, long long int second) {
	int temp_second = second;
	int third = 1;
	int cut_cnt = 0;
	if (number == 2) {
		return 1;
	}
	else {
		while (true) {
			cut_cnt++;
			number = number - first - second;
			third = third + second;
			second = third + 1;
			if (second >= number) {
				//cout << "temp_second : " << temp_second << endl;
				//cout << "second : " << second << endl;
				break;
			}
		}
		//cout << "cnt : " << cut_cnt << endl;
		if (cut_cnt == temp_second - 1) {
			return cut_cnt;
		}
	}
	return -1;
}