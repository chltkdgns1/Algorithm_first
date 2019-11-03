#include <iostream>
#include <string>
#include <Windows.h>
#include <algorithm>
#include <math.h>
#include <random>
using namespace std;

string Binary(int n) {
	string s;
	while (n) {
		s += n % 2 + 48;
		n /= 2;
	}
	reverse(s.begin(), s.end());
	if (s.length() < 8) {
		int len = s.length();
		for (int i = 0; i < 8 - len; i++) {
			s.insert(0, "0");
		}
	}
	return s;
}

int restoreData(string s) {
	int t = 0;
	for (int i = 0; i < s.length(); i++) {
		t += pow(2, 7 - i) * (s[i] - 48);
	}
	return t;
}

string checkBinary(int &n) {
	string s = Binary(n), t;
	for (int i = s.length() - 8; i < s.length() ; i++) t += s[i];
	n = restoreData(t);
	return t;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int buff = 0x7F;
	bool check = 0;
	while (1) {
		cout << checkBinary(buff) << "\n";
		if (!check) {
			buff >>= 1;
			buff |= 0x80;
			if (buff == 0xFE) check = 1;
		}
		else {
			if (buff == 127) {
				check = 0; buff>>=1;
				buff |= 0x80;
				continue;
			}
			buff <<= 1;
			buff |= 0x01;
		}
		Sleep(500);
	}
}

/*
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int arr[2] = { 0xAA,0x55 };
	int buff = 0x00, i = 0;
	while (1) {
		buff = arr[i];
		cout << checkBinary(buff) << "\n";
		i++;
		if (i == 2) i = 0;
		Sleep(500);
	}
}
*/
/*
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int buff = 0x7F;
	while (1) {
		Sleep(500);
		cout << checkBinary(buff) << "\n";
		buff >>= 1;
		buff |= 0x80;
		if (buff == 0xFF) buff = 0x7F;
		Sleep(500);
	}
}
*/
/*
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int buff = 0xFE;
	while (1) {
		Sleep(500);
		cout << checkBinary(buff) << "\n";
		buff <<= 1;
		buff |= 0x01;
		if (buff == 0xFF) buff = 0xFE;
		Sleep(500);
	}
}
*/
/*
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int buff = 0x7F;
	while (1) {
		Sleep(500);
		buff = rand() % 0x10;
		cout << checkBinary(buff) << "\n";
		Sleep(500);
	}
}
*/

/*
int main() {

	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int buff = 0x7F;
	while (1) {
		cout<<checkBinary(buff)<<"\n";
		Sleep(500);
		if (buff == 0x00) buff = 0xFF;
		else buff <<= 1; // else buff >>= 1;
	}
}
*/

/*
int arr[8]; // 8 비트 표현
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n = 7;
	while (1) {
		arr[n] = 1;
		for (int i = 0; i < 8; i++) cout << arr[i] << " ";
		cout << "\n";
		arr[n] = 0; n--;
		if (n == -1) n = 7;
		Sleep(500);
	}
}
*/