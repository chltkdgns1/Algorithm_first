#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int number;
string n[10];
string result[10];
int arr[10];
int length[10]; // ���ڿ��� ���̰� ������ �ε��� ����
int len_index = 0;
int len_data[10][8];
int _data = 9;
int Solve() { // ���� ���ڿ��� ã�� ���ĺ��� �� �ο�
	while (1) { // ��� �ݺ��ϸ鼭
		checkLen(); // ���ڿ��� ���̰� 0�� �ɶ����� �ݺ�.
		if (len_index == 1) { // ���� �� ���ڿ��� �Ѱ���� ��
			result[length[len_index]].at(0) = _data + 48;
			_data--;
			continue;
		}
		for (int i = 0; i < len_index; i++) {
			int cnt = 0;
			 // �ϴ� ���ڿ��� ���̰� ���� ������ 
			 // �� �� ���ڶ� ������ ���ڰ� �ִ��� ã��.
			 // ���� ������ ���ڰ� ������ ���� �տ� �ִ� ���ڿ��� ���� ū �� �ο�.
			for (int j = 0; j < n[length[i]].length(); j++) {
				if (n[length[i]].at(0) == n[length[i]].at(j)) {
					len_data[length[i]][cnt] = j;
					cnt++;
				}
			}
		}
	}
}


void checkLen() { // ���� �� ���ڿ��� ���̰� ���� ���ڿ� ã��
	// arr[0] �� �ε����� ũ�Ⱑ ����ũ��.
	// �� arr[0] �� ���� ���ڿ��� ã���� ��.
	for (int i = 0; i < len_index; i++) length[i] = 0; // ������ �ʱ�ȭ
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