#include <iostream>
#include <Windows.h>
using namespace std;


void PrintMap(int n, int h);
bool InputMapData(int a, int b);
bool Play(int n, int h);
void CheckM(int n, int h);
bool Simulater(int n, int h);
void DelMapData(int a, int b);
void TempArray(int n, int h, bool on_off);

int map[30][10] = {};
int temp_map[30][10] = {};
int collect_count = 0;
int create_count = 0;
int number_three_count = 0;


class Xypos {
public:
	int xpos;
	int ypos;
	Xypos() {
		xpos = 0;
		ypos = 0;
	}
};

int xypos_index = 0;
Xypos *xypos;

int main() {
	int n; // 행
	int m; // 가로선 개수
	int h; // 열
	int a; // 열 번호
	int b; // 행과 다음 행
	cin >> n >> m >> h;

	xypos = new Xypos[(n - 1)*h];

	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		if (InputMapData(a, b) == false) {
			cout << "-1" << endl;
			return 0;
		}
	}
	CheckM(n, h);
	PrintMap(n, h);
	if (Play(n, h)) {
		cout << create_count << endl;
		cout << "a" << endl;
	}
	else {
		PrintMap(n, h);
		cout << create_count << endl;
		cout << "-1" << endl;
	}
	//cout << " simualter : " << Simulater(n, h) << endl;
	//Sleep(1000);
	system("pause");
	//TempMap(false);

	
};

void TempArray(int n,int h,bool on_off) {
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			if (on_off == true) {
				map[i][j] = temp_map[i][j];
			}
			else {
				temp_map[i][j] = map[i][j];
			}
		}
	}
}

bool Play(int n, int h) {
	if (Simulater(n, h) == true) {
		return true;
	}

	for (int i = 0; i < xypos_index; i++) {
		if (InputMapData(xypos[i].ypos + 1, xypos[i].xpos + 1) == true) {
			create_count++;
			if (Simulater(n, h) == false) {
				DelMapData(xypos[i].ypos + 1, xypos[i].xpos + 1);
				create_count--;
			}
			else {
				return true;
			}
		}
	}
	
	cout << "create_count : " << create_count << endl;
	cout << endl;

	for (int i = 0; i < xypos_index; i++) {
		if (InputMapData(xypos[i].ypos + 1, xypos[i].xpos + 1) == true) {
			create_count++;
			for (int j = i + 1; j < xypos_index; j++) {
				if (InputMapData(xypos[j].ypos + 1, xypos[j].xpos + 1) == true) {
					create_count++;
					if (Simulater(n, h) == false) {
						DelMapData(xypos[j].ypos + 1, xypos[j].xpos + 1);
						create_count--;
					}
					else {
						PrintMap(n, h);
						return true;
					}
				}
			}
			DelMapData(xypos[i].ypos + 1, xypos[i].xpos + 1);
			create_count--;
		}
	}


	cout << "create_count : " << create_count << endl;
	cout << endl;

	for (int i = 0; i < xypos_index; i++) {
		if (InputMapData(xypos[i].ypos + 1, xypos[i].xpos + 1) == true) {
			create_count++;
			for (int j = i + 1; j < xypos_index; j++) {
				if (InputMapData(xypos[j].ypos + 1, xypos[j].xpos + 1) == true) {
					create_count++;
					for (int k = j + 1; k < xypos_index; k++) {
						if (InputMapData(xypos[k].ypos + 1, xypos[k].xpos + 1) == true) {
							create_count++;
							if (Simulater(n, h) == false) {
								DelMapData(xypos[k].ypos + 1, xypos[k].xpos + 1);
								create_count--;
							}
							else {
								PrintMap(n, h);
								return true;
							}
						}
					}
					DelMapData(xypos[j].ypos + 1, xypos[j].xpos + 1);
					create_count--;
				}
			}
			DelMapData(xypos[i].ypos + 1, xypos[i].xpos + 1);
			create_count--;
		}
	}


	cout << "create_count : " << create_count << endl;
	cout << endl;
	
	return false;
}

bool Simulater(int n,int h) {
	int n_index;
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		n_index = i;
		for (int j = 0; j < h; j++) {
			if (map[j][n_index] == 1) {
				n_index++;
			}
			else if (map[j][n_index] == 2) {
				n_index--;
			}
		}
		if (n_index == i) {
			cnt++;
		}
	}
	if (cnt == n) {
		return true;
	}
	return false;
}

void CheckM(int n,int h) { // 가로선이 들어갈 수 있는 좌표 찾기
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == 0 && map[i][j+1]==0 && j+1!=n) {
				xypos[xypos_index].xpos = j;
				xypos[xypos_index].ypos = i;
				xypos_index++;
			}
		}
	}
}

void PrintMap(int n,int h) {
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			cout << map[i][j] << " ";
		}
		cout << endl;
	}
}
bool InputMapData(int a, int b) {
	if (map[a - 1][b - 1] != 0 ) {
		return false;
	}
	map[a - 1][b - 1] = 1;
	map[a - 1][b] = 2;
	return true;
}

void DelMapData(int a, int b) {
	map[a - 1][b - 1] = 0;
	map[a - 1][b] = 0;
}

/*
bool Play(int n, int h) {
	if (Simulater(n, h) == n) {
		return true;
	}
	int order_count = 0;
	for (int k = 0; k < xypos_index; k++) {
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < n; j++) {
				if (map[i][j] == 3) {
					InputMapData(i + 1, j + 1);
					//PrintMap(n, h);
					//cout << endl;
					create_count++;
					//cout << "temp : " << temp << endl;
					if (Simulater(n, h) == false) {
						TempArray(n, h, true);
						create_count--;
						//PrintMap(n, h);
						//cout << endl;
					}
					else {
						TempArray(n, h, false);
					}
					cout << "collect : " << collect_count << endl;
					if (collect_count == n) {
						return true;
					}

				}
			}
		}
	}
	return false;
}

*/