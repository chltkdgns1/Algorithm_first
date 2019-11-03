#include <iostream>
using namespace std;

int pow(int a, int b);
int rule[10][4] =
{
	1,1,1,1,
	2,4,8,6,
	3,9,7,1,
	4,6,4,6,
	5,5,5,5,
	6,6,6,6,
	7,9,3,1,
	8,4,2,6,
	9,1,9,1,
	0,0,0,0
};

int main() {
	int test_case;
	int a, b;
	int number;
	cin >> test_case;
	for (int i = 0; i < test_case; i++) {
		cin >> a >> b;
		cout << pow(a, b) << endl;
	}
	//system("pause");
}

int pow(int a,int b) {
	if (a % 10 == 0) {
		return 10;
	}
	if (b % 4 == 0) {
		return rule[a % 10 - 1][3];
	}
	return rule[a % 10 - 1 ][b % 4 - 1];
}

