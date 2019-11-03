#include <iostream>
using namespace std;

int array_number[1001];
bool array_bool[1001][1001] = { false };
//int BictoryHouse(int start_number, int n);
int BictoryHouse2(int start_number, int n);

int bictory_house;
int time = 0;

int main() {
	int test;
	int n, k;
	int x, y;
	cin >> test;
	for (int i = 0; i < test; i++) {
		cin >> n >> k;
		for (int j = 0; j < n; j++) {
			cin >> array_number[j + 1];
		}
		for (int j = 0; j < k; j++) {
			cin >> x >> y;
			array_bool[x][y] = true;
		}
		cin >> bictory_house;
		cout << BictoryHouse2(bictory_house, n) + array_number[1]<< endl;
		//system("pause");
	}
}

int BictoryHouse2(int start_number, int n) {
	int temp = 0;
	int temp2 = 0;
	int return_data = 0;
	int cnt = 0;
	if (start_number == 1) {
		//cout << "a" << endl;
		//cout << "array_number[1] : " << array_number[1] << endl;
		return array_number[1];
	}
	for (int i = start_number - 1 ; i >= 3; i--) {
		if (array_bool[i][start_number] == true) {
			temp2 = return_data;
			return_data = BictoryHouse2(i, n);
			
			if (return_data == -1) {
				temp = -1;
				continue;
			}

			if (temp2 < return_data) {
				temp = array_number[start_number] + return_data;
			}
			cnt++;
		}
	}
	if (cnt == 0) {
		temp = -1;
	}
	//cout << "temp : " << temp << endl;
	return temp;
}

int BictoryHouse(int start_number, int n) {
	int temp = 0;
	int return_data = 0;
	if (start_number > bictory_house) {
		return -1;
	}
	if (bictory_house == start_number) {
		return array_number[bictory_house];
	}
	for (int i = start_number; i <= n; i++) {
		if (array_bool[start_number][i] == true) {
			return_data = BictoryHouse(i, n);
			if (return_data == -1) {
				temp = -1;
			}
			if (temp < return_data) {
				temp = return_data + array_number[start_number];
			}
		}
	}
	return temp;
}



/*#include <iostream>
using namespace std;

int array_number[1001];
bool array_bool[1001][1001] = {false};
int BictoryHouse(int start_number,int n);
int bictory_house;
int time=0;

int main() {
	int test;
	int n, k;
	int x, y;
	cin >> test;
	for (int i = 0; i < test; i++) {
		cin >> n >> k;
		for (int j = 0; j < n; j++) {
			cin >> array_number[j + 1];
		}
		for (int j = 0; j < k; j++) {
			cin >> x >> y;
			array_bool[x][y] = true;
		}
		cin >> bictory_house;
		cout << BictoryHouse(1, n) << endl;
		//system("pause");
	}
}

int BictoryHouse(int start_number,int n ) {
	int temp = 0;
	int return_data=0;
	if (start_number > bictory_house) {
		return -1;
	}
	if (bictory_house == start_number) {
		return array_number[bictory_house];
	}
	for (int i = 1; i <= n; i++) {
		if (array_bool[start_number][i] == true) {	
			return_data = BictoryHouse(i,n);
			if (return_data == -1) {
				temp = -1;
			}
			if (temp < return_data) {
				temp = return_data+ array_number[start_number];
			 }
		}
	}
	return temp;
}
*/

