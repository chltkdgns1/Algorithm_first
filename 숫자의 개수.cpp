#include <iostream>
using namespace std;

int main() {
	int cnt[10] = { 0 };
	int a, b, c;
	int temp;
	cin >> a >> b >> c;
	temp = a * b * c;
	while (temp / 10 != 0) {
		cnt[temp % 10 ]++;
		temp = temp / 10;
	}
	cnt[temp]++;
	for (int i = 0; i < 10; i++) cout << cnt[i] << endl;
	system("pause");
}