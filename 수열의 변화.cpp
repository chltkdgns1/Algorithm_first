#include <iostream>
#include <string>
using namespace std;

string arr;
int result[50];
int index;
int main() {
	int n, k ,on;
	cin >> n >> k;
	cin >> arr;
	string temp;
	for (int i = 0; i < arr.length(); i++) {
		if (arr[i] != ',') temp += arr[i];
		else if (arr[i] == ',') {
			result[index++] = stoi(temp);
			temp.clear();
		}
	}
	result[index++] = stoi(temp);
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < index; j++) {
			result[j] = result[j + 1] - result[j];
		}
		result[index] = 0;
		index--;
	}
	for (int i = 0; i < index; i++) {
		if (i == index - 1) cout << result[i];
		else cout << result[i] << ",";
	}
}