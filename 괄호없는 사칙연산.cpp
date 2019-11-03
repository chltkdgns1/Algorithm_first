#include <iostream>
#include <string.h>
using namespace std;
char arr[1000];
int datas[3];
int temp_data[3];
char rule[2];
char temp_arr[4];
int col[2];
int main() {
	cin.getline(arr,sizeof(arr));
	int index = 0;
	int in_index = 0;
	int ru_index = 0;
	for (int i = 0; i < strlen(arr); i++) {
		if (arr[i] >= 48 && arr[i] <= 57) {
			temp_arr[index] = arr[i];
			index++;
			if (arr[i + 1] == ' ' || arr[i+1] == NULL) {
				datas[in_index] = atoi(temp_arr);
				in_index ++ ;
				for (int j = 0; j < 4; j++) temp_arr[j] = NULL;
				index = 0;
			}
		}
		else if (arr[i] == '*' || arr[i] == '+' || arr[i] == '-' || arr[i] == '/') {
			rule[ru_index] = arr[i];
			ru_index++;
		}
	}
	for (int i = 0; i < 3; i++) temp_data[i] = datas[i];
	for (int i = 1; i >= 0; i--) {
		switch (rule[i]) {
		case '+':
			col[0] = datas[i] + datas[i + 1];
			break;
		case '-':
			col[0] = datas[i] - datas[i + 1];
			break;
		case '*':
			col[0] = datas[i] * datas[i + 1];
			break;
		case '/':
			col[0] = datas[i] / datas[i + 1];
			break;
		}
		datas[i] = col[0];
	}
	for (int i = 0; i < 3; i++) datas[i] = temp_data[i];
	for (int i = 0; i < 2; i++) {
		switch (rule[i]) {
		case '+':
			col[1] = datas[i] + datas[i + 1];
			break;
		case '-':
			col[1] = datas[i] - datas[i + 1];
			break;
		case '*':
			col[1] = datas[i] * datas[i + 1];
			break;
		case '/':
			col[1] = datas[i] / datas[i + 1];
			break;
		}
		datas[i + 1] = col[1];
	}
	if (col[0] < col[1]) {
		cout << col[0] << endl;
		cout << col[1] << endl;
	}
	else {
		cout << col[1] << endl;
		cout << col[0] << endl;
	}
}