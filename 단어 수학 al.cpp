#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int arr_index[26][11]; // 알파벳의 위치하고 있는 인덱스 
int store_index[26];
string word[10];
int number_data = 9;
void searchHighNumber(int index,int key) {
	int n = 11;
	while (1) {
		for (int i = 0; i < 26; i++) {
			if (arr_index[i][index] < n && arr_index[i][10] == key && arr_index[i][index] > 0) {
				n = arr_index[i][index];
			}
		}
		int cnt = 0;
		for (int i = 0; i < 26; i++) {
			if (arr_index[i][index] == n && arr_index[i][10] == key && arr_index[i][index] > 0) {
				cnt++;
				arr_index[i][10] = key + 1;
			}
		}
		if (cnt == 1) {
			for (int i = 0; i < 26; i++) {
				if (arr_index[i][10] == key + 1) {	
					arr_index[i][0] = -1;
					arr_index[i][1] = number_data;
					arr_index[i][10] = -1;
					number_data--;
					break;
				}
			}
			if (number_data == -1) break;
		}
		else if(cnt > 1){
			searchHighNumber(index + 1, key + 1);
		}
		else {

		}
	}
}
void checkAlpa(int number) {
	int data = 65; // 대문자 A의 값
	for (int ts = 0; ts < 26; ts++) {
		int index_cur = 0;
		for (int i = 0; i < number; i++) {
			for (int j = 0; j < word[i].length(); j++) {
				if (word[i].at(j) == data) {
					arr_index[ts][index_cur] = j + 1 + 10 - word[i].length();
					index_cur++;
				}
			}
		}
		data++;
		sort(arr_index[ts], arr_index[ts] + index_cur);
	}
}
int main() {
	int number;
	cin >> number;
	for (int i = 0; i < number; i++) cin >> word[i];
	checkAlpa(number);
	searchHighNumber(0, 0);
	system("pause");
}

