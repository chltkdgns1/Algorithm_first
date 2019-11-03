#include <iostream>
#include <string>
using namespace std;

int sr[26];
int main() {
	string arr;
	cin >> arr;
	for (int i = 0; i < arr.length(); i++) {
		sr[arr[i] - 97]++;
	}
	for (int i = 0; i < 26; i++) {
		cout << sr[i] << " ";
	}
}