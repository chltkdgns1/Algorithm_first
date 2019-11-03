#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int number;
string n[10];
string result[10];
int arr[10];
int length[10]; // 문자열의 길이가 같은거 인덱스 저장
int len_index = 0;
int len_data[10][8];
int _data = 9;
int Solve() { // 같은 문자열을 찾아 알파벳에 값 부여
	while (1) { // 계속 반복하면서
		checkLen(); // 문자열의 길이가 0이 될때까지 반복.
		if (len_index == 1) { // 가장 긴 문자열이 한개라는 뜻
			result[length[len_index]].at(0) = _data + 48;
			_data--;
			continue;
		}
		for (int i = 0; i < len_index; i++) {
			int cnt = 0;
			 // 일단 문자열의 길이가 같기 때문에 
			 // 맨 앞 문자랑 동일한 문자가 있는지 찾고.
			 // 만약 동일한 문자가 있으면 가장 앞에 있는 문자열에 제일 큰 값 부여.
			for (int j = 0; j < n[length[i]].length(); j++) {
				if (n[length[i]].at(0) == n[length[i]].at(j)) {
					len_data[length[i]][cnt] = j;
					cnt++;
				}
			}
		}
	}
}


void checkLen() { // 가장 긴 문자열의 길이가 같은 문자열 찾기
	// arr[0] 의 인덱스의 크기가 가장크다.
	// 즉 arr[0] 과 같은 문자열을 찾으면 됨.
	for (int i = 0; i < len_index; i++) length[i] = 0; // 데이터 초기화
	len_index = 0;
	for (int i = 0; i < number; i++) {
		if (arr[0] == n[i].length()) {
			length[len_index] = i;
			len_index++;
		}
	}
}

int main() {
	cin >> number;
	for (int i = 0; i < number; i++) {
		cin >> n[i];
		arr[i] = n[i].length();
	}
	sort(arr, arr + number);
}