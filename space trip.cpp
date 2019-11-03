#include <iostream>
using namespace std;
int SpaceTrip(int x, int y, int first_data);
//int data_[3] = { -1,0.1 };
// 0 1 2


int xpos, ypos;
int main() {
	int test_case;
	cin >> test_case;
	for (int i = 0; i < test_case; i++) {
		cin >> xpos >> ypos;
		cout<<SpaceTrip(xpos, ypos, 2) <<endl;
	}
	system("pause");
}

int SpaceTrip(int x,int y,int first_data) {
	int temp = 0;
	int number = 0;
	if (x == y - 1) {
		return 1;
	}
	else if (x > y - 1) {
		return -1;
	}
	for (int i = 0; i < 3; i++) {
		first_data--;
		if (first_data == -1 || first_data == 0) {
			continue;
		}
		x = x + first_data;
		number = 1 + SpaceTrip(x, y, first_data + i + 2);
		if (temp == 0 && number != 0) {
			temp = number;
		}
		else if (temp >= number && number != 0) {
			temp = number;
			//cout << "temp : " << temp << endl;
		}
		x = x - first_data;
	}
	if (temp == 0) {
		return -1;
	}
	return temp;
}
