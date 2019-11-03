#include <iostream>
#include <math.h>
using namespace std;

int PointDistance(int x1, int y1, int x2, int y2);
int CircleRelation(int distance, int r1, int r2);

int main() {
	int cnt;
	cin >> cnt;
	int x1, y1, r1;
	int x2, y2, r2;
	int *array = new int[cnt];

	int distance;
	int array_index = 0;
	for (int i = 0; i < cnt; i++) {
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
		if (x1 >= -10000 && y1 >= -10000 && x2 >= -10000 && y2 >= -10000 && x1 <= 10000 && y1 <= 10000 && x2 <= 10000 && y2 <= 10000 && 0<r1 && r1<=10000 && 0<=r2 && r2<=10000)  {
			distance =  PointDistance(x1, y1, x2, y2);
			array[array_index] =CircleRelation(distance, r1, r2);
			array_index++;
		}
	}
	for (int i = 0; i < cnt; i++) {
		cout << array[i] << endl;
	}
	//system("pause");
	free(array);
}

int PointDistance(int x1,int y1,int x2,int y2) {
	return sqrt(((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2)));
}

int CircleRelation(int distance,int r1,int r2) {
	if (distance < r1 + r2 && abs(r1-r2) < distance) {	
			return 2;//
	}
	else if (r1 + r2 == distance) {//
		return 1;
	}
	else if (abs(r1 - r2) == distance) {//
		if (r1 == r2) {
			return -1;
		}
		return 1;
	}
	else if (r1 + r2 < distance) {//
		return 0;
	}
	else if (abs(r1 - r2) > distance) {//
		return 0;
	}
}

/*

if (r1 + r2 == distance) {
		return 1;
	}
	else if (r1 + r2 > distance) {
		if (distance == 0 && r1 == r2) {
			return -1;
		}
		if (r1 > r2) {
			if (r1 - r2 < distance) {
				return 2;
			}
			else if (r2 + distance == r1) {
				return 1;
			}
			else {
				return 0;
			}
		}
		else {
			if (r2 - r1 < distance) {
				return 2;
			}
			else if (r1 + distance == r2) {
				return 1;
			}
			else {
				return 0;
			}
		}
	}
	else if (r1 + r2 < distance) {
		return 0;
	}
*/