#include <iostream>
#include <string>
using namespace std;

char d[5] = { 'a','e','i','o','u' };
bool checkAeiou(string s) { // 모음이 하나를 포함하고 있는지 확인
	for (int i = 0; i < s.length(); i++) {
		for (int j = 0; j < 5; j++) {
			if (s[i] == d[j]) return true;
		}
	}
	return false;
}
bool checkThree(string s) {
	int a = 0, b = 0; // a 는 자음의 연속된 갯수 b 는 모음
	for (int i = 0; i < s.length(); i++) {
		bool br = 0;
		for (int j = 0; j < 5; j++) {
			if (s[i] == d[j]) {
				b++; br = 1; a = 0;
				if (b == 3) return false;
				break;
			}
		}
		if (!br) {
			b = 0, a++;
			if (a == 3) return false;
		}
	}
	return true;
}
bool checkTwo(string s) { // 연속으로 2개 나오면 안됨
	char before; // 현재 문자와 비교할 문자
	int cnt = 0;
	for (int i = 0; i < s.length(); i++) {
		if (!i) {
			before = s[i];
			cnt++;
		}
		else {
			if (s[i] == before) {
				cnt++;
				if (s[i] != 'e' && s[i] != 'o') {
					return false;
				}
				else if (cnt > 2) return false;
				before = s[i];
			}
			else {
				before = s[i];
				cnt = 1;
			}
		}
	}
	return true;
}

int main() {
	while (1) {
		string s;
		cin >> s;
		if (s == "end") break;
		if (checkAeiou(s) && checkThree(s) && checkTwo(s)) {
			cout << "<" << s << "> is acceptable." << "\n";
		}
		else cout << "<" << s << "> is not acceptable." << "\n";
	}
}