#include <iostream>
#include <math.h>
using namespace std;
bool Decimal(int number);
int CheckBool(int n);

int dp[1000] = { 2,3,5,7, };
int dp_cnt = 4;
int array_[51];
bool array__[51] = { false };

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> array_[i];
	}
}

bool CheckDuo(int n, int start) {
	if (CheckBool(n) == n) {
		return true;
	}
	if (array__[start] == true) {
		return CheckDuo(n, start + 1);
	}
	for (int j = start + 1; j < n; j++) {
		if (array__[j] == true);
		else if (Decimal(array_[start] + array_[j]) == true) {
			array__[start] = true;
			array__[j] = true;
			CheckDuo(n, start + 1);
		}
	}
}

int CheckBool(int n) {
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		if (array__[i] == true) {
			cnt++;
		}
	}
	return cnt;
}

bool Decimal(int number) {
	for (int i = 0; i < dp_cnt; i++) {
		if (number % dp[i] == 0) {
			return false;
		}
	}
	
		
		
		
		

}