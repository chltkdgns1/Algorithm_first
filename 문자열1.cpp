#include <iostream>
#include <string>
using namespace std;
int main() {
	string a, b;
	int cnt = 0, index = 0 , max = 0;
	cin >> a >> b;
	for (int i = 0; i <= b.length() - a.length() ; i++) {
		for (int j = i; j < a.length() + i; j++) {
			if (b[j] == a[index]) cnt++;
			index++;
		}
		if (max < cnt) max = cnt;
		index = 0;
		cnt = 0;
	}
	cout << a.length() - max << endl;
}


// a aaa