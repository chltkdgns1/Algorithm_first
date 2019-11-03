#include <iostream>
#include <math.h>
using namespace std;

int main() {
	int n, cnt = 0;
	int ten = 1; 
	int total = 0;
	int temp;
	cin >> n;
	temp = n;
	while (n > 0) {
		n = n / 10;
		cnt++;
	}
	for (int i = 1; i < cnt ; i++) total += (i) * (pow(10, i) - pow(10, i - 1));	
	cout << total << endl;
	total += (cnt) * (temp - (pow(10, cnt - 1) - 1)) ;
	cout << total << endl;
	system("pause");
}