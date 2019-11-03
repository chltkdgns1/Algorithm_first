#include <iostream>
#include <string>
using namespace std;
char arr[100];
char brr[100];
char r;
int main() {
	cin >> arr >> r >> brr;
	int a_len = strlen(arr), b_len = strlen(brr);
	if (r == '+') {
		if (a_len == b_len) {
			arr[0]++;
			cout << arr << endl;
		}
		else if (a_len > b_len) {
			arr[a_len - b_len] = '1';
			cout << arr << endl;
		}
		else {
			brr[b_len - a_len] = '1';
			cout << brr << endl;
		}
	}
	else if(r == '*'){
		for (int i = a_len; i < a_len + b_len - 1; i++) arr[i] = '0';
		cout << arr << endl;
	}
	system("pause");
}