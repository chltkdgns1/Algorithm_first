#include<iostream>
#include<string>

using namespace std;
int main()
{
	string arr;
	int count = 0;
	cin >> arr;
	int br = 0;
	for (int i = 0; i < arr.length(); i++) {
		if (arr[i] != arr[arr.length() - 1 - i]) {
			cout << 0;
			br = 1;
			break;
		}
	}
	if (br == 0) cout << 1 << endl;
}