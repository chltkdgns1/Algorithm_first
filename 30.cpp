#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
char arr[1000000];
char key[1000000];
int main() {
	cin >> arr;
	int sum = 0, cnt = 0 , len = strlen(arr);
	for (int i = 0; i < len; i++) {
		int n = arr[i] - 48;
		sum += n;
		if (arr[i] == '0') cnt++;
	}
	if (cnt == 0 || sum % 3 != 0) cout << "-1" << endl;
	else if(cnt >=1 && sum % 3 == 0){
 		sort(arr, arr + len); 
		for (int i = 0; i < len; i++) key[i] = arr[len - i - 1];
		cout << key << endl;
	}
}
